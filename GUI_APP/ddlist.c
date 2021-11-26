#include "ddlist.h"

LV_FONT_DECLARE(my_font_16);

#define DDLIST_DIRECTION_UP_EN    0  //是否将下拉列表框的弹出方向改为向上,默认情况是向下的

lv_style_t bg_style_ddlist;
lv_style_t sel_style;
lv_style_t font_ddlist_style;
lv_obj_t * ddlist1;
lv_obj_t * ddlist1_label;

//事件回调函数
static void event_handler(lv_obj_t * obj,lv_event_t event)
{
  if(event == LV_EVENT_VALUE_CHANGED)
  {
    char buf[32];
    uint16_t selected_index = lv_ddlist_get_selected(obj);//获取选项值的索引
    lv_ddlist_get_selected_str(obj,buf,sizeof(buf));//获取选项值的文本内容
    //printf("Option index: %d,Option text:%s\r\n",selected_index,buf);
  }
}


//例程入口
void ddlist_create(lv_obj_t *parent)
{
  //1.创建样式
  //1.1 创建背景样式
  lv_style_copy(&bg_style_ddlist,&lv_style_plain);
  bg_style_ddlist.body.main_color = LV_COLOR_WHITE;//纯白色背景
  bg_style_ddlist.body.grad_color = bg_style_ddlist.body.main_color;
  bg_style_ddlist.body.border.width = 1;//边框宽度
  bg_style_ddlist.body.border.color = LV_COLOR_MAKE(0xAA,0xAA,0xAA);//LV_COLOR_MAKE(0x30,0x30,0x30);//边框颜色
  bg_style_ddlist.body.padding.left = 10;//设置左侧的内边距
  bg_style_ddlist.text.color = LV_COLOR_BLACK;//文本颜色
  bg_style_ddlist.body.shadow.color = bg_style_ddlist.body.border.color;//阴影颜色
  bg_style_ddlist.body.shadow.width = 4;//阴影宽度
  //1.2 创建选择项被选中时的样式
  lv_style_copy(&sel_style,&lv_style_plain);
  sel_style.body.main_color = LV_COLOR_MAKE(0x5F,0xB8,0x78);//浅绿色背景
  sel_style.body.grad_color = sel_style.body.main_color;
  sel_style.text.color = LV_COLOR_WHITE;//文本为白色

	lv_style_copy(&font_ddlist_style,&lv_style_plain);
	font_ddlist_style.text.font = &my_font_16;
	font_ddlist_style.text.color=LV_COLOR_WHITE;
	font_ddlist_style.body.main_color=LV_COLOR_MAKE(0x27,0x2A,0x2D);//272A2D
	font_ddlist_style.body.grad_color=font_ddlist_style.body.main_color;		
	
  //2.创建下拉列表框
  ddlist1 = lv_ddlist_create(parent,NULL);
  lv_ddlist_set_options(ddlist1,"10\n20\n30\n40\n50");//设置列表选项
  lv_ddlist_set_selected(ddlist1,4);//设置默认选中值为Hangzhou
	lv_ddlist_set_fix_width(ddlist1,60);//设置固定宽度
  lv_ddlist_set_draw_arrow(ddlist1,true);//使能绘制向下的箭头
  lv_ddlist_set_style(ddlist1,LV_DDLIST_STYLE_BG,&bg_style_ddlist);//设置背景样式
  lv_ddlist_set_style(ddlist1,LV_DDLIST_STYLE_SEL,&sel_style);//设置背景样式
  lv_obj_set_event_cb(ddlist1, event_handler);//注册事件回调函数
  lv_obj_align(ddlist1,NULL,LV_ALIGN_CENTER,-110,60);//设置与屏幕的对齐方式
  #if(DDLIST_DIRECTION_UP_EN)
    lv_obj_align(ddlist1,NULL,LV_ALIGN_IN_BOTTOM_MID,0,-20);//重新设置与屏幕的对齐方式,必须为底部对齐
    lv_obj_set_auto_realign(ddlist1,true);//必须使能自动对齐,只有满足这俩点,才能看到向上弹出的效果
  #endif
	ddlist1_label=lv_label_create(parent,NULL);
	lv_obj_align(ddlist1_label,ddlist1,LV_ALIGN_OUT_LEFT_MID,-45,0);
	lv_label_set_style(ddlist1_label,LV_LABEL_STYLE_MAIN,&font_ddlist_style);
	lv_label_set_text(ddlist1_label,"小时单价： ");
	
}
