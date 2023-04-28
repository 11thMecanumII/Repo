#include "timing.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		interPub();
	}
//	if (htim->Instance == TIM5) {
//		Kpid[0].goalVel = Vy + Vx + (W * 0.152767);
//		Kpid[1].goalVel = Vy - Vx - (W * 0.152844);
//		Kpid[2].goalVel = Vy + Vx - (W * 0.152998);
//		Kpid[3].goalVel = Vy - Vx + (W * 0.154852);
//		Kpid[0].enc = __HAL_TIM_GetCounter(&htim23);
//		Kpid[1].enc = __HAL_TIM_GetCounter(&htim4) * -1;
//		Kpid[2].enc = __HAL_TIM_GetCounter(&htim24);
//		Kpid[3].enc = __HAL_TIM_GetCounter(&htim3);
//		__HAL_TIM_SetCounter(&htim24, 0);
//		__HAL_TIM_SetCounter(&htim23, 0);
//		__HAL_TIM_SetCounter(&htim3, 0);
//		__HAL_TIM_SetCounter(&htim4, 0);
//
//		for( int i = 0; i < 4; i ++){
//			pidCtrl(i);
//		}
//
//		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, Kpid[0].pulse);
//		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, Kpid[1].pulse);
//		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_2, Kpid[2].pulse);
//		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, Kpid[3].pulse);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
//		if (Kpid[0].u > 0)HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
//		else if (Kpid[0].u < 0)HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
//		if (Kpid[1].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
//		else if (Kpid[1].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
//		if (Kpid[2].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
//		else if (Kpid[2].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
//		if (Kpid[3].u > 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
//		else if (Kpid[3].u < 0)HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
//
//		rVy = 0.25 * ( Kpid[0].insVel + Kpid[1].insVel
//				+ Kpid[2].insVel + Kpid[3].insVel );
//		rVx = 0.25 * ( Kpid[0].insVel - Kpid[1].insVel
//				+ Kpid[2].insVel - Kpid[3].insVel );
//		rW = 0.25 * ( Kpid[0].insVel - Kpid[1].insVel
//				- Kpid[2].insVel + Kpid[3].insVel );
//	}
}
