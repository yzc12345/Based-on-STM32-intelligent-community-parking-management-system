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

//注:对于littleVGL库,最好不要采用-O的优化,保持为-O0不优化就可以了

#define TEST_NUM		1   //1,2,3分别对应三个演示例程


int main(void)
{
	u8 key,a=0;
	HAL_Init();                     //初始化HAL库   
	Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
	delay_init(180);                //初始化延时函数
	uart_init(115200);              //初始化USART
	usart3_init(115200);  						//初始化串口3波特率为115200
	LED_Init();                     //初始化LED 
	KEY_Init();                     //初始化按键
	SDRAM_Init();                   //初始化SDRAM
	RTC_Init();											//RTC时钟初始化
	LCD_Init();                     //初始化LCD
	TIM3_Init(999,89);							//定时器初始化(1ms中断),用于给lvgl提供心跳节拍
	TIM4_CH1_Cap_Init(0XFFFFFFFF,90-1); //以1MHZ的频率计数	
	trig_init();
	duoji_init(200-1,9000-1);
		
	if(lcdltdc.pwidth!=0)		
		LCD_Display_Dir(1);						//如果是RGB屏的话,则强制设置为横屏显示
	tp_dev.init();				    			//触摸屏初始化 
	
	lv_init();											//lvgl系统初始化
	lv_port_disp_init();						//lvgl显示接口初始化,放在lv_init()的后面
	lv_port_indev_init();						//lvgl输入接口初始化,放在lv_init()的后面

/********************************/	
	RC522_Init();
	PcdReset ();
	M500PcdConfigISOType ( 'A' );/*设置工作方式*/
/**********************************/
	test_start();
	while(1)
	{
		tp_dev.scan(0);
		lv_task_handler();
		time_count();   //璁℃椂
	}
}
