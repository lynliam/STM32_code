//
// Created by liam on 2023/12/9.
//
#include "EnterCritical.h"

static uint32_t uxCriticalNesting = 0xaaaaaaaa;

#define portDISABLE_INTERRUPTS()				vPortRaiseBASEPRI()
//不带返回值的关中断函数不能嵌套，不能在中断中实现
portFORCE_INLINE static void vPortRaiseBASEPRI( void )
{
    uint32_t ulNewBASEPRI;

    __asm volatile
            (
            "	mov %0, %1												\n"	\
		"	msr basepri, %0											\n" \
		"	isb														\n" \
		"	dsb														\n" \
		:"=r" (ulNewBASEPRI) : "i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY )
            );
}

#define portSET_INTERRUPT_MASK_FROM_ISR()		ulPortRaiseBASEPRI()
//带返回值的关中断函数能嵌套，能在中断中实现
portFORCE_INLINE static uint32_t ulPortRaiseBASEPRI( void )
{
    uint32_t ulOriginalBASEPRI, ulNewBASEPRI;

    __asm volatile
            (
            "	mrs %0, basepri											\n" \
		"	mov %1, %2												\n"	\
		"	msr basepri, %1											\n" \
		"	isb														\n" \
		"	dsb														\n" \
		:"=r" (ulOriginalBASEPRI), "=r" (ulNewBASEPRI) : "i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY )
            );

    /* This return will not be reached but is necessary to prevent compiler
    warnings. */
    return ulOriginalBASEPRI;
}


#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x)	vPortSetBASEPRI(x)
#define portENABLE_INTERRUPTS()					vPortSetBASEPRI(0)

portFORCE_INLINE static void vPortSetBASEPRI( uint32_t ulNewMaskValue )
{
    __asm volatile
            (
            "	msr basepri, %0	" :: "r" ( ulNewMaskValue )
            );
}

#define configASSERT( x ) if ((x) == 0) {taskDISABLE_INTERRUPTS(); for( ;; );}
#define taskDISABLE_INTERRUPTS()           portDISABLE_INTERRUPTS()
#define portNVIC_INT_CTRL_REG		( * ( ( volatile uint32_t * ) 0xe000ed04 ) )
/* Masks off all bits but the VECTACTIVE bits in the ICSR register. */
#define portVECTACTIVE_MASK					( 0xFFUL )


void vPortEnterCritical( void )
{
    portDISABLE_INTERRUPTS();
    uxCriticalNesting++;

    /* This is not the interrupt safe version of the enter critical function so
    assert() if it is being called from an interrupt context.  Only API
    functions that end in "FromISR" can be used in an interrupt.  Only assert if
    the critical nesting count is 1 to protect against recursive calls if the
    assert function also uses a critical section. */
    if( uxCriticalNesting == 1 )
    {
        configASSERT( ( portNVIC_INT_CTRL_REG & portVECTACTIVE_MASK ) == 0 );
    }
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
    configASSERT( uxCriticalNesting );
    uxCriticalNesting--;
    if( uxCriticalNesting == 0 )
    {
        portENABLE_INTERRUPTS();
    }
}