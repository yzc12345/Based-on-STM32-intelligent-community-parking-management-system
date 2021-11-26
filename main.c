#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "ltdc.h"
#include "sdram.h"
#include "touch.h"
#include "timer.h"
#include "rtc.h"
#include "lvgl.h"
#include "usart.h"
#include "malloc.h"
#include "esp8266.h"
#include "table.h"
#include "ultro.h"
#include "duoji.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_apps\demo\demo.h" 
#include "lv_tests\lv_test_theme\lv_test_theme_1.h" 
#include "lv_tests\lv_test_theme\lv_test_theme_2.h"
#include "start_task.h"
#include "rc522_config.h"
#include "rc522_function.h"

//ע:����littleVGL��,��ò�Ҫ����-O���Ż�,����Ϊ-O0���Ż��Ϳ�����

#define TEST_NUM		1   //1,2,3�ֱ��Ӧ������ʾ����


int main(void)
{
	u8 key,a=0;
	HAL_Init();                     //��ʼ��HAL��   
	Stm32_Clock_Init(360,25,2,8);   //����ʱ��,180Mhz
	delay_init(180);                //��ʼ����ʱ����
	uart_init(115200);              //��ʼ��USART
	usart3_init(115200);  						//��ʼ������3������Ϊ115200
	LED_Init();                     //��ʼ��LED 
	KEY_Init();                     //��ʼ������
	SDRAM_Init();                   //��ʼ��SDRAM
	RTC_Init();											//RTCʱ�ӳ�ʼ��
	LCD_Init();                     //��ʼ��LCD
	TIM3_Init(999,89);							//��ʱ����ʼ��(1ms�ж�),���ڸ�lvgl�ṩ��������
	TIM4_CH1_Cap_Init(0XFFFFFFFF,90-1); //��1MHZ��Ƶ�ʼ���	
	trig_init();
	duoji_init(200-1,9000-1);
		
	if(lcdltdc.pwidth!=0)		
		LCD_Display_Dir(1);						//�����RGB���Ļ�,��ǿ������Ϊ������ʾ
	tp_dev.init();				    			//��������ʼ�� 
	
	lv_init();											//lvglϵͳ��ʼ��
	lv_port_disp_init();						//lvgl��ʾ�ӿڳ�ʼ��,����lv_init()�ĺ���
	lv_port_indev_init();						//lvgl����ӿڳ�ʼ��,����lv_init()�ĺ���

/********************************/	
	RC522_Init();
	PcdReset ();
	M500PcdConfigISOType ( 'A' );/*���ù�����ʽ*/
/**********************************/
	test_start();
	while(1)
	{
		tp_dev.scan(0);
		lv_task_handler();
		time_count();   //计时
	}
}
