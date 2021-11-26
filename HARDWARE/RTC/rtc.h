#ifndef _RTC_H_
#define _RTC_H_

#include "sys.h"

extern RTC_HandleTypeDef RTC_Handler;  //RTC���
    
u8 RTC_Init(void);              //RTC��ʼ��
HAL_StatusTypeDef RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm);      //RTCʱ������
HAL_StatusTypeDef RTC_Set_Date(u8 year,u8 month,u8 date,u8 week);	//RTC��������
#endif
