#include "bar.h"

LV_FONT_DECLARE(my_font_16);

lv_obj_t *bar;
lv_obj_t *bar_label;
lv_obj_t *bar_labe2;

lv_style_t bar_bg_style;//进度条的背景样式
lv_style_t bar_indic_style;//进度条的指示器样式
lv_style_t bar_font_style;

lv_task_t *task_bar=NULL;
uint16_t bar_value=0;
void get_value_bar(lv_task_t *task)
{
	if(task_bar==NULL)
			return;
	char buff[10];
	bar_value=lv_bar_get_value(bar);
	sprintf(buff,"%d",bar_value);
	lv_label_set_text(bar_labe2,buff);
	
}


void bar_create(lv_obj_t *parent)
{
	//1.创建进度条的背景和指示器样式
	//1.1 创建背景样式
	lv_style_copy(&bar_bg_style,&lv_style_plain_color);
	bar_bg_style.body.main_color = LV_COLOR_MAKE(0xBB,0xBB,0xBB);
	bar_bg_style.body.grad_color = LV_COLOR_MAKE(0xBB,0xBB,0xBB);
	//bar_bg_style.body.radius = LV_RADIUS_CIRCLE;//绘制圆角
	//1.2 创建指示器样式
	lv_style_copy(&bar_indic_style,&lv_style_plain_color);

	bar_indic_style.body.main_color = LV_COLOR_MAKE(0x5F,0xB8,0x78);
	bar_indic_style.body.grad_color = LV_COLOR_MAKE(0x5F,0xB8,0x78);
	//bar_indic_style.body.radius = LV_RADIUS_CIRCLE;//绘制圆角
	bar_indic_style.body.padding.left = 0;//让指示器跟背景边框之间没有距离
	bar_indic_style.body.padding.top = 0;
	bar_indic_style.body.padding.right = 0;
	bar_indic_style.body.padding.bottom = 0;

	lv_style_copy(&bar_font_style,&lv_style_plain);
	bar_font_style.text.font = &my_font_16;
	bar_font_style.text.color=LV_COLOR_WHITE;
	bar_font_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	bar_font_style.body.grad_color=bar_font_style.body.main_color;	
	
	//3.创建垂直进度条
	bar = lv_bar_create(parent, NULL);//从 bar1 进行拷贝
	lv_obj_set_size(bar,100,40);//设置大小,宽度比高度小就是垂直的
	lv_obj_align(bar,NULL,LV_ALIGN_IN_BOTTOM_LEFT,50,-150);
	lv_bar_set_range(bar,0,50);
	lv_bar_set_value(bar,30,LV_ANIM_ON);
	lv_bar_set_style(bar,LV_BAR_STYLE_BG,&bar_bg_style);
	lv_bar_set_style(bar,LV_BAR_STYLE_INDIC,&bar_indic_style);
	task_bar=lv_task_create(get_value_bar,1000,LV_TASK_PRIO_MID,NULL);
	
	bar_label=lv_label_create(parent,NULL);
	lv_obj_align(bar_label,bar,LV_ALIGN_IN_BOTTOM_MID,-50,20);
	lv_label_set_style(bar_label,LV_LABEL_STYLE_MAIN,&bar_font_style);
	lv_label_set_text(bar_label,"车库剩余容量： ");
	
	bar_labe2=lv_label_create(parent,NULL);
	lv_obj_align(bar_labe2,bar,LV_ALIGN_IN_BOTTOM_MID,50,20);
	lv_obj_set_auto_realign(bar_labe2,true);
	//lv_label_set_text(bar_labe2,"0");//设置文本
}
