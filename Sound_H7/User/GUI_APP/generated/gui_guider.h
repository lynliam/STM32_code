/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_11;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_label_time_8;
	lv_obj_t *screen_label_time_7;
	lv_obj_t *screen_label_time_6;
	lv_obj_t *screen_label_time_5;
	lv_obj_t *screen_label_time_4;
	lv_obj_t *screen_label_time_3;
	lv_obj_t *screen_label_time_2;
	lv_obj_t *screen_label_time_1;
	lv_obj_t *screen_label_author_8;
	lv_obj_t *screen_label_author_7;
	lv_obj_t *screen_label_author_6;
	lv_obj_t *screen_label_author_5;
	lv_obj_t *screen_label_author_4;
	lv_obj_t *screen_label_author_3;
	lv_obj_t *screen_label_author_2;
	lv_obj_t *screen_label_music_8;
	lv_obj_t *screen_label_music_7;
	lv_obj_t *screen_label_music_6;
	lv_obj_t *screen_label_music_5;
	lv_obj_t *screen_label_music_4;
	lv_obj_t *screen_label_music_3;
	lv_obj_t *screen_label_music_2;
	lv_obj_t *screen_img_8;
	lv_obj_t *screen_img_7;
	lv_obj_t *screen_img_6;
	lv_obj_t *screen_img_5;
	lv_obj_t *screen_img_4;
	lv_obj_t *screen_img_3;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_label_author_1;
	lv_obj_t *screen_label_music_1;
	lv_obj_t *screen_btn_8;
	lv_obj_t *screen_btn_8_label;
	lv_obj_t *screen_btn_7;
	lv_obj_t *screen_btn_7_label;
	lv_obj_t *screen_btn_6;
	lv_obj_t *screen_btn_6_label;
	lv_obj_t *screen_btn_5;
	lv_obj_t *screen_btn_5_label;
	lv_obj_t *screen_btn_4;
	lv_obj_t *screen_btn_4_label;
	lv_obj_t *screen_btn_3;
	lv_obj_t *screen_btn_3_label;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_player;
	lv_obj_t *screen_img_album;
	lv_obj_t *screen_imgbtn_play;
	lv_obj_t *screen_imgbtn_play_label;
	lv_obj_t *screen_img_9;
	lv_obj_t *screen_img_10;
	lv_obj_t *screen_img_wave_bottom;
	lv_obj_t *screen_img_wave_top;
	lv_obj_t *screen_img_icn_rnd;
	lv_obj_t *screen_img_icn_loop;
	lv_obj_t *screen_img_icn_left;
	lv_obj_t *screen_img_icn_right;
	lv_obj_t *screen_slider_1;
	lv_obj_t *screen_img_icn_msg;
	lv_obj_t *screen_img_icn_heart;
	lv_obj_t *screen_img_icn_donwload;
	lv_obj_t *screen_img_icn_chart;
	lv_obj_t *screen_label_slider_time;
	lv_obj_t *screen_label_tracks;
	lv_obj_t *screen_btn_tracks;
	lv_obj_t *screen_btn_tracks_label;
	lv_obj_t *screen_label_title_music;
	lv_obj_t *screen_label_title_author;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_icn_slider_alpha_25x25);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_play_alpha_70x70);
LV_IMG_DECLARE(_btn_list_pause_alpha_70x70);
LV_IMG_DECLARE(_cover_1_alpha_175x175);
LV_IMG_DECLARE(_btn_play_alpha_80x80);
LV_IMG_DECLARE(_btn_play_alpha_80x80);
LV_IMG_DECLARE(_btn_pause_alpha_80x80);
LV_IMG_DECLARE(_btn_pause_alpha_80x80);
LV_IMG_DECLARE(_cover_2_alpha_175x175);
LV_IMG_DECLARE(_cover_3_alpha_175x175);
LV_IMG_DECLARE(_wave_bottom_alpha_800x51);
LV_IMG_DECLARE(_wave_top_alpha_800x51);
LV_IMG_DECLARE(_btn_rnd_alpha_25x25);
LV_IMG_DECLARE(_btn_loop_alpha_25x25);
LV_IMG_DECLARE(_btn_prev_alpha_61x61);
LV_IMG_DECLARE(_btn_next_alpha_61x61);
LV_IMG_DECLARE(_icn_chat_alpha_25x25);
LV_IMG_DECLARE(_icn_heart_alpha_25x25);
LV_IMG_DECLARE(_icn_download_alpha_25x25);
LV_IMG_DECLARE(_icn_chart_alpha_25x25);

LV_FONT_DECLARE(lv_font_arial_20)
LV_FONT_DECLARE(lv_font_arial_16)
LV_FONT_DECLARE(lv_font_arial_23)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_20)
LV_FONT_DECLARE(lv_font_arial_26)


#ifdef __cplusplus
}
#endif
#endif
