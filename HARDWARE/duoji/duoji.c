#include "duoji.h"

TIM_HandleTypeDef TIM2_Handler;
TIM_OC_InitTypeDef TIM2_CH2_Handler;

//舵机初始化函数，这里使用到的是定时器3通道2输出PWM
void duoji_init(u16 arr,u16 psc)
{
    TIM2_Handler.Instance=TIM9;//选取通用定时器3
    TIM2_Handler.Init.Prescaler=psc;//定时器分频
    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//向上计数模式
    TIM2_Handler.Init.Period=arr;//自动重装载值
    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//
    HAL_TIM_PWM_Init(&TIM2_Handler);//初始化PWM配置
    
    TIM2_CH2_Handler.OCMode=TIM_OCMODE_PWM1;//选取模式1
    TIM2_CH2_Handler.Pulse=arr/2;//设置比较值，确定占空比
    TIM2_CH2_Handler.OCNPolarity=TIM_OCPOLARITY_LOW;//输出比较极性为低
    HAL_TIM_PWM_ConfigChannel(&TIM2_Handler,&TIM2_CH2_Handler,TIM_CHANNEL_1);//配置TIM3通道2
    HAL_TIM_PWM_Start(&TIM2_Handler,TIM_CHANNEL_1);//开启PWM通道2
}

//回调函数
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_TIM9_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    
    GPIO_Initure.Pin=GPIO_PIN_5;//PB5
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;//复用推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;//上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;//高速
    GPIO_Initure.Alternate=GPIO_AF3_TIM9;//复用为TIM3_CH2
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);//初始化GPIOB
}

//设置 TIM 通道 2 的占空比
//compare:比较值
void TIM_SetTIM2Compare2(u32 compare)
{
    TIM9->CCR1=compare;
}

//TIM_HandleTypeDef TIM2_Handler;
//TIM_OC_InitTypeDef TIM2_CH2_Handler;

////舵机初始化函数，这里使用到的是定时器3通道2输出PWM
//void duoji_init(u16 arr,u16 psc)
//{
//    TIM2_Handler.Instance=TIM4;//选取通用定时器3
//    TIM2_Handler.Init.Prescaler=psc;//定时器分频
//    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//向上计数模式
//    TIM2_Handler.Init.Period=arr;//自动重装载值
//    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//
//    HAL_TIM_PWM_Init(&TIM2_Handler);//初始化PWM配置
//    
//    TIM2_CH2_Handler.OCMode=TIM_OCMODE_PWM1;//选取模式1
//    TIM2_CH2_Handler.Pulse=arr/2;//设置比较值，确定占空比
//    TIM2_CH2_Handler.OCNPolarity=TIM_OCPOLARITY_LOW;//输出比较极性为低
//    HAL_TIM_PWM_ConfigChannel(&TIM2_Handler,&TIM2_CH2_Handler,TIM_CHANNEL_2);//配置TIM3通道2
//    HAL_TIM_PWM_Start(&TIM2_Handler,TIM_CHANNEL_2);//开启PWM通道2
//}

////回调函数
//void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
//{
//    GPIO_InitTypeDef GPIO_Initure;
//    __HAL_RCC_TIM4_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    
//    GPIO_Initure.Pin=GPIO_PIN_7;//PB5
//    GPIO_Initure.Mode=GPIO_MODE_AF_PP;//复用推挽输出
//    GPIO_Initure.Pull=GPIO_PULLUP;//上拉
//    GPIO_Initure.Speed=GPIO_SPEED_HIGH;//高速
//    GPIO_Initure.Alternate=GPIO_AF2_TIM4;//复用为TIM3_CH2
//    HAL_GPIO_Init(GPIOB,&GPIO_Initure);//初始化GPIOB
//}

////设置 TIM 通道 2 的占空比
////compare:比较值
//void TIM_SetTIM2Compare2(u32 compare)
//{
//    TIM4->CCR2=compare;
//}
