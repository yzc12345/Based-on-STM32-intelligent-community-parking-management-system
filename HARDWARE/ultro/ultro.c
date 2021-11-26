#include "ultro.h"
#include "led.h"							  
#include "delay.h"
#include "duoji.h"

TIM_HandleTypeDef TIM4_Handler;         //��ʱ��5���


//��ʱ��5ͨ��1���벶������
//arr���Զ���װֵ(TIM2,TIM5��32λ��!!)
//psc��ʱ��Ԥ��Ƶ��
void TIM4_CH1_Cap_Init(u32 arr,u16 psc)
{  
    TIM_IC_InitTypeDef TIM4_CH1Config;  
    
    TIM4_Handler.Instance=TIM4;                          //ͨ�ö�ʱ��5
    TIM4_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
    TIM4_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
    TIM4_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
    TIM4_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
    HAL_TIM_IC_Init(&TIM4_Handler);//��ʼ�����벶��ʱ������
    
    TIM4_CH1Config.ICPolarity=TIM_ICPOLARITY_RISING;    //�����ز���
    TIM4_CH1Config.ICSelection=TIM_ICSELECTION_DIRECTTI;//ӳ�䵽TI1��
    TIM4_CH1Config.ICPrescaler=TIM_ICPSC_DIV1;          //���������Ƶ������Ƶ
    TIM4_CH1Config.ICFilter=0;                          //���������˲��������˲�
    HAL_TIM_IC_ConfigChannel(&TIM4_Handler,&TIM4_CH1Config,TIM_CHANNEL_1);//����TIM5ͨ��1
	
    HAL_TIM_IC_Start_IT(&TIM4_Handler,TIM_CHANNEL_1);   //����TIM5�Ĳ���ͨ��1�����ҿ��������ж�
    __HAL_TIM_ENABLE_IT(&TIM4_Handler,TIM_IT_UPDATE);   //ʹ�ܸ����ж�
}


//��ʱ��5�ײ�������ʱ��ʹ�ܣ���������
//�˺����ᱻHAL_TIM_IC_Init()����
//htim:��ʱ��5���
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_TIM4_CLK_ENABLE();            //ʹ��TIM5ʱ��
    __HAL_RCC_GPIOB_CLK_ENABLE();			//����GPIOAʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_6;            //PA0
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;      //�����������
    GPIO_Initure.Pull=GPIO_PULLDOWN;        //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    GPIO_Initure.Alternate=GPIO_AF2_TIM4;   //PA0����ΪTIM5ͨ��1
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

    HAL_NVIC_SetPriority(TIM4_IRQn,2,0);    //�����ж����ȼ�����ռ���ȼ�2�������ȼ�0
    HAL_NVIC_EnableIRQ(TIM4_IRQn);          //����ITM5�ж�ͨ��  
}


//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)
u8  TIM4CH1_CAPTURE_STA=0;	//���벶��״̬		    				
u32	TIM4CH1_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)


//��ʱ��5�жϷ�����
void TIM4_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM4_Handler);//��ʱ�����ô�����
}
 

////��ʱ�������жϣ�����������жϴ���ص������� �ú�����HAL_TIM_IRQHandler�лᱻ����
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//�����жϣ����������ʱִ��
//{
//	
//	if((TIM4CH1_CAPTURE_STA&0X80)==0)//��δ�ɹ�����
//	{
//			if(TIM4CH1_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
//			{
//				if((TIM4CH1_CAPTURE_STA&0X3F)==0X3F)//�ߵ�ƽ̫����
//				{
//					TIM4CH1_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
//					TIM4CH1_CAPTURE_VAL=0XFFFFFFFF;
//				}else TIM4CH1_CAPTURE_STA++;
//			}	 
//	}		
//}


//��ʱ�����벶���жϴ���ص��������ú�����HAL_TIM_IRQHandler�лᱻ����
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)//�����жϷ���ʱִ��
{
	if((TIM4CH1_CAPTURE_STA&0X80)==0)//��δ�ɹ�����
	{
		if(TIM4CH1_CAPTURE_STA&0X40)		//����һ���½��� 		
			{	  			
				TIM4CH1_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
                TIM4CH1_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(&TIM4_Handler,TIM_CHANNEL_1);//��ȡ��ǰ�Ĳ���ֵ.
                TIM_RESET_CAPTUREPOLARITY(&TIM4_Handler,TIM_CHANNEL_1);   //һ��Ҫ�����ԭ�������ã���
                TIM_SET_CAPTUREPOLARITY(&TIM4_Handler,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);//����TIM5ͨ��1�����ز���
			}else  								//��δ��ʼ,��һ�β���������
			{
				TIM4CH1_CAPTURE_STA=0;			//���
				TIM4CH1_CAPTURE_VAL=0;
				TIM4CH1_CAPTURE_STA|=0X40;		//��ǲ�����������
				__HAL_TIM_DISABLE(&TIM4_Handler);        //�رն�ʱ��5
				__HAL_TIM_SET_COUNTER(&TIM4_Handler,0);
				TIM_RESET_CAPTUREPOLARITY(&TIM4_Handler,TIM_CHANNEL_1);   //һ��Ҫ�����ԭ�������ã���
				TIM_SET_CAPTUREPOLARITY(&TIM4_Handler,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);//��ʱ��5ͨ��1����Ϊ�½��ز���
				__HAL_TIM_ENABLE(&TIM4_Handler);//ʹ�ܶ�ʱ��5
			}		    
	}		
	
}

//����  ��������ģ��ĳ�ʼ��	
void trig_init(void)
{
   GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOA_CLK_ENABLE();           //����GPIOAʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_5; //PD3
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //�������
    GPIO_Initure.Pull=GPIO_PULLDOWN;          //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
	
    trig_pin=0;
}


void trig(void)
{
	trig_pin=1;
	delay_us(40);
	trig_pin=0;
}

u8 date_set(u32 date)  //ȡ20������ ��С�������� ȥ����С���ֵ ��ƽ��ֵ
{
	u8 s[size],i,j,t;
	float sum=0.0;
	for(i=0;i<size;i++)
	{
		s[i]=date;
		delay_ms(1);
	}
	for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(s[i]>s[j]) // ��С����
				{
					t=s[i];
					s[i]=s[j];
					s[j]=t;
				}
			}
		}
	for(i=2;i<18;i++) // ȥ�����ֵ��Сֵ
		{
			sum+=s[i];
		}
	return sum/16;  // ƽ��ֵ
}

void Ultro_decide(void)
{
	long long temp=0;
	u32 distance_1;
	trig();
	if(TIM4CH1_CAPTURE_STA&0X80)        //�ɹ�������һ�θߵ�ƽ
	{
		temp=TIM4CH1_CAPTURE_STA&0X3F; 
		temp*=0XFFFFFFFF;		 	    //���ʱ���ܺ�
		temp+=TIM4CH1_CAPTURE_VAL;      //�õ��ܵĸߵ�ƽʱ��
		temp=temp*0.017;
		//printf("HIGH:%lld cm\r\n",temp);//��ӡ�ܵĸߵ�ƽʱ��
		delay_ms(300);
		TIM4CH1_CAPTURE_STA=0;          //������һ�β���0
		//distance_1=date_set(temp);
		printf("�������������ľ���Ϊ%lld\n\t",temp);
		printf("\r\n");
		if(temp>20)
		{
			//LED0=1;
			TIM_SetTIM2Compare2(30);
		}		
		else
		{
			//LED0=0;
			TIM_SetTIM2Compare2(5);
		}
			
	}

}

