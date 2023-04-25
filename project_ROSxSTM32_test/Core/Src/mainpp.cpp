#include "mainpp.h"
#include "ros.h"
#include "std_msgs/Int64.h"
#include "geometry_msgs/Twist.h"
#include "STM32Hardware.h"

int	count;
int run_inter = 0;
double Vx, Vy, W;

void callback(const geometry_msgs::Twist &msg)
{
	Vx = msg.linear.x;
	Vy = msg.linear.y;
	W = msg.angular.z;
}


geometry_msgs::Twist ins_vel;
ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", callback);
ros::Publisher pub("/ins_vel", &ins_vel);

/* UART Communication */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

static void MX_USART10_UART_Init(void)
{
  /* USER CODE BEGIN USART10_Init 0 */

  /* USER CODE END USART10_Init 0 */

  /* USER CODE BEGIN USART10_Init 1 */

  /* USER CODE END USART10_Init 1 */
  huart10.Instance = USART10;
  huart10.Init.BaudRate = 115200;
  huart10.Init.WordLength = UART_WORDLENGTH_8B;
  huart10.Init.StopBits = UART_STOPBITS_1;
  huart10.Init.Parity = UART_PARITY_NONE;
  huart10.Init.Mode = UART_MODE_TX_RX;
  huart10.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart10.Init.OverSampling = UART_OVERSAMPLING_16;
  huart10.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart10.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart10.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart10) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart10, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart10, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart10) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART10_Init 2 */

  /* USER CODE END USART10_Init 2 */
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(huart == &huart10){
// 		set velocity 0 before uart reinitialization
        Vx = 0.0;
        Vy = 0.0;
        W = 0.0;

		HAL_UART_DeInit(&huart10);
		MX_USART10_UART_Init();
		nh.getHardware()->init();
    }
}


//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//    nh.getHardware()->flush();
//}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    nh.getHardware()->reset_rbuf();
}
void setup(void)
{
    nh.initNode();
    nh.subscribe(sub);
}
void loop(void)
{
    nh.spinOnce();
}

void inter(){
    ins_vel.linear.x = Vx;
    ins_vel.linear.y = Vy;
    ins_vel.angular.z = W;

	pub.publish(&ins_vel);
	run_inter ++;
}
