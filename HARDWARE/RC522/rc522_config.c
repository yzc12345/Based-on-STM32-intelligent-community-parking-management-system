#include "rc522_config.h"
#include "stm32f4xx.h"
#include "sys.h"


static void   RC522_SPI_Config  ( void );

/**
  * @brief  RC522初始化
  * @param  无
  * @retval 无
  */
void RC522_Init ( void )
{
	RC522_SPI_Config ();
	
	RC522_Reset_Disable();

	RC522_CS_Disable();

}

/**
  * @brief  SPI配置
  * @param  无
  * @retval 无
  */
static void RC522_SPI_Config ( void )
{
  /* SPI_InitTypeDef  SPI_InitStructure */
  GPIO_InitTypeDef GPIO_InitStructure;
  
	//RC522_GPIO_CS_CLK_FUN (RC522_GPIO_CS_CLK, ENABLE );
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStructure.Pin=GPIO_PIN_12;
	GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_InitStructure.Pin=GPIO_PIN_6;
	GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStructure.Pin=GPIO_PIN_13;
	GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	__HAL_RCC_GPIOB_CLK_ENABLE();	
	GPIO_InitStructure.Pin=GPIO_PIN_15;
	GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStructure.Pin=GPIO_PIN_14;
	GPIO_InitStructure.Mode=GPIO_MODE_INPUT;
	GPIO_InitStructure.Speed=GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
	

}


