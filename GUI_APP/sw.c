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


//label1��ʾ���ص�״̬
#define LABEL1_DISP_STATE(sta)   lv_label_set_text(label1,sta?"#65C466 ON#":"#FF0000 OFF#")


//�¼��ص�����
static void event_handler(lv_obj_t * obj,lv_event_t event)
{
	if(event==LV_EVENT_VALUE_CHANGED)
	{
		LABEL1_DISP_STATE(lv_sw_get_state(obj));
	}
}

//�������
void sw_create(lv_obj_t *parent)
{
	//1.����4����ʽ
	//1.1 ����������ʽ
	lv_style_copy(&sw_bg_style,&lv_style_plain_color);
	sw_bg_style.body.main_color = LV_COLOR_MAKE(0xCC,0xCC,0xCC);//�Ұ�ɫ
	sw_bg_style.body.grad_color = LV_COLOR_MAKE(0xCC,0xCC,0xCC);
	sw_bg_style.body.radius = LV_RADIUS_CIRCLE;//Բ��
	sw_bg_style.body.padding.left = -3;//���ñ����߿�����ť�߿�֮��ľ���,������Ϊ����ʱ,���������ť��
	sw_bg_style.body.padding.right = -3;
	sw_bg_style.body.padding.top = -3;
	sw_bg_style.body.padding.bottom = -3;
	//1.2 ����ָʾ����ʽ
	lv_style_copy(&sw_indic_style,&lv_style_plain_color);
	sw_indic_style.body.main_color = LV_COLOR_MAKE(0x65,0xC4,0x66);//ǳ��ɫ
	sw_indic_style.body.grad_color = LV_COLOR_MAKE(0x65,0xC4,0x66);
	sw_indic_style.body.radius = LV_RADIUS_CIRCLE;//Բ��
	sw_indic_style.body.padding.left = 0;//��ָʾ���뱳���߿�֮���޾���
	sw_indic_style.body.padding.top = 0;
	sw_indic_style.body.padding.right = 0;
	sw_indic_style.body.padding.bottom = 0;
	//1.3 �����ر�״̬ʱ,��ť����ʽ
	lv_style_copy(&sw_knob_off_style,&lv_style_plain_color);
	sw_knob_off_style.body.main_color = LV_COLOR_WHITE;//����ɫ
	sw_knob_off_style.body.grad_color = LV_COLOR_WHITE;
	sw_knob_off_style.body.radius = LV_RADIUS_CIRCLE;//Բ��
	sw_knob_off_style.body.shadow.color = LV_COLOR_MAKE(0xA0,0xA0,0xA0);//��Ӱ��ɫ
	sw_knob_off_style.body.shadow.width = 6;//��Ӱ���
	//1.4 ������״̬ʱ,��ť����ʽ
	lv_style_copy(&sw_knob_on_style,&sw_knob_off_style);//���ֺ͹ر�״̬ʱ����ʽһ������

	lv_style_copy(&font_style,&lv_style_plain);
	font_style.body.main_color=LV_COLOR_WHITE;
	font_style.body.grad_color=font_style.body.main_color;
	font_style.text.color=LV_COLOR_WHITE;
	font_style.text.font=&my_font_16;

	//2.�������ض���
	sw1 = lv_sw_create(parent,NULL);
	lv_obj_set_size(sw1,100,50);//���ô�С
	lv_obj_align(sw1,NULL,LV_ALIGN_IN_BOTTOM_LEFT,50,-50);//��������Ļ���־���
	lv_sw_on(sw1,LV_ANIM_ON);//����Ϊ��״̬,�����ж���Ч��
	lv_sw_set_style(sw1,LV_SW_STYLE_BG,&sw_bg_style);//���ñ�����ʽ
	lv_sw_set_style(sw1,LV_SW_STYLE_INDIC,&sw_indic_style);//����ָʾ����ʽ
	lv_sw_set_style(sw1,LV_SW_STYLE_KNOB_OFF,&sw_knob_off_style);//���ùر�״̬ʱ,��ť����ʽ
	lv_sw_set_style(sw1,LV_SW_STYLE_KNOB_ON,&sw_knob_on_style);//���ô�״̬ʱ,��ť����ʽ
	lv_obj_set_event_cb(sw1,event_handler);//�����¼��ص�����

	//3.����label��ǩ,������ʾ���صĵ�ǰ״̬
	label1 = lv_label_create(parent,NULL);
	lv_label_set_recolor(label1,true);//ʹ���ػ�ɫ����
	LABEL1_DISP_STATE(lv_sw_get_state(sw1));
	lv_obj_align(label1,sw1,LV_ALIGN_OUT_BOTTOM_MID,30,10);
	
	label2 = lv_label_create(parent,NULL);
	lv_label_set_text(label2,"闸门开关： ");
	lv_obj_align(label2,sw1,LV_ALIGN_OUT_BOTTOM_MID,-60,10);
	lv_label_set_style(label2,LV_LABEL_STYLE_MAIN,&font_style);
}
