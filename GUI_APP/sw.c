#include "sw.h"

LV_FONT_DECLARE(my_font_16);

lv_style_t sw_bg_style;
lv_style_t sw_indic_style;
lv_style_t sw_knob_off_style;
lv_style_t sw_knob_on_style;
lv_style_t font_style;

lv_obj_t *  sw1;
lv_obj_t * label1;
lv_obj_t *label2;


//label1显示开关的状态
#define LABEL1_DISP_STATE(sta)   lv_label_set_text(label1,sta?"#65C466 ON#":"#FF0000 OFF#")


//事件回调函数
static void event_handler(lv_obj_t * obj,lv_event_t event)
{
	if(event==LV_EVENT_VALUE_CHANGED)
	{
		LABEL1_DISP_STATE(lv_sw_get_state(obj));
	}
}

//例程入口
void sw_create(lv_obj_t *parent)
{
	//1.创建4个样式
	//1.1 创建背景样式
	lv_style_copy(&sw_bg_style,&lv_style_plain_color);
	sw_bg_style.body.main_color = LV_COLOR_MAKE(0xCC,0xCC,0xCC);//灰白色
	sw_bg_style.body.grad_color = LV_COLOR_MAKE(0xCC,0xCC,0xCC);
	sw_bg_style.body.radius = LV_RADIUS_CIRCLE;//圆角
	sw_bg_style.body.padding.left = -3;//设置背景边框与旋钮边框之间的距离,当设置为负数时,背景会比旋钮大
	sw_bg_style.body.padding.right = -3;
	sw_bg_style.body.padding.top = -3;
	sw_bg_style.body.padding.bottom = -3;
	//1.2 创建指示器样式
	lv_style_copy(&sw_indic_style,&lv_style_plain_color);
	sw_indic_style.body.main_color = LV_COLOR_MAKE(0x65,0xC4,0x66);//浅绿色
	sw_indic_style.body.grad_color = LV_COLOR_MAKE(0x65,0xC4,0x66);
	sw_indic_style.body.radius = LV_RADIUS_CIRCLE;//圆角
	sw_indic_style.body.padding.left = 0;//让指示器与背景边框之间无距离
	sw_indic_style.body.padding.top = 0;
	sw_indic_style.body.padding.right = 0;
	sw_indic_style.body.padding.bottom = 0;
	//1.3 创建关闭状态时,旋钮的样式
	lv_style_copy(&sw_knob_off_style,&lv_style_plain_color);
	sw_knob_off_style.body.main_color = LV_COLOR_WHITE;//纯白色
	sw_knob_off_style.body.grad_color = LV_COLOR_WHITE;
	sw_knob_off_style.body.radius = LV_RADIUS_CIRCLE;//圆角
	sw_knob_off_style.body.shadow.color = LV_COLOR_MAKE(0xA0,0xA0,0xA0);//阴影颜色
	sw_knob_off_style.body.shadow.width = 6;//阴影宽度
	//1.4 创建打开状态时,旋钮的样式
	lv_style_copy(&sw_knob_on_style,&sw_knob_off_style);//保持和关闭状态时的样式一样即可

	lv_style_copy(&font_style,&lv_style_plain);
	font_style.body.main_color=LV_COLOR_WHITE;
	font_style.body.grad_color=font_style.body.main_color;
	font_style.text.color=LV_COLOR_WHITE;
	font_style.text.font=&my_font_16;

	//2.创建开关对象
	sw1 = lv_sw_create(parent,NULL);
	lv_obj_set_size(sw1,100,50);//设置大小
	lv_obj_align(sw1,NULL,LV_ALIGN_IN_BOTTOM_LEFT,50,-50);//设置与屏幕保持居中
	lv_sw_on(sw1,LV_ANIM_ON);//设置为打开状态,并带有动画效果
	lv_sw_set_style(sw1,LV_SW_STYLE_BG,&sw_bg_style);//设置背景样式
	lv_sw_set_style(sw1,LV_SW_STYLE_INDIC,&sw_indic_style);//设置指示器样式
	lv_sw_set_style(sw1,LV_SW_STYLE_KNOB_OFF,&sw_knob_off_style);//设置关闭状态时,旋钮的样式
	lv_sw_set_style(sw1,LV_SW_STYLE_KNOB_ON,&sw_knob_on_style);//设置打开状态时,旋钮的样式
	lv_obj_set_event_cb(sw1,event_handler);//设置事件回调函数

	//3.创建label标签,用来显示开关的当前状态
	label1 = lv_label_create(parent,NULL);
	lv_label_set_recolor(label1,true);//使能重绘色功能
	LABEL1_DISP_STATE(lv_sw_get_state(sw1));
	lv_obj_align(label1,sw1,LV_ALIGN_OUT_BOTTOM_MID,30,10);
	
	label2 = lv_label_create(parent,NULL);
	lv_label_set_text(label2,"闂搁棬寮�鍏筹細 ");
	lv_obj_align(label2,sw1,LV_ALIGN_OUT_BOTTOM_MID,-60,10);
	lv_label_set_style(label2,LV_LABEL_STYLE_MAIN,&font_style);
}
