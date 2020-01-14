// Includes
#include "main.h"

// UART handler declaration
UART_HandleTypeDef UartHandle;
__IO ITStatus UartReady = RESET;

//Buffer used for transmission
//uint8_t aTxBuffer[] = " *** UART DMA for GlobalLogic *** ";

// Buffer used for reception
uint8_t aRxBuffer[RXBUFFERSIZE];

// Private function prototypes
void SystemClock_Config(void);
static void Error_Handler(void);

int main(void)
{
  HAL_Init();

  /* Configure the system clock to 72 MHz */
  SystemClock_Config();
  
	// Configure LED3, LED4, LED5, LED6, LED7, LED8, LED9 and LED10
	RCC -> AHBENR  |= 0x00200000;//GPIOE clock enable
	GPIOE -> MODER   |= 0x55550000;//PE8-15 output
	GPIOE -> OSPEEDR |= 0xFFFF0000;//PE8-15

  // Configure the UART peripheral
  // Put the USART peripheral in the Asynchronous mode (UART Mode)
  /* UART configured as follows:
      - Word Length = 8 Bits
      - Stop Bit = One Stop bit
      - Parity = None
      - BaudRate = 115200 baud
      - Hardware flow control disabled (RTS and CTS signals) */
  UartHandle.Instance        = USARTx;

  UartHandle.Init.BaudRate   = 115200;
  UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits   = UART_STOPBITS_1;
  UartHandle.Init.Parity     = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode       = UART_MODE_TX_RX;
  UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if(HAL_UART_DeInit(&UartHandle) != HAL_OK)
  {
    Error_Handler();
  }  
  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    Error_Handler();
  }
  
	// The board receives the message (20 bytes) and sends it back

	// Infinite loop
	while (1)
	{

		if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)
		{
			Error_Handler();
		}

		GPIOE -> BSRR = GPIO_BSRR_BS_8;
		while (UartReady != SET)
		{
		}
		GPIOE -> BSRR = GPIO_BSRR_BR_8;

		// Reset transmission flag
		UartReady = RESET;

		if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)aRxBuffer, TXBUFFERSIZE)!= HAL_OK)
		{
			Error_Handler();
		}

		GPIOE -> BSRR = GPIO_BSRR_BS_9;
		while (UartReady != SET)
		{
		}
		GPIOE -> BSRR = GPIO_BSRR_BR_9;

		// Reset transmission flag
		UartReady = RESET;

		if(HAL_UART_Receive_DMA(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)
		{
			Error_Handler();
		}

		GPIOE -> BSRR = GPIO_BSRR_BS_10;
		// Wait for the end of the transfer
		while (UartReady != SET)
		{
		}
		GPIOE -> BSRR = GPIO_BSRR_BR_10;

		// Reset transmission flag
		UartReady = RESET;

		// Start the transmission process
		// While the UART in reception process, user can transmit data through "aRxBuffer" buffer
		if(HAL_UART_Transmit_DMA(&UartHandle, (uint8_t*)aRxBuffer, TXBUFFERSIZE)!= HAL_OK)
		{
			Error_Handler();
		}

		GPIOE -> BSRR = GPIO_BSRR_BS_11;
		// Wait for the end of the transfer
		while (UartReady != SET)
		{
		}
		GPIOE -> BSRR = GPIO_BSRR_BR_11;

		// Reset transmission flag
		UartReady = RESET;
	}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV                     = 1
  *            PLLMUL                         = RCC_PLL_MUL9 (9)
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
    	
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
}

/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle. 
  * @note   This example shows a simple way to report end of DMA Tx transfer, and 
  *         you can add your own implementation. 
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	// Set transmission flag: transfer complete
	UartReady = SET;

}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and 
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	// Set transmission flag: transfer complete
	UartReady = SET;

}

/**
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *UartHandle)
{
	// Turn LED6 on: Transfer error in reception/transmission process
	GPIOE -> BSRR = GPIO_BSRR_BS_15;
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
	// Turn LED6 on
	GPIOE -> BSRR = GPIO_BSRR_BS_15;
	while(1)
	{
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
