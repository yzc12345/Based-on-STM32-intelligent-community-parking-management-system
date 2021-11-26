#include "start_task.h"
#include <stdio.h>
#include "login_win.h"
#include "login_win.h"
#include "rtc_time.h"
#include "sw.h"
#include "bar.h"
#include "table.h"

LV_FONT_DECLARE(my_font_16);

#define BACK_BTN_TITLE		LV_SYMBOL_LEFT" Back\n"   //���ذ�ť���ı�����,��\n��Ϊ�˼Ӵ�������
//���ذ�ťר�õ��¼��ص�����
static void back_btn_event_handler(lv_obj_t * obj,lv_event_t event)
{
	if(event==LV_EVENT_PRESSED)//�����¼�
	{
		lv_label_set_text(obj,"#444444 "BACK_BTN_TITLE"#");//ʹ���ı���ɫ���,�а��µ�Ч��
		lv_label_set_recolor(obj,true);//ʹ���ػ�ɫ
	}else if(event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)//�����¼��򻮳��ؼ���Ч�����¼�
	{
		//ɾ������,��ʵҲ����ɾ��lv_page����
		//��Ϊback_btn����lv_pageҳ���е�,��Ҫ��ȡ2����ܻ�ȡ��������lv_page����
		obj = lv_obj_get_parent(obj);
		obj = lv_obj_get_parent(obj);//��ʱ��objΪlv_pageҳ�����,������
		lv_event_cb_t event_cb = lv_obj_get_event_cb(obj);
		if(event_cb)//�˴����Ƿ��������¼��ص�����,�����˵Ļ������,�������������ͷ���Դ�Ȳ���
			event_cb(obj,USER_EVENT_BACK);
		lv_obj_del(obj);//ɾ���˴���,�൱�ڷ��ز���
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


//����һ��ͨ�õĴ���,�����б���ͷ��ذ�ť
//parent:������
//title:����ı���
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
	
	//��������
	win = lv_page_create(parent,NULL);//��lv_pageҳ����ģ�ⴰ��
	lv_obj_set_size(win,lv_obj_get_width(parent),lv_obj_get_height(parent));//���ô���Ĵ�С
	lv_page_set_sb_mode(win,LV_SB_MODE_AUTO);//���ù�������ģʽΪ�Զ�
	lv_page_set_edge_flash(win,true);//ʹ�ܱ�Ե��Բ������Ч��
	lv_page_set_style(win,LV_PAGE_STYLE_SCRL,&lv_style_transp_tight);//����scrl��������ʽΪ͸��
	//����һ������
	lv_obj_t * title_label = lv_label_create(win,NULL);
	lv_label_set_text(title_label,title);//���ô������
	lv_obj_align(title_label,NULL,LV_ALIGN_IN_TOP_MID,-30,TOP_OFFSET);//���ö��뷽ʽ
	lv_label_set_style(title_label,LV_LABEL_STYLE_MAIN,&font_style);
	//�������ذ�ť
	lv_obj_t * back_btn = lv_label_create(win,NULL);//�ñ�ǩ��ģ�ⰴť
	lv_label_set_text(back_btn,BACK_BTN_TITLE);//�����ı�
	lv_obj_align(back_btn,NULL,LV_ALIGN_IN_TOP_LEFT,5,TOP_OFFSET);//���ö��뷽ʽ
	lv_obj_set_click(back_btn,true);//ʹ�ܵ������
	lv_obj_set_event_cb(back_btn,back_btn_event_handler);//�����¼��ص�����,���ڹرմ���

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

//	//1.������ʽ
//	//1.1 ����������ʽ
//	lv_style_copy(&bg_style,&lv_style_plain);
//	bg_style.body.main_color = LV_COLOR_MAKE(49,49,49);//��ɫ����
//	bg_style.body.grad_color = bg_style.body.main_color;
//	bg_style.body.border.color = LV_COLOR_MAKE(150,150,150);//�߿���ɫ
//	bg_style.body.border.width = 2;//�߿���
//	bg_style.text.color = LV_COLOR_WHITE;
//	//1.2 ����ҳ��ָʾ������ʽ
//	lv_style_copy(&indic_style,&lv_style_plain_color);
//	indic_style.body.main_color = LV_COLOR_MAKE(42,212,66);//ָʾ������ɫ,��ɫ
//	indic_style.body.grad_color = indic_style.body.main_color;
//	indic_style.body.padding.inner = 3;//����ָʾ���ĸ߶�
//	//1.3 ����ҳ��ѡ��ť���ı�����ʽ
//	//lv_style_transp_tight��ʽ�е�inner,left,top,right,bottom���ڼ��ֵ��Ϊ0,����Ϊ����ҳ��ѡ��ť�ܹ�������һ��
//	lv_style_copy(&btn_bg_style,&lv_style_transp_tight);
//	//1.4 ������ť����̬�µ�������ʽ
//	lv_style_copy(&btn_rel_style,&lv_style_plain_color);
//	btn_rel_style.body.main_color = LV_COLOR_MAKE(98,98,98);
//	btn_rel_style.body.grad_color = btn_rel_style.body.main_color;
//	btn_rel_style.body.border.color = LV_COLOR_MAKE(150,150,150);//�߿���ɫ
//	btn_rel_style.body.border.width = 1;
//	btn_rel_style.text.color = LV_COLOR_WHITE;//������ɫ
//	btn_rel_style.text.font=&my_font_30;
//	//btn_rel_style.body.radius=LV_RADIUS_CIRCLE;
//	//1.5 ������ť����̬�µİ�����ʽ
//	lv_style_copy(&btn_pr_style,&btn_rel_style);
//	btn_pr_style.body.main_color = LV_COLOR_GRAY;
//	btn_pr_style.body.grad_color = btn_pr_style.body.main_color;
//	//1.6 ������ť�л�̬�µ�������ʽ
//	lv_style_copy(&btn_tgl_rel_style,&btn_rel_style);
//	btn_tgl_rel_style.body.main_color = bg_style.body.main_color;//����������ɫһ��
//	btn_tgl_rel_style.body.grad_color = btn_tgl_rel_style.body.main_color;
//	//1.7 ������ť�л�̬�µİ�����ʽ
//	//���ֺ�btn_tgl_rel_styleһ��������
//	lv_style_copy(&btn_tgl_pr_style,&btn_tgl_rel_style);

//	tabview1=lv_tabview_create(scr,NULL);
//	lv_obj_set_size(tabview1,lv_obj_get_width(scr),lv_obj_get_height(scr));
//	lv_obj_align(tabview1,NULL,LV_ALIGN_CENTER,0,0);

//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BG,&bg_style);//���ñ�����ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_INDIC,&indic_style);//����ҳ��ָʾ������ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_BG,&btn_bg_style);//����ҳ��ѡ��ť���ı�����ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_REL,&btn_rel_style);//���ð�ť����̬�µ�������ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_PR,&btn_pr_style);//���ð�ť����̬�µİ�����ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_TGL_REL,&btn_tgl_rel_style);//���ð�ť�л�̬�µ�������ʽ
//	lv_tabview_set_style(tabview1,LV_TABVIEW_STYLE_BTN_TGL_PR,&btn_tgl_pr_style);//���ð�ť�л�̬�µİ�����ʽ


//	lv_obj_t *tab1_page=lv_tabview_add_tab(tabview1,"停车数据");
//	table_create(tab1_page);
//	
//	lv_obj_t *tab2_page=lv_tabview_add_tab(tabview1,"图表");
//	chart_create(tab2_page);
//}



