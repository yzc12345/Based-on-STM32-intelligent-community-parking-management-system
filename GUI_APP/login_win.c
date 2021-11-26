#include "login_win.h"
#include "start_task.h"
#include "tabview.h"
#include "rtc_time.h"
#include "sw.h"
#include "bar.h"
#include "calendar.h"
#include "image.h"
#include "ddlist.h"

LV_FONT_DECLARE(my_font_icon1_60);
LV_FONT_DECLARE(my_font_16);
LV_FONT_DECLARE(my_font_32);

#define MY_ICON_camera			"\xEE\x98\xAE" //����ͷͼ��  		0xee98ae
#define MY_ICON_park				"\xEE\x98\xB0" //ͣ����ͼ��	 		0xee98b0
#define MY_ICON_time				"\xEE\xA3\x85" //ʱ��ͼ��		 		0xeea385
#define MY_ICON_user				"\xEE\xA2\xA1" //�û�����ͼ��		0xeea2a1
#define MY_ICON_date				"\xEE\xA2\xB4" //����ͼ��		 		0xeea2b4
#define MY_ICON_weather			"\xEE\xA1\xBF" //����ͼ��		 		0xeea1bf

lv_obj_t *login_win=NULL;
lv_obj_t *time_label;
lv_obj_t *park_label;
lv_obj_t *camera_label;
lv_obj_t *user_label;
lv_obj_t *date_label;
lv_obj_t *weather_label;
lv_obj_t *time_label1;

lv_task_t *time_task=NULL;

void time_show(lv_obj_t *parent);


static void login_win_event_handler(lv_obj_t * obj,lv_event_t event)
{
	if(event==LV_EVENT_PRESSED)
	{
		if(obj==time_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_time"#");
			lv_label_set_recolor(obj,true);
		}
		else if(obj==park_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_park"#");//ʹŜτѾҕɫҤܒ,ԐдЂքЧڻ
			lv_label_set_recolor(obj,true);//ʹŜטܦɫ
		}
		else if(obj==camera_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_camera"#");//ʹŜτѾҕɫҤܒ,ԐдЂքЧڻ
			lv_label_set_recolor(obj,true);//ʹŜטܦɫ
		}
		else if(obj==user_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_user"#");//ʹŜτѾҕɫҤܒ,ԐдЂքЧڻ
			lv_label_set_recolor(obj,true);//ʹŜטܦɫ
		}
		else if(obj==date_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_date"#");//ʹŜτѾҕɫҤܒ,ԐдЂքЧڻ
			lv_label_set_recolor(obj,true);//ʹŜטܦɫ
		}
		else if(obj==weather_label)
		{
			lv_label_set_text(obj,"#444444 "MY_ICON_weather"#");//ʹŜτѾҕɫҤܒ,ԐдЂքЧڻ
			lv_label_set_recolor(obj,true);//ʹŜטܦɫ
		}
		
	}else if(event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST) //松手事件和移位事件
	{		
		lv_obj_del(login_win); //删除当前窗体
		login_win=NULL;
		if(task_bar!=NULL)
		{
			lv_task_del(task_bar);
			task_bar=NULL;
		}
		if(time_task!=NULL)
		{
			lv_task_del(time_task);
			time_task=NULL;
		}
		//lv_task_del(task1);
		if(obj==park_label)
		{
			tabview_create(lv_scr_act());
		}
		if(obj==time_label)
		{
			RTC_Time_create(lv_scr_act());
		}
		if(obj==date_label)
		{
			calendar_create(lv_scr_act());
		}
		
	}
}


void login_win_create(lv_obj_t *parent)
{
	uint16_t parent_width,parent_height;
	
	static lv_style_t icon_style;
	lv_style_copy(&icon_style,&lv_style_plain);
	icon_style.text.font = &my_font_icon1_60;
	icon_style.text.color=LV_COLOR_WHITE;
	icon_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	icon_style.body.grad_color=icon_style.body.main_color;
	
	static lv_style_t font_style;
	lv_style_copy(&font_style,&lv_style_plain);
	font_style.text.font = &my_font_16;
	font_style.text.color=LV_COLOR_WHITE;
	font_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	font_style.body.grad_color=font_style.body.main_color;	
	
	static lv_style_t font32_style;
	lv_style_copy(&font32_style,&font_style);
	font32_style.text.font=&my_font_32;
	
	parent_width = lv_obj_get_width(parent);
	parent_height = lv_obj_get_height(parent);

	login_win = lv_cont_create(parent,NULL);
	lv_obj_set_size(login_win,parent_width,parent_height);
	lv_cont_set_layout(login_win,LV_LAYOUT_OFF);

	time_label = lv_label_create(login_win,NULL);
	lv_label_set_text(time_label,MY_ICON_time);
	lv_obj_align(time_label,NULL,LV_ALIGN_IN_TOP_LEFT,10,30);
	lv_obj_set_click(time_label,true);
	lv_label_set_style(time_label,LV_LABEL_STYLE_MAIN,&icon_style);
	lv_obj_set_event_cb(time_label,login_win_event_handler);

	park_label = lv_label_create(login_win,NULL);
	lv_label_set_text(park_label,MY_ICON_park);
	lv_obj_align(park_label,NULL,LV_ALIGN_IN_TOP_LEFT,90,30);
	lv_obj_set_click(park_label,true);
	lv_label_set_style(park_label,LV_LABEL_STYLE_MAIN,&icon_style);
	lv_obj_set_event_cb(park_label,login_win_event_handler);

//	camera_label = lv_label_create(login_win,NULL);
//	lv_label_set_text(camera_label,MY_ICON_camera);
//	lv_obj_align(camera_label,NULL,LV_ALIGN_IN_TOP_LEFT,170,30);
//	lv_obj_set_click(camera_label,true);
//	lv_label_set_style(camera_label,LV_LABEL_STYLE_MAIN,&icon_style);
//	lv_obj_set_event_cb(camera_label,login_win_event_handler);
	
//	date_label = lv_label_create(login_win,NULL);
//	lv_label_set_text(date_label,MY_ICON_date);
//	lv_obj_align(date_label,NULL,LV_ALIGN_IN_TOP_LEFT,10,150);
//	lv_obj_set_click(date_label,true);
//	lv_label_set_style(date_label,LV_LABEL_STYLE_MAIN,&icon_style);
//	lv_obj_set_event_cb(date_label,login_win_event_handler);
	
//	user_label = lv_label_create(login_win,NULL);
//	lv_label_set_text(user_label,MY_ICON_user);
//	lv_obj_align(user_label,NULL,LV_ALIGN_IN_TOP_LEFT,90,150);
//	lv_obj_set_click(user_label,true);
//	lv_label_set_style(user_label,LV_LABEL_STYLE_MAIN,&icon_style);
//	lv_obj_set_event_cb(user_label,login_win_event_handler);

//	weather_label = lv_label_create(login_win,NULL);
//	lv_label_set_text(weather_label,MY_ICON_weather);
//	lv_obj_align(weather_label,NULL,LV_ALIGN_IN_TOP_LEFT,170,150);
//	lv_obj_set_click(weather_label,true);
//	lv_label_set_style(weather_label,LV_LABEL_STYLE_MAIN,&icon_style);
//	lv_obj_set_event_cb(weather_label,login_win_event_handler);
//	
//	
//	lv_obj_t *font_label1 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label1,time_label,LV_ALIGN_OUT_BOTTOM_MID,0,10);
//	lv_label_set_text(font_label1,"时间");
//	lv_label_set_style(font_label1,LV_LABEL_STYLE_MAIN,&font_style);

//	lv_obj_t *font_label2 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label2,park_label,LV_ALIGN_OUT_BOTTOM_MID,-20,10);
//	lv_label_set_text(font_label2,"停车场信息 ");
//	lv_label_set_style(font_label2,LV_LABEL_STYLE_MAIN,&font_style);
//	
//	lv_obj_t *font_label3 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label3,camera_label,LV_ALIGN_OUT_BOTTOM_MID,0,10);
//	lv_label_set_text(font_label3,"相机 ");
//	lv_label_set_style(font_label3,LV_LABEL_STYLE_MAIN,&font_style);
//	
//	lv_obj_t *font_label4 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label4,date_label,LV_ALIGN_OUT_BOTTOM_MID,0,10);
//	lv_label_set_text(font_label4,"日历 ");
//	lv_label_set_style(font_label4,LV_LABEL_STYLE_MAIN,&font_style);
//	
//	lv_obj_t *font_label5 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label5,user_label,LV_ALIGN_OUT_BOTTOM_MID,-20,10);
//	lv_label_set_text(font_label5,"用户反馈 ");
//	lv_label_set_style(font_label5,LV_LABEL_STYLE_MAIN,&font_style);
//	
//	lv_obj_t *font_label6 = lv_label_create(login_win,NULL);
//	lv_obj_align(font_label6,weather_label,LV_ALIGN_OUT_BOTTOM_MID,0,10);
//	lv_label_set_text(font_label6,"天气 ");
//	lv_label_set_style(font_label6,LV_LABEL_STYLE_MAIN,&font_style);	

//	lv_obj_t *font_label7 = lv_label_create(login_win,NULL);
//	lv_label_set_long_mode(font_label7,LV_LABEL_LONG_SROLL_CIRC);
//	lv_obj_set_size(font_label7,300,40);
//	lv_obj_align(font_label7,login_win,LV_ALIGN_IN_TOP_MID,100,20);
//	lv_label_set_text(font_label7,"小区停车管理系统V1.0 ");
//	lv_label_set_style(font_label7,LV_LABEL_STYLE_MAIN,&font32_style);	
//	
//		
//	sw_create(login_win);
//	bar_create(login_win);
//	image_hs_create(login_win);
//	ddlist_create(login_win);
//	time_show(login_win);
}

static void task_time(lv_task_t * t)
{
	char buff[20];
	sprintf(buff,"%d:%d:%d",Hours,Minutes,Secondsute);
	lv_label_set_text(time_label1,buff);
}

void time_show(lv_obj_t *parent)
{	
	static lv_style_t time_style;
	lv_style_copy(&time_style,&lv_style_plain);
	time_style.text.font = &my_font_16;
	time_style.text.color=LV_COLOR_WHITE;
	time_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	time_style.body.grad_color=time_style.body.main_color;	
	
	time_label1=lv_label_create(parent,NULL);
	lv_obj_align(time_label1,NULL,LV_ALIGN_IN_TOP_RIGHT,-45,20);
	time_task=lv_task_create(task_time,1000,LV_TASK_PRIO_MID,NULL);
	
	lv_obj_t *time_font_label=lv_label_create(parent,NULL);
	lv_obj_align(time_font_label,time_label1,LV_ALIGN_OUT_LEFT_MID,-10,0);
	lv_label_set_style(time_font_label,LV_LABEL_STYLE_MAIN,&time_style);
	lv_label_set_text(time_font_label,"时间： ");
	
}


