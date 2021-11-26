#include "timer.h"
#include "lvgl.h"
#include "rtc_time.h"
#include "rc522_config.h"
#include "rc522_function.h"
#include "table.h"
#include "tabview.h"
#include "login_win.h"
#include "led.h"
#include "ultro.h"
#include "duoji.h"
//#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F429开发板
//定时器中断驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2016/1/6
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	



TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!(定时器3挂在APB1上，时钟为HCLK/2)
void TIM3_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;                          //通用定时器3
    TIM3_Handler.Init.Prescaler=psc;                     //分频系数
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM3_Handler.Init.Period=arr;                        //自动装载值
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM3_Handler);
    
    HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   
}


//定时器底册驱动，开启时钟，设置中断优先级
//此函数会被HAL_TIM_Base_Init()函数调用
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
   if(htim->Instance==TIM3)
		{
			__HAL_RCC_TIM3_CLK_ENABLE();            //使能TIM3时钟
			HAL_NVIC_SetPriority(TIM3_IRQn,1,3);    //设置中断优先级，抢占优先级1，子优先级3
			HAL_NVIC_EnableIRQ(TIM3_IRQn);          //开启ITM3中断   
		}
	 if(htim->Instance==TIM7)
		{
			__HAL_RCC_TIM7_CLK_ENABLE();            //使能TIM7时钟
			HAL_NVIC_SetPriority(TIM7_IRQn,0,1);    //设置中断优先级，抢占优先级0，子优先级1
			HAL_NVIC_EnableIRQ(TIM7_IRQn);          //开启ITM7中断   
		}
}


//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

uint16_t i=0;
uint8_t time_flag=0;
//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM3_Handler))
    {
        lv_tick_inc(1);//lvgl的1ms心跳
				if(++i>1000)
				{
					i=0;
					time_flag=1;
				}
    }
		if(htim==(&TIM4_Handler))
		{
			if((TIM4CH1_CAPTURE_STA&0X80)==0)//还未成功捕获
			{
					if(TIM4CH1_CAPTURE_STA&0X40)//已经捕获到高电平了
					{
						if((TIM4CH1_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
						{
							TIM4CH1_CAPTURE_STA|=0X80;		//标记成功捕获了一次
							TIM4CH1_CAPTURE_VAL=0XFFFFFFFF;
						}else TIM4CH1_CAPTURE_STA++;
					}	 
			}	
		}
}


uint8_t KeyValue[]={0xFF ,0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // 卡A密钥
uint8_t ucArray_ID [ 4 ];    /*先后存放IC卡的类型和UID(IC卡序列号)*/   
void time_count(void)
{                                                                                     
	uint8_t ucStatusReturn;      /*返回状态*/  
	if(time_flag==1)
	{
		ucStatusReturn = PcdRequest ( PICC_REQALL, ucArray_ID ); //PICC_REQALL   PICC_REQIDL
		time_flag=0;
		Secondsute++;
		//printf("%d-%d-%d\t\n",Hours,Minutes,Secondsute);
		if(Secondsute>60)
		{
			Secondsute=0;
			Minutes++;
			if(Minutes>=60)
			{
				Minutes=0;
				Hours++;
				if(Hours>=24)
					Hours=0;
			}
		}
		ID_scan(ucStatusReturn);
		Ultro_decide();		
	}
}

void ID_scan(uint8_t ucStatusReturn)
{
	static u8 i=0,j=0;
	char buff[20];
	u8 t,flag=0;
	char cStr [ 30 ],c1[2];
	//uint8_t ucArray_ID [ 4 ]; 
	if ( ucStatusReturn == MI_OK  )
	{
		/*防冲撞（当有多张卡进入读写器操作范围时，防冲突机制会从其中选择一张进行操作）*/
		if ( PcdAnticoll ( ucArray_ID ) == MI_OK )                                                                   
		{			
			LED0=!LED0;
			PcdSelect(ucArray_ID);				
			PcdAuthState( PICC_AUTHENT1A, 0x11, KeyValue, ucArray_ID );//校验密码 
			sprintf ( cStr, "%02X%02X%02X%02X",ucArray_ID [0], ucArray_ID [1], ucArray_ID [2],ucArray_ID [3] );
			sprintf(buff,"%d:%d:%d",Hours,Minutes,Secondsute);
			for(t=0;t<TABLE_ROW_CNT-1;t++)
			{
				if(strstr(data_1[t].name,cStr)!=NULL)//相同
				{
					strcpy(data_1[t].time_out,buff);
					flag=0;
					break;
				}
				else
				{
					flag=1;
					//if(++i>4) i=1;
				}				
			}
			sprintf(c1,"%02d",j+1);	
		  if(flag)
			{
				strcpy(data_1[j].num,c1);
				strcpy(data_1[j].name,cStr);
				strcpy(data_1[j].time_into,buff);
				if(++j>=TABLE_ROW_CNT-1) j=0;
			}			
			//lv_obj_invalidate(table1); 
		}				
	}	
}


TIM_HandleTypeDef TIM7_Handler;      //定时器句柄 
extern vu16 USART3_RX_STA;

//基本定时器7中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM7_Int_Init(u16 arr,u16 psc)
{
		TIM7_Handler.Instance=TIM7;                          //通用定时器3
    TIM7_Handler.Init.Prescaler=psc;                     //分频系数
    TIM7_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM7_Handler.Init.Period=arr;                        //自动装载值
    TIM7_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM7_Handler);
    
    HAL_TIM_Base_Start_IT(&TIM7_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE									 
}
////定时器底册驱动，开启时钟，设置中断优先级
////此函数会被HAL_TIM_Base_Init()函数调用
//void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
//{
//    if(htim->Instance==TIM7)
//	{
//		__HAL_RCC_TIM7_CLK_ENABLE();            //使能TIM7时钟
//		HAL_NVIC_SetPriority(TIM7_IRQn,0,1);    //设置中断优先级，抢占优先级0，子优先级1
//		HAL_NVIC_EnableIRQ(TIM7_IRQn);          //开启ITM7中断   
//	}
//}
//定时器7中断服务程序		    
void TIM7_IRQHandler(void)
{ 	    		    
		USART3_RX_STA|=1<<15;	//标记接收完成
		__HAL_TIM_CLEAR_FLAG(&TIM7_Handler,TIM_EventSource_Update );       //清除TIM7更新中断标志  
		TIM7->CR1&=~(1<<0);     			//关闭定时器7     											 
} 





