#include "start_task.h"
#include <stdio.h>
#include "login_win.h"
#include "login_win.h"
#include "rtc_time.h"
#include "sw.h"
#include "bar.h"
#include "table.h"

LV_FONT_DECLARE(my_font_16);

#define BACK_BTN_TITLE		LV_SYMBOL_LEFT" Back\n"   //返回按钮的文本内容,加\n是为了加大点击区域
//返回按钮专用的事件回调函数
static void back_btn_event_handler(lv_obj_t * obj,lv_event_t event)
{
	if(event==LV_EVENT_PRESSED)//按下事件
	{
		lv_label_set_text(obj,"#444444 "BACK_BTN_TITLE"#");//使能文本颜色变灰,有按下的效果
		lv_label_set_recolor(obj,true);//使能重绘色
	}else if(event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)//松手事件或划出控件有效区域事件
	{
		//删除窗体,其实也就是删除lv_page对象
		//因为back_btn是在lv_page页面中的,需要获取2层才能获取到真正的lv_page对象
		obj = lv_obj_get_parent(obj);
		obj = lv_obj_get_parent(obj);//此时的obj为lv_page页面对象,即窗体
		lv_event_cb_t event_cb = lv_obj_get_event_cb(obj);
		if(event_cb)//此窗体是否设置了事件回调函数,设置了的话则调用,可以用来进行释放资源等操作
			event_cb(obj,USER_EVENT_BACK);
		lv_obj_del(obj);//删除此窗体,相当于返回操作
		login_win_create(lv_scr_act());
		if(task1!=NULL)
		{
			lv_task_del(task1);
			task1=NULL;
		}
		if(table_task!=NULL)
		{
			lv_task_del(table_task);
			table_task=NULL;
		}
	}
}


//创建一个通用的窗体,它具有标题和返回按钮
//parent:父对象
//title:窗体的标题
lv_obj_t * general_win_create(lv_obj_t * parent,const char * title)
{
	#define	TOP_OFFSET	5
	lv_obj_t * win;

	static lv_style_t font_style;
	lv_style_copy(&font_style,&lv_style_plain);
	font_style.text.font = &my_font_16;
	font_style.text.color=LV_COLOR_WHITE;
	font_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	font_style.body.grad_color=font_style.body.main_color;		
	
	//创建窗体
	win = lv_page_create(parent,NULL);//用lv_page页面来模拟窗体
	lv_obj_set_size(win,lv_obj_get_width(parent),lv_obj_get_height(parent));//设置窗体的大小
	lv_page_set_sb_mode(win,LV_SB_MODE_AUTO);//设置滚动条的模式为自动
	lv_page_set_edge_flash(win,true);//使能边缘半圆弧动画效果
	lv_page_set_style(win,LV_PAGE_STYLE_SCRL,&lv_style_transp_tight);//设置scrl容器的样式为透明
	//创建一个标题
	lv_obj_t * title_label = lv_label_create(win,NULL);
	lv_label_set_text(title_label,title);//设置窗体标题
	lv_obj_align(title_label,NULL,LV_ALIGN_IN_TOP_MID,-30,TOP_OFFSET);//设置对齐方式
	lv_label_set_style(title_label,LV_LABEL_STYLE_MAIN,&font_style);
	//创建返回按钮
	lv_obj_t * back_btn = lv_label_create(win,NULL);//用标签来模拟按钮
	lv_label_set_text(back_btn,BACK_BTN_TITLE);//设置文本
	lv_obj_align(back_btn,NULL,LV_ALIGN_IN_TOP_LEFT,5,TOP_OFFSET);//设置对齐方式
	lv_obj_set_click(back_btn,true);//使能点击功能
	lv_obj_set_event_cb(back_btn,back_btn_event_handler);//设置事件回调函数,用于关闭窗体

	//RTC_Time_create(parent);
	return win;
}



void test_start()
{
	lv_obj_t *scr=lv_scr_act();

	lv_theme_t *theme=lv_theme_night_init(210,NULL);
	lv_theme_set_current(theme);

	
	login_win_create(scr);
		
 
	
}




//lv_style_t bg_style;
//lv_style_t indic_style;
//lv_style_t btn_bg_style;
//lv_style_t btn_rel_style;
//lv_style_t btn_pr_style;
//lv_style_t btn_tgl_rel_style;
//lv_style_t btn_tgl_pr_style;

//lv_obj_t *tabview1;

//void test_start(void)
//{
//	lv_obj_t *scr=lv_scr_act();

//	//1.创建样式
//	//1.1 创建背景样式
//	lv_style_copy(&bg_style,&lv_style_plain);
//	bg_style.body.main_color = LV_COLOR_MAKE(49,49,49);//纯色背景
//	bg_style.body.grad_color = bg_style.body.main_color;
//	bg_style.body.border.color = LV_COLOR_MAKE(150,150,150);//边框颜色
//	bg_style.body.border.width = 2;//边框宽度
//	bg_style.text.color = LV_COLOR_WHITE;
//	//1.2 创建页面指示器的样式
//	lv_style_copy(&indic_style,&lv_style_plain_color);
//	indic_style.body.main_color = LV_COLOR_MAKE(42,212,66);//指示器的颜色,绿色
//	indic_style.body.grad_color = indic_style.body.main_color;
//	indic_style.body.padding.inner = 3;//设置指示器的高度
//	//1.3 创建页面选择按钮栏的背景样式
//	//lv_style_transp_tight样式中的inner,left,top,right,bottom等内间距值都为0,这是为了让页面选择按钮能够紧挨在一起
//	lv_style_copy(&btn_bg_style,&lv_style_transp_tight);
//	//1.4 创建按钮正常态下的松手样式
//	lv_style_copy(&btn_rel_style,&lv_style_plain_color);
//	btn_rel_style.body.main_color = LV_COLOR_MAKE(98,98,98);
//	btn_rel_style.body.grad_color = btn_rel_style.body.main_color;
//	btn_rel_style.body.border.color = LV_COLOR_MAKE(150,150,150);//边框颜色
//	btn_rel_style.body.border.width = 1;
//	btn_rel_style.text.color = LV_COLOR_WHITE;//字体颜色
//	btn_rel_style.text.font=&my_font_30;
//	//btn_rel_style.body.radius=LV_RADIUS_CIRCLE;
//	//1.5 创建按钮正常态下的按下样式
//	lv_style_copy(&btn_pr_style,&btn_rel_style);
//	btn_pr_style.body.main_color = LV_COLOR_GRAY;
//	btn_pr_style.body.grad_color = btn_pr_style.body.main_color;
//	//1.6 创建按钮切换态下的松手样式
//	lv_style_copy(&btn_tgl_rel_style,&btn_rel_style);
//	btn_tgl_rel_style.body.main_color = bg_style.body.main_color;//和主背景颜色一致
//	btn_tgl_rel_style.body.grad_color = btn_tgl_rel_style.body.main_color;
//	//1.7 创建按钮切换态下的按下样式
//	//保持和btn_tgl_rel_style一样就行了
//	lv_style_copy(&btn_tgl_pr_style,&btn_tgl_rel_style);

//	tabview1=lv_tabview_create(scr,NULL);
//	lv_obj_set_size(tabview1,lv_obj_get_width(scr),lv_obj_get_height(scr));
//	lv_obj_align(tabview1,NULL,LV_ALIGN_CENTER,0,0);

//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BG,&bg_style);//设置背景样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_INDIC,&indic_style);//设置页面指示器的样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_BG,&btn_bg_style);//设置页面选择按钮栏的背景样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_REL,&btn_rel_style);//设置按钮正常态下的松手样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_PR,&btn_pr_style);//设置按钮正常态下的按下样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_TGL_REL,&btn_tgl_rel_style);//设置按钮切换态下的松手样式
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_TGL_PR,&btn_tgl_pr_style);//设置按钮切换态下的按下样式


//	lv_obj_t *tab1_page=lv_tabview_add_tab(tabview1,"鍋滆溅鏁版嵁");
//	table_create(tab1_page);
//	
//	lv_obj_t *tab2_page=lv_tabview_add_tab(tabview1,"鍥捐〃");
//	chart_create(tab2_page);
//}



