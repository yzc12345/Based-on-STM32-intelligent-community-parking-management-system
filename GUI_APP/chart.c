#include "chart.h"

LV_FONT_DECLARE(my_font_20);

#define POINT_COUNT   7  
const lv_coord_t series1_y[POINT_COUNT] = {30,60,40,60,20,60,50};

lv_style_t label_style;

void chart_create(lv_obj_t *parent)
{
	lv_style_copy(&label_style,&lv_style_plain);
  label_style.text.color=LV_COLOR_WHITE;
	label_style.text.font=&my_font_20;
	
	lv_obj_t *chart1=lv_chart_create(parent,NULL);
	lv_chart_set_type(chart1,LV_CHART_TYPE_COLUMN);
	lv_obj_set_size(chart1,200,200);
	lv_obj_align(chart1,NULL,LV_ALIGN_IN_TOP_LEFT,100,50);

	lv_chart_set_series_darking(chart1,LV_OPA_80);//设置数据线的黑阴影效果
	lv_chart_set_point_count(chart1,POINT_COUNT);//设置每条数据线所具有的数据点个数,如果不设置的话,则默认值是10
	lv_chart_set_div_line_count(chart1,4,4);//设置水平和垂直分割线
	lv_chart_set_range(chart1,0,100);//设置y轴的数值范围,[0,100]也是默认值
	lv_chart_set_y_tick_length(chart1,10,3);//设置y轴的主刻度线长度和次刻度线长度
	lv_chart_set_y_tick_texts(chart1,"100\n80\n60\n40\n20\n0",2,LV_CHART_AXIS_DRAW_LAST_TICK);
	//lv_chart_set_x_tick_length(chart1,10,3);//设置x轴的主刻度线长度和次刻度线长度
	//lv_chart_set_x_tick_texts(chart1," ",0,LV_CHART_AXIS_DRAW_LAST_TICK);//设置x轴的刻度数和主刻度标题
	lv_chart_set_margin(chart1,40);//设置刻度区域的高度

	lv_chart_series_t * series1=lv_chart_add_series(chart1,LV_COLOR_RED);
	lv_chart_set_points(chart1,series1,(lv_coord_t*)series1_y);

	lv_obj_t *text_label=lv_label_create(parent,NULL);
	lv_label_set_style(text_label,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_label,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,5,0);
	lv_label_set_text(text_label,"一 ");

	lv_obj_t *text_labe2=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe2,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe2,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,35,0);
	lv_label_set_text(text_labe2,"二 ");

  lv_obj_t *text_labe3=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe3,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe3,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,62,0);
	lv_label_set_text(text_labe3,"三 ");

  lv_obj_t *text_labe4=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe4,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe4,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,90,0);
	lv_label_set_text(text_labe4,"四 ");

  lv_obj_t *text_labe5=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe5,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe5,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,119,0);
	lv_label_set_text(text_labe5,"五 ");

  lv_obj_t *text_labe6=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe6,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe6,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,148,0);
	lv_label_set_text(text_labe6,"六 ");

  lv_obj_t *text_labe7=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe7,LV_LABEL_STYLE_MAIN,&label_style);
	lv_obj_align(text_labe7,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,176,0);
	lv_label_set_text(text_labe7,"日 ");

	lv_obj_t *text_labe8=lv_label_create(parent,NULL);
	lv_label_set_style(text_labe8,LV_LABEL_STYLE_MAIN,&label_style);
	lv_label_set_text(text_labe8,"单位：辆 ");
	lv_obj_align(text_labe8,chart1,LV_ALIGN_IN_TOP_LEFT,0,-25);

}


//lv_style_t scr_style;

//#define POINT_COUNT   7  //每条数据线所具有的数据点个数
//lv_style_t main_style;
//lv_style_t label_style;
//const lv_coord_t series1_y[POINT_COUNT] = {30,60,40,60,20,60,50};
//lv_obj_t * chart1;
//lv_chart_series_t * series1;



//void chart_create(lv_obj_t *parent)
//{
//	  //1.创建样式
//    lv_style_copy(&main_style,&lv_style_pretty);
//    main_style.body.main_color = LV_COLOR_WHITE;//主背景为纯白色
//    main_style.body.grad_color = main_style.body.main_color;
//    main_style.body.border.color = LV_COLOR_BLACK;//边框的颜色
//    main_style.body.border.width = 3;//边框的宽度
//    main_style.body.border.opa = LV_OPA_COVER;
//    main_style.body.radius = 0;
//    main_style.line.color = LV_COLOR_GRAY;//分割线和刻度线的颜色
//    main_style.text.color = LV_COLOR_WHITE;//主刻度标题的颜色

//    lv_style_copy(&label_style,&lv_style_plain);
//    label_style.text.color=LV_COLOR_WHITE;
//		//label_style.text.font=&my_font_20;

//    chart1=lv_chart_create(parent,NULL);
//    lv_chart_set_type(chart1,LV_CHART_TYPE_COLUMN);
//    lv_obj_set_size(chart1,300,300);
//    lv_obj_align(chart1,NULL,LV_ALIGN_IN_TOP_LEFT,100,0);


//    lv_chart_set_series_darking(chart1,LV_OPA_80);//设置数据线的黑阴影效果
//    lv_chart_set_style(chart1,LV_CHART_STYLE_MAIN,&main_style);//设置样式
//    lv_chart_set_point_count(chart1,POINT_COUNT);//设置每条数据线所具有的数据点个数,如果不设置的话,则默认值是10
//    lv_chart_set_div_line_count(chart1,4,4);//设置水平和垂直分割线
//    lv_chart_set_range(chart1,0,100);//设置y轴的数值范围,[0,100]也是默认值
//    lv_chart_set_y_tick_length(chart1,10,3);//设置y轴的主刻度线长度和次刻度线长度
//    lv_chart_set_y_tick_texts(chart1,"100\n80\n60\n40\n20\n0",2,LV_CHART_AXIS_DRAW_LAST_TICK);
//    //lv_chart_set_x_tick_length(chart1,10,3);//设置x轴的主刻度线长度和次刻度线长度
//    //lv_chart_set_x_tick_texts(chart1," ",0,LV_CHART_AXIS_DRAW_LAST_TICK);//设置x轴的刻度数和主刻度标题
//    lv_chart_set_margin(chart1,40);//设置刻度区域的高度

//    series1=lv_chart_add_series(chart1,LV_COLOR_RED);
//    lv_chart_set_points(chart1,series1,(lv_coord_t*)series1_y);

//    lv_obj_t *text_label=lv_label_create(parent,NULL);
//    lv_obj_align(text_label,chart1,LV_ALIGN_OUT_BOTTOM_LEFT,0,0);
//		lv_label_set_style(text_label,LV_LABEL_STYLE_MAIN,&label_style);
//    //lv_label_set_text(text_label,"星期一\t星期二\t星期三\t星期四\t星期五\t星期六\t星期日 ");
//		lv_label_set_text(text_label,"   1         2         3        4         5         6        7");
//}
