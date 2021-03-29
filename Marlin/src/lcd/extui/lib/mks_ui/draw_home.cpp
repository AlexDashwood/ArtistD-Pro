#include "../../../../MarlinCore.h"
#if ENABLED(TFT_LITTLE_VGL_UI)
#include "draw_ui.h"
#include "../../../../gcode/queue.h"


#define ID_H_ALL			1
#define ID_H_X				2
#define ID_H_Y				3
#define ID_H_Z				4
#define ID_H_RETURN			5
#define ID_H_OFF_ALL		6
#define ID_H_OFF_XY			7

static lv_obj_t *scr;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
	switch(obj->mks_obj_id)
	{
		case ID_H_ALL:
			if(event == LV_EVENT_CLICKED) {
				
			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("G28"));
			}
			break;
		case ID_H_X:
			if(event == LV_EVENT_CLICKED) {
				
			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("G28 X0"));
			}
			break;
		case ID_H_Y:
			if(event == LV_EVENT_CLICKED) {
				
			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("G28 Y0"));
			}
			break;
		case ID_H_Z:
			if(event == LV_EVENT_CLICKED) {
				
			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("G28 Z0"));
			}
			break;
		case ID_H_OFF_ALL:
			if(event == LV_EVENT_CLICKED) {

			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("M84"));
			}
			break;
		case ID_H_OFF_XY:
			if(event == LV_EVENT_CLICKED) {

			}
			else if(event == LV_EVENT_RELEASED) {
				queue.inject_P(PSTR("M84 X Y"));
			}
			break;
		case ID_H_RETURN:
			if(event == LV_EVENT_CLICKED) {
				
			}
			else if(event == LV_EVENT_RELEASED) {
				lv_clear_home();
				lv_draw_ready_print(1);
			}
			break;
	}
}

void lv_draw_home(void)
{
	if(disp_state_stack._disp_state[disp_state_stack._disp_index] != ZERO_UI)
	{
		disp_state_stack._disp_index++;
		disp_state_stack._disp_state[disp_state_stack._disp_index] = ZERO_UI;
	}
	disp_state = ZERO_UI;

	scr = lv_obj_create(NULL, NULL);

	//static lv_style_t tool_style;
	
	lv_obj_set_style(scr, &tft_style_scr);
  	lv_scr_load(scr);
 	lv_obj_clean(scr);

  	lv_obj_t *title = lv_label_create(scr, NULL);
	lv_obj_set_style(title, &tft_style_label_rel);
	lv_obj_set_pos(title, TITLE_XPOS, TITLE_YPOS);
	lv_label_set_text(title, creat_title_text());
  
  	lv_refr_now(lv_refr_get_disp_refreshing());
	
	LV_IMG_DECLARE(bmp_pic);
	
    /*Create an Image button*/
	lv_obj_t *buttonHomeAll = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonHomeX = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonHomeY = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonHomeZ = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonBack = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonOffAll = lv_imgbtn_create(scr, NULL);
	lv_obj_t *buttonOffXY = lv_imgbtn_create(scr, NULL);
	
	lv_obj_set_event_cb_mks(buttonHomeAll, event_handler, ID_H_ALL, "bmp_Zero.bin", 0);
	lv_imgbtn_set_src(buttonHomeAll, LV_BTN_STATE_REL, &bmp_pic);
	lv_imgbtn_set_src(buttonHomeAll, LV_BTN_STATE_PR, &bmp_pic);
	lv_imgbtn_set_style(buttonHomeAll, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonHomeAll, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonHomeX, event_handler, ID_H_X, "bmp_zeroX.bin", 0);	
    lv_imgbtn_set_src(buttonHomeX, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeX, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeX, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonHomeX, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonHomeY, event_handler, ID_H_Y, "bmp_zeroY.bin", 0);	
    lv_imgbtn_set_src(buttonHomeY, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeY, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeY, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonHomeY, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonHomeZ, event_handler, ID_H_Z, "bmp_zeroZ.bin", 0);	
    lv_imgbtn_set_src(buttonHomeZ, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeZ, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeZ, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonHomeZ, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonOffAll, event_handler, ID_H_OFF_ALL, "bmp_Motor_off.bin", 0);	
    lv_imgbtn_set_src(buttonOffAll, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonOffAll, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonOffAll, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonOffAll, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonOffXY, event_handler, ID_H_OFF_XY, "bmp_MotorXY_off.bin", 0);	
    lv_imgbtn_set_src(buttonOffXY, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonOffXY, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonOffXY, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonOffXY, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_event_cb_mks(buttonBack, event_handler, ID_H_RETURN, "bmp_Return.bin", 0);	
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_PR, &tft_style_label_pre);
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_REL, &tft_style_label_rel);

	lv_obj_set_pos(buttonHomeAll, INTERVAL_V, titleHeight);
	lv_obj_set_pos(buttonHomeX, BTN_X_PIXEL+INTERVAL_V*2, titleHeight);
	lv_obj_set_pos(buttonHomeY, BTN_X_PIXEL*2+INTERVAL_V*3, titleHeight);
	lv_obj_set_pos(buttonHomeZ, BTN_X_PIXEL*3+INTERVAL_V*4, titleHeight);
	lv_obj_set_pos(buttonOffAll, INTERVAL_V, BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonOffXY, BTN_X_PIXEL+INTERVAL_V*2, BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonBack, BTN_X_PIXEL*3+INTERVAL_V*4, BTN_Y_PIXEL+INTERVAL_H+titleHeight);

    /*Create a label on the Image button*/
	lv_btn_set_layout(buttonHomeAll, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeX, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeY, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeZ, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonOffAll, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonOffXY, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonBack, LV_LAYOUT_OFF);
	
	lv_obj_t * labelHomeAll = lv_label_create(buttonHomeAll, NULL);
	lv_obj_t * labelHomeX= lv_label_create(buttonHomeX, NULL);
	lv_obj_t * labelHomeY = lv_label_create(buttonHomeY, NULL);
	lv_obj_t * labelHomeZ = lv_label_create(buttonHomeZ, NULL);
	lv_obj_t * labelOffAll = lv_label_create(buttonOffAll, NULL);
	lv_obj_t * labelOffXY = lv_label_create(buttonOffXY, NULL);
	lv_obj_t * label_Back = lv_label_create(buttonBack, NULL);
	
	if(gCfgItems.multiple_language !=0)
	{
		lv_label_set_text(labelHomeAll, home_menu.home_all);
		lv_obj_align(labelHomeAll, buttonHomeAll, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeX,home_menu.home_x);
		lv_obj_align(labelHomeX, buttonHomeX, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeY, home_menu.home_y);	
		lv_obj_align(labelHomeY, buttonHomeY, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeZ, home_menu.home_z);	
		lv_obj_align(labelHomeZ, buttonHomeZ, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelOffAll, set_menu.motoroff);
		lv_obj_align(labelOffAll, buttonOffAll, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelOffXY, set_menu.motoroffXY);
		lv_obj_align(labelOffXY, buttonOffXY, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);
		
		lv_label_set_text(label_Back, common_menu.text_back);
		lv_obj_align(label_Back, buttonBack, LV_ALIGN_IN_BOTTOM_MID, 0, BUTTON_TEXT_Y_OFFSET);
	}
}

void lv_clear_home(void)
{
	lv_obj_del(scr);
}

#endif
