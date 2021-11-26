#ifndef _RTC_H_
#define _RTC_H_

#include "sys.h"

extern RTC_HandleTypeDef RTC_Handler;  //RTC句柄
    
u8 RTC_Init(void);              //RTC初始化
HAL_StatusTypeDef RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm);      //RTC时间设置
HAL_StatusTypeDef RTC_Set_Date(u8 year,u8 month,u8 date,u8 week);	//RTC日期设置
#endif
