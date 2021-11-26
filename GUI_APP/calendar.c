#include "calendar.h"
#include "start_task.h"

//����,��һ,�ܶ�,....,����
const char * const day_names[7] = {"Su","Mo","Tu","We","Th","Fr","Sa"};
//һ��,����,����...,ʮ����
const char * const month_names[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
//��Ҫ��������ʾ������
const lv_calendar_date_t highlihted_days[2] = {{2021,11,17},{2018,11,13}};
//��ʽ
lv_style_t bg_style;
lv_style_t header_style;
lv_style_t header_pr_style;
lv_style_t day_names_style;
lv_style_t highlighted_style;
lv_style_t inactive_style;
lv_style_t today_style;
lv_style_t today_row_style;


//�¼��ص�����
static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	char buff[30];
	if(event==LV_EVENT_CLICKED)//�൱�������¼�,����Ҳ�����滻��LV_EVENT_RELEASED
	{
		lv_calendar_date_t * selected_date = lv_calendar_get_pressed_date(obj);//��ȡ�����µ�����,����˵���û�ѡ�������

		//���û����HEADER�����������Ϣ������ʱ,�����year=0,month=0,day=0�����,�������ǵù��˵��������
		if(selected_date&&(selected_date->year!=0)) {
				sprintf(buff,"%d/%d/%d",selected_date->year,selected_date->month,selected_date->day);
				//lv_label_set_text(label1,buff);//���û�ѡ������ڸ���ʾ����
				lv_calendar_set_today_date(obj,selected_date);//���û�ѡ�����������Ϊ���������,��TODAY����
				lv_calendar_set_showed_date(obj,selected_date);//��ת������������ڵĽ���
		}
	}
}


//�������
void calendar_create(lv_obj_t *parent)
{
	
	lv_obj_t *win=general_win_create(parent,"日历 ");
	//1.����8����ʽ
	//1.1 ����������ʽ
	lv_style_copy(&bg_style,&lv_style_plain_color);
	bg_style.body.main_color = LV_COLOR_WHITE;//������ɫ
	bg_style.body.grad_color = LV_COLOR_WHITE;
	bg_style.body.border.color = LV_COLOR_MAKE(57,61,73);//�߿����ɫ
	bg_style.body.border.width = 2;//�߿�Ŀ��
	bg_style.body.shadow.color = LV_COLOR_GRAY;//��Ӱ����ɫ
	bg_style.body.shadow.width = 6;//��Ӱ�Ŀ��
	bg_style.body.padding.left = 0;//������������߿�ľ���
	bg_style.text.color = LV_COLOR_BLACK;//δ��������ʾ�������ı���ɫ
	//1.2 ����HEADER��ʽ
	lv_style_copy(&header_style,&lv_style_plain_color);
	header_style.body.main_color = LV_COLOR_MAKE(57,61,73);//������ɫ
	header_style.body.grad_color = LV_COLOR_MAKE(57,61,73);
	header_style.body.padding.left = 15;//�������ͷ��ť����߿�ľ���
	header_style.body.padding.right = 15;//�����Ҽ�ͷ��ť���ұ߿�ľ���
	header_style.body.padding.top = 8;//�����ı��������ϱ߿�ľ���
	//1.3 ����HEADER����ʱ����ʽ
	lv_style_copy(&header_pr_style,&lv_style_plain_color);
	header_pr_style.text.color = LV_COLOR_GRAY;//��ͷ��ť����ʱ���ı���ɫ
	//1.4 ����������Ϣ�е���ʽ
	lv_style_copy(&day_names_style,&lv_style_plain_color);
	day_names_style.text.color = LV_COLOR_MAKE(0,150,136);
	//1.5 �����������ڵ���ʽ
	lv_style_copy(&highlighted_style,&lv_style_plain_color);
	highlighted_style.text.color = LV_COLOR_RED;//�ú�ɫ���и���
	//1.6 �����ϸ��µ���ĩ���ں��¸��µ��³�������ʽ
	lv_style_copy(&inactive_style,&lv_style_plain_color);
	inactive_style.text.color = LV_COLOR_MAKE(0xAA,0xAA,0xAA);//��ɫ
	//1.7 ����TODAY���ڵ���ʽ
	lv_style_copy(&today_style,&lv_style_plain_color);
	today_style.body.main_color = LV_COLOR_MAKE(85,150,216);
	today_style.body.grad_color = LV_COLOR_MAKE(85,150,216);
	today_style.body.radius = LV_RADIUS_CIRCLE;//Բ��
	today_style.text.color = LV_COLOR_WHITE;
	 //1.8 ����TODAY���������е�����
	lv_style_copy(&today_row_style,&lv_style_transp);
	today_row_style.text.color = LV_COLOR_MAKE(85,150,216);

	//2.������������
	lv_obj_t * calendar1 = lv_calendar_create(win,NULL);//������������
	lv_obj_set_size(calendar1,220,220);//���ô�С
	lv_obj_align(calendar1,NULL,LV_ALIGN_CENTER,0,0);//��������Ļ���ж���
	lv_obj_set_event_cb(calendar1,event_handler);//�����¼��ص�����
	lv_calendar_date_t today = {2021,11,17};//���Զ���Ϊ�ֲ���
	lv_calendar_set_today_date(calendar1,&today);//����TODAY����
	lv_calendar_set_showed_date(calendar1,&today);//��ת��TODAY�������ڵĽ���
	lv_calendar_set_day_names(calendar1,(const char **)day_names);//����������Ϣ�еı���,Ҳ���Բ�����,��ôlv_calendar����һ��Ĭ�ϵ�ֵ
	lv_calendar_set_month_names(calendar1,(const char **)month_names);//�����·ݵı���,Ҳ���Բ�����,��ôlv_calendar����һ��Ĭ�ϵ�ֵ
	lv_calendar_set_highlighted_dates(calendar1,(lv_calendar_date_t *)highlihted_days,sizeof(highlihted_days)/sizeof(highlihted_days[0]));//������Ҫ��������ʾ������
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_BG,&bg_style);//���������ؼ����岿�ֵı�����ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_HEADER,&header_style);//����HEADER��ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_HEADER_PR,&header_pr_style);//����HEADER����ʱ����ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_DAY_NAMES,&day_names_style);//����������Ϣ�е���ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_HIGHLIGHTED_DAYS,&highlighted_style);//���ø������ڵ���ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_INACTIVE_DAYS,&inactive_style);//���ø������ڵ���ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_TODAY_BOX,&today_style);//����TODAY���ڵ���ʽ
	lv_calendar_set_style(calendar1,LV_CALENDAR_STYLE_WEEK_BOX,&today_row_style);//����TODAY���������е���ʽ
}
