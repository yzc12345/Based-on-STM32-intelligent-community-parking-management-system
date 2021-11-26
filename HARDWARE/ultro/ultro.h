#ifndef __ULTRO_H
#define __ULTRO_H
#include "sys.h"

extern TIM_HandleTypeDef TIM4_Handler;      //定时器5句柄
extern u8  TIM4CH1_CAPTURE_STA;	//输入捕获状态		    				
extern u32	TIM4CH1_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)
void TIM4_CH1_Cap_Init(u32 arr,u16 psc);

#define trig_pin PAout(5)	// Trig
#define size 20
void trig_init(void);//初始化
void trig(void);
void Ultro_decide(void);
#endif

