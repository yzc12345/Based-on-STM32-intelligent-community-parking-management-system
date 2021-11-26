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
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F429������
//��ʱ���ж���������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2016/1/6
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	



TIM_HandleTypeDef TIM3_Handler;      //��ʱ����� 

//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!(��ʱ��3����APB1�ϣ�ʱ��ΪHCLK/2)
void TIM3_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;                          //ͨ�ö�ʱ��3
    TIM3_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
    TIM3_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
    HAL_TIM_Base_Init(&TIM3_Handler);
    
    HAL_TIM_Base_Start_IT(&TIM3_Handler); //ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE   
}


//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻHAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
   if(htim->Instance==TIM3)
		{
			__HAL_RCC_TIM3_CLK_ENABLE();            //ʹ��TIM3ʱ��
			HAL_NVIC_SetPriority(TIM3_IRQn,1,3);    //�����ж����ȼ�����ռ���ȼ�1�������ȼ�3
			HAL_NVIC_EnableIRQ(TIM3_IRQn);          //����ITM3�ж�   
		}
	 if(htim->Instance==TIM7)
		{
			__HAL_RCC_TIM7_CLK_ENABLE();            //ʹ��TIM7ʱ��
			HAL_NVIC_SetPriority(TIM7_IRQn,0,1);    //�����ж����ȼ�����ռ���ȼ�0�������ȼ�1
			HAL_NVIC_EnableIRQ(TIM7_IRQn);          //����ITM7�ж�   
		}
}


//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

uint16_t i=0;
uint8_t time_flag=0;
//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM3_Handler))
    {
        lv_tick_inc(1);//lvgl��1ms����
				if(++i>1000)
				{
					i=0;
					time_flag=1;
				}
    }
		if(htim==(&TIM4_Handler))
		{
			if((TIM4CH1_CAPTURE_STA&0X80)==0)//��δ�ɹ�����
			{
					if(TIM4CH1_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
					{
						if((TIM4CH1_CAPTURE_STA&0X3F)==0X3F)//�ߵ�ƽ̫����
						{
							TIM4CH1_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
							TIM4CH1_CAPTURE_VAL=0XFFFFFFFF;
						}else TIM4CH1_CAPTURE_STA++;
					}	 
			}	
		}
}


uint8_t KeyValue[]={0xFF ,0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // ��A��Կ
uint8_t ucArray_ID [ 4 ];    /*�Ⱥ���IC�������ͺ�UID(IC�����к�)*/   
void time_count(void)
{                                                                                     
	uint8_t ucStatusReturn;      /*����״̬*/  
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
		/*����ײ�����ж��ſ������д��������Χʱ������ͻ���ƻ������ѡ��һ�Ž��в�����*/
		if ( PcdAnticoll ( ucArray_ID ) == MI_OK )                                                                   
		{			
			LED0=!LED0;
			PcdSelect(ucArray_ID);				
			PcdAuthState( PICC_AUTHENT1A, 0x11, KeyValue, ucArray_ID );//У������ 
			sprintf ( cStr, "%02X%02X%02X%02X",ucArray_ID [0], ucArray_ID [1], ucArray_ID [2],ucArray_ID [3] );
			sprintf(buff,"%d:%d:%d",Hours,Minutes,Secondsute);
			for(t=0;t<TABLE_ROW_CNT-1;t++)
			{
				if(strstr(data_1[t].name,cStr)!=NULL)//��ͬ
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


TIM_HandleTypeDef TIM7_Handler;      //��ʱ����� 
extern vu16 USART3_RX_STA;

//������ʱ��7�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM7_Int_Init(u16 arr,u16 psc)
{
		TIM7_Handler.Instance=TIM7;                          //ͨ�ö�ʱ��3
    TIM7_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
    TIM7_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
    TIM7_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
    TIM7_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
    HAL_TIM_Base_Init(&TIM7_Handler);
    
    HAL_TIM_Base_Start_IT(&TIM7_Handler); //ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE									 
}
////��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
////�˺����ᱻHAL_TIM_Base_Init()��������
//void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
//{
//    if(htim->Instance==TIM7)
//	{
//		__HAL_RCC_TIM7_CLK_ENABLE();            //ʹ��TIM7ʱ��
//		HAL_NVIC_SetPriority(TIM7_IRQn,0,1);    //�����ж����ȼ�����ռ���ȼ�0�������ȼ�1
//		HAL_NVIC_EnableIRQ(TIM7_IRQn);          //����ITM7�ж�   
//	}
//}
//��ʱ��7�жϷ������		    
void TIM7_IRQHandler(void)
{ 	    		    
		USART3_RX_STA|=1<<15;	//��ǽ������
		__HAL_TIM_CLEAR_FLAG(&TIM7_Handler,TIM_EventSource_Update );       //���TIM7�����жϱ�־  
		TIM7->CR1&=~(1<<0);     			//�رն�ʱ��7     											 
} 





