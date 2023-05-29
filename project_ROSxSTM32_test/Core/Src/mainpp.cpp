#include "mainpp.h"
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include "STM32Hardware.h"

ros::NodeHandle nh;
int run_inter0 = 0, run_inter1 = 0;
double Vx, Vy, W, rVx, rVy, rW;
double WX, WY, WW;
geometry_msgs::Twist insVel;
ros::Publisher pub("/ins_vel", &insVel);
int timeout = 0;

void callback(const geometry_msgs::Twist &msg)
{
//	Vx = vel_World2Car('x', msg.linear.x, msg.linear.y);
//	Vy = vel_World2Car('y', msg.linear.x, msg.linear.y);
//	W = msg.angular.z;
	WX = msg.linear.x;
	WY = msg.linear.y;
	WW = msg.angular.z;
	Vx = vel_World2Car('x', WX, WY);
	Vy = vel_World2Car('y', WX, WY);
	W = WW;

}
void interPub(void){
	insVel.linear.x = rVx;
	insVel.linear.y = rVy;
	insVel.angular.z = rW;
	insVel.angular.x = odom.x;
	insVel.angular.y = odom.y;
	insVel.linear.z = odom.theta;
	run_inter0 ++;

	if(run_inter0 > 1)
		pub.publish(&insVel);

	run_inter1 ++;
}
void stop(void){
	Vx = 0;
	Vy = 0;
	W = 0;
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", callback);

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


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    nh.getHardware()->flush();
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    nh.getHardware()->reset_rbuf();
}
void setup(void)
{
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub);

    odom.x = 0;		odom.y = 0;		odom.theta = (double)PI/2;

//    W = 10 * 2 * PI / 180;
}
void loop(void)
{
    if(!nh.spinOnce()){
//    	timeout ++;
    }
//    else timeout = 0;
//    if(timeout > 100000){
//    	stop();
//    	timeout = 0;
//    }
//    Vx = vel_World2Car('x', WX, WY);
//	Vy = vel_World2Car('y', WX, WY);
}

