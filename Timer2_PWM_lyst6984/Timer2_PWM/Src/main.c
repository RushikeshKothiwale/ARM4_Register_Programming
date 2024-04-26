#include "stm32f446xx.h"

void delay();

int main(void){

	int duty_cycle = 100;
	int total_period = 1000;

	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<11);

	GPIOA->AFR[0] |= (1<<20);    // Select AF1 on PA5 Pin
	GPIOA->AFR[0] &= ~(1<<21);
	GPIOA->AFR[0] &= ~(1<<22);
	GPIOA->AFR[0] &= ~(1<<23);

	RCC->APB1ENR = (1<<0);
	TIM2->PSC = 16;

	TIM2->ARR = total_period;
	TIM2->CCR1 = duty_cycle;

	TIM2->CCER &= ~(1<<1);  	// set output polarity to active high

	TIM2->CCMR1 &= ~(1<<0);
	TIM2->CCMR1 &= ~(1<<1);

	TIM2->CCMR1 |= (1<<3);    // Enable corresponding Pre-load Register

	TIM2->CCMR1 &= ~(1<<4);   // Select PWM Mode1 for Timer2
	TIM2->CCMR1 |= (1<<5);
	TIM2->CCMR1 |= (1<<6);

	TIM2->CCER |= (1<<0);    // Enable Capture Compare
	TIM2->EGR |= (1<<0);     // Set UG-bit, re-initialize the counter
	TIM2->BDTR |= (1<<15);   // Enable MOE
	TIM2->CR1 |= (1<<0);     // Start Timer-2

	while(1){

		static uint8_t direction = 0;

		TIM2->CCR1 = duty_cycle;

		if(duty_cycle>total_period){
			direction = 1;
		}
		else if(duty_cycle == 100){
			direction = 0;
		}

		if(direction == 0){
			duty_cycle = duty_cycle + 10;
		}else{
			duty_cycle = duty_cycle - 10;
		}

		delay();
	}
}

void delay(){
	for(int i=0; i<10000;i++){}
}



