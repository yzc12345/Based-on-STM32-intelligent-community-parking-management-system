#ifndef __ULTRO_H
#define __ULTRO_H
#include "sys.h"

extern TIM_HandleTypeDef TIM4_Handler;      //��ʱ��5���
extern u8  TIM4CH1_CAPTURE_STA;	//���벶��״̬		    				
extern u32	TIM4CH1_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)
void TIM4_CH1_Cap_Init(u32 arr,u16 psc);

#define trig_pin PAout(5)	// Trig
#define size 20
void trig_init(void);//��ʼ��
void trig(void);
void Ultro_decide(void);
#endif

