#include "stm32f446xx.h"



int main(void){

	RCC->AHB1ENR |= (1<<0); // Enable the clock for GPIOA

	GPIOA->MODER |= (1<<10); // Setting PA5 pin as output mode

	GPIOA->MODER &= ~(1<<11);

	RCC->APB2ENR |= (1<<0); // Enable the clock for timer 1

	TIM1->PSC = 1999+1;
	TIM1->ARR = 7999+1;

	TIM1->CR1 |= (1<<0);

	while(1){

		while(!(TIM1->SR & (1<<0))){}
		TIM1->SR &= ~(1<<0);
		GPIOA->ODR ^= (1<<5);
	}




}

