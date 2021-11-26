#include "rtc_time.h"
#include "rtc.h"
#include "led.h"
#include "start_task.h"


lv_obj_t *gauge_m;
lv_obj_t *gauge_f;
lv_obj_t *gauge_s;

void set_tim(uint8_t hour,uint8_t min,uint8_t sec);//设置时间

lv_color_t colors[3];
lv_task_t *task1=NULL;

uint8_t Secondsute=15;
uint8_t Minutes=29;
uint8_t Hours=15;
void task_cb(lv_task_t * task)
{
	set_tim(Hours,Minutes,Secondsute);
	if(task==NULL)
			return;
}


void RTC_Time_create(lv_obj_t *parent)
{
		lv_obj_t *win=general_win_create(parent,"时间 ");
	
		colors[0]=LV_COLOR_RED;
		colors[1]=LV_COLOR_BLUE;
		colors[2]=LV_COLOR_GREEN;
//------------------设置时针 不要刻度线------------------
    gauge_s = lv_gauge_create(win,NULL);
    lv_obj_set_size(gauge_s,100,100);
    lv_obj_align(gauge_s,NULL, LV_ALIGN_CENTER,0,0);

    static lv_style_t gauge_style;//
    lv_style_copy(&gauge_style,gauge_s->style_p);
    gauge_style.body.padding.left = 0;//不要表盘刻度线

    lv_gauge_set_range(gauge_s,0,60);
    lv_gauge_set_scale(gauge_s,360,61,0);
    lv_gauge_set_needle_count(gauge_s,1,&colors[0]);//时针
    lv_gauge_set_style(gauge_s,LV_GAUGE_STYLE_MAIN,&gauge_style);
    //lv_gauge_set_value(gauge_s,0,30);

    //------------------设置分针 不要刻度线------------------
    gauge_f = lv_gauge_create(win,NULL);
    lv_obj_set_size(gauge_f,140,140);
    lv_obj_align(gauge_f,NULL, LV_ALIGN_CENTER,0,0);

    lv_gauge_set_range(gauge_f,0,60);
    lv_gauge_set_scale(gauge_f,360,61,0);
    lv_gauge_set_needle_count(gauge_f,1,&colors[1]);//分针
    lv_gauge_set_style(gauge_f,LV_GAUGE_STYLE_MAIN,&gauge_style);
    //lv_gauge_set_value(gauge_f,0,35);
    //------------------设置秒针 及60根刻度线------------------
    gauge_m = lv_gauge_create(win,NULL);
    lv_obj_set_size(gauge_m,180,180);
    lv_obj_align(gauge_m,NULL, LV_ALIGN_CENTER,0,0);

    lv_gauge_set_range(gauge_m,0,60);
    lv_gauge_set_scale(gauge_m,360,61,0);
    lv_gauge_set_needle_count(gauge_m,1,&colors[2]);//秒针
    //lv_gauge_set_value(gauge_m,0,55);

    //-----------------设置外表盘----------------------
    lv_obj_t *arc = lv_arc_create(win,NULL);
    lv_obj_set_size(arc,190,190);
    lv_obj_align(arc,NULL, LV_ALIGN_CENTER,0,0);
    lv_arc_set_angles(arc, 0, 360);
    //----------------设置宽刻度线-------------------------
    lv_obj_t *lmeter = lv_lmeter_create(win,NULL);
    lv_obj_set_size(lmeter,180,180);
    lv_obj_align(lmeter,NULL, LV_ALIGN_CENTER,0,0);
    lv_lmeter_set_scale(lmeter,360,13);

    static lv_style_t lmeter_style;//
    lv_style_copy(&lmeter_style,gauge_s->style_p);
    lmeter_style.body.padding.left = 10;
    lmeter_style.line.width = 4;
		lmeter_style.line.color=LV_COLOR_WHITE;
		lmeter_style.body.main_color=LV_COLOR_WHITE;
		lmeter_style.body.grad_color=lmeter_style.body.main_color;
    lv_lmeter_set_style(lmeter,LV_LMETER_STYLE_MAIN,&lmeter_style);
		lv_lmeter_set_style(arc,LV_ARC_STYLE_MAIN,&lmeter_style);
		
    set_tim(Hours,Minutes,Secondsute);//设置时间 06:59:45
		task1=lv_task_create(task_cb,1000,LV_TASK_PRIO_MID,NULL);
}
//------------------------------------------------------------

void set_tim(uint8_t hour,uint8_t min,uint8_t sec)//设置时间
{
  uint8_t min_s = min;

  if(sec < 30) sec += 30;  //加减30是因为仪表盘的0起始线 为30秒钟刻度线
  else sec -= 30;
  lv_gauge_set_value(gauge_m,0,sec);//秒针
  //-----------------------
  if(min < 30) min += 30;
  else min -= 30;
  lv_gauge_set_value(gauge_f,0,min);//分针
  //----------------------
  hour *= 5;
  //分针每走12格 时针走一格
  hour += min_s/12; //分针参数不会等于60
  if(hour < 30) hour += 30;
  else hour -= 30;
  lv_gauge_set_value(gauge_s,0,hour);//时针

}


