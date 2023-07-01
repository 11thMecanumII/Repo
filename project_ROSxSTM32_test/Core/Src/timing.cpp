#include "timing.h"

#define cor_num_y 1.3
#define cor_num_x 18

int ccc = 0;
double coeffab = 0.5 * (width + length);
double angle = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		interPub();
	}
	if (htim->Instance == TIM5) {

		W += cor_num_y * Vy * 0.001;
		if (Vx < 0){
			W -= cor_num_x * Vx * 0.001;
		}

		Kpid[0].goalVel = Vy + Vx + (W * coeffab);
		Kpid[1].goalVel = Vy - Vx - (W * coeffab);
		Kpid[2].goalVel = Vy + Vx - (W * coeffab);
		Kpid[3].goalVel = Vy - Vx + (W * coeffab);

		Kpid[0].enc = __HAL_TIM_GetCounter(&htim23);
		Kpid[1].enc = __HAL_TIM_GetCounter(&htim4) * -1;
		Kpid[2].enc = __HAL_TIM_GetCounter(&htim24);
		Kpid[3].enc = __HAL_TIM_GetCounter(&htim3);
		__HAL_TIM_SetCounter(&htim24, 0);
		__HAL_TIM_SetCounter(&htim23, 0);
		__HAL_TIM_SetCounter(&htim3, 0);
		__HAL_TIM_SetCounter(&htim4, 0);

		for( int i = 0; i < 4; i ++){
			pidCtrl(i);
		}

		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, Kpid[0].pulse);
		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, Kpid[1].pulse);
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_2, Kpid[2].pulse);
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, Kpid[3].pulse);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
		if (Kpid[0].u > 0)HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		else if (Kpid[0].u < 0)HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		if (Kpid[1].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
		else if (Kpid[1].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
		if (Kpid[2].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
		else if (Kpid[2].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
		if (Kpid[3].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
		else if (Kpid[3].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);

		rVy = 0.25 * ( Kpid[0].insVel + Kpid[1].insVel
				+ Kpid[2].insVel + Kpid[3].insVel );
		rVx = 0.25 * ( Kpid[0].insVel - Kpid[1].insVel
				+ Kpid[2].insVel - Kpid[3].insVel );
		rW = (double)0.25 * ( Kpid[0].insVel - Kpid[1].insVel
				- Kpid[2].insVel + Kpid[3].insVel ) / coeffab;


		rW -= cor_num_y * Vy * 0.001;
		if (Vx < 0){
			rW += cor_num_x * Vx * 0.001;
		}

//		odom_update(vel_Car2World('x',rVx,rVy),vel_Car2World('y',rVx,rVy), rW);
	}
}
