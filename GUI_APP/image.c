#include "image.h"



LV_IMG_DECLARE(hs);
void image_hs_create(lv_obj_t *parent)
{	
	static lv_style_t my_style;
	lv_style_copy(&my_style,&lv_style_plain);
	my_style.image.color=LV_COLOR_BLACK;
	my_style.image.intense = 0;//暂时不使能重绘色功能
  my_style.image.opa = LV_OPA_COVER;//透明度
	
	lv_obj_t *image_hs=lv_img_create(parent,NULL);
	lv_obj_align(image_hs,NULL,LV_ALIGN_IN_RIGHT_MID,-400,-150);
	lv_obj_set_size(image_hs,400,126);
	lv_img_set_src(image_hs,&hs);
	lv_img_set_style(image_hs,LV_IMG_STYLE_MAIN,&my_style);//设置样式


}
