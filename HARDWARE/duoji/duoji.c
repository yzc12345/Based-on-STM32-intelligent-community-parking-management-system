#include "duoji.h"

TIM_HandleTypeDef TIM2_Handler;
TIM_OC_InitTypeDef TIM2_CH2_Handler;

//�����ʼ������������ʹ�õ����Ƕ�ʱ��3ͨ��2���PWM
void duoji_init(u16 arr,u16 psc)
{
    TIM2_Handler.Instance=TIM9;//ѡȡͨ�ö�ʱ��3
    TIM2_Handler.Init.Prescaler=psc;//��ʱ����Ƶ
    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//���ϼ���ģʽ
    TIM2_Handler.Init.Period=arr;//�Զ���װ��ֵ
    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//
    HAL_TIM_PWM_Init(&TIM2_Handler);//��ʼ��PWM����
    
    TIM2_CH2_Handler.OCMode=TIM_OCMODE_PWM1;//ѡȡģʽ1
    TIM2_CH2_Handler.Pulse=arr/2;//���ñȽ�ֵ��ȷ��ռ�ձ�
    TIM2_CH2_Handler.OCNPolarity=TIM_OCPOLARITY_LOW;//����Ƚϼ���Ϊ��
    HAL_TIM_PWM_ConfigChannel(&TIM2_Handler,&TIM2_CH2_Handler,TIM_CHANNEL_1);//����TIM3ͨ��2
    HAL_TIM_PWM_Start(&TIM2_Handler,TIM_CHANNEL_1);//����PWMͨ��2
}

//�ص�����
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_TIM9_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    
    GPIO_Initure.Pin=GPIO_PIN_5;//PB5
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;//�����������
    GPIO_Initure.Pull=GPIO_PULLUP;//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;//����
    GPIO_Initure.Alternate=GPIO_AF3_TIM9;//����ΪTIM3_CH2
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);//��ʼ��GPIOB
}

//���� TIM ͨ�� 2 ��ռ�ձ�
//compare:�Ƚ�ֵ
void TIM_SetTIM2Compare2(u32 compare)
{
    TIM9->CCR1=compare;
}

//TIM_HandleTypeDef TIM2_Handler;
//TIM_OC_InitTypeDef TIM2_CH2_Handler;

////�����ʼ������������ʹ�õ����Ƕ�ʱ��3ͨ��2���PWM
//void duoji_init(u16 arr,u16 psc)
//{
//    TIM2_Handler.Instance=TIM4;//ѡȡͨ�ö�ʱ��3
//    TIM2_Handler.Init.Prescaler=psc;//��ʱ����Ƶ
//    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//���ϼ���ģʽ
//    TIM2_Handler.Init.Period=arr;//�Զ���װ��ֵ
//    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//
//    HAL_TIM_PWM_Init(&TIM2_Handler);//��ʼ��PWM����
//    
//    TIM2_CH2_Handler.OCMode=TIM_OCMODE_PWM1;//ѡȡģʽ1
//    TIM2_CH2_Handler.Pulse=arr/2;//���ñȽ�ֵ��ȷ��ռ�ձ�
//    TIM2_CH2_Handler.OCNPolarity=TIM_OCPOLARITY_LOW;//����Ƚϼ���Ϊ��
//    HAL_TIM_PWM_ConfigChannel(&TIM2_Handler,&TIM2_CH2_Handler,TIM_CHANNEL_2);//����TIM3ͨ��2
//    HAL_TIM_PWM_Start(&TIM2_Handler,TIM_CHANNEL_2);//����PWMͨ��2
//}

////�ص�����
//void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
//{
//    GPIO_InitTypeDef GPIO_Initure;
//    __HAL_RCC_TIM4_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    
//    GPIO_Initure.Pin=GPIO_PIN_7;//PB5
//    GPIO_Initure.Mode=GPIO_MODE_AF_PP;//�����������
//    GPIO_Initure.Pull=GPIO_PULLUP;//����
//    GPIO_Initure.Speed=GPIO_SPEED_HIGH;//����
//    GPIO_Initure.Alternate=GPIO_AF2_TIM4;//����ΪTIM3_CH2
//    HAL_GPIO_Init(GPIOB,&GPIO_Initure);//��ʼ��GPIOB
//}

////���� TIM ͨ�� 2 ��ռ�ձ�
////compare:�Ƚ�ֵ
//void TIM_SetTIM2Compare2(u32 compare)
//{
//    TIM4->CCR2=compare;
//}
