#include "stm32f446xx.h"

void USART2_init(void);

void USART2_write(int ch);

char USART2_read();

void Send_String(char *ch);

void Timer_Precise_Delay(int delay);

void USART2_init(void){
	RCC->AHB1ENR |= (1<<0);// Enable the clock for GPIOA for PA2_TX

	RCC->APB2ENR |= (1<<0);// Enable the clock for timer 1;

	TIM1->PSC = 3999+1;
	TIM1->ARR = 15999+1;

	TIM1->CR1 |= (1<<0);

	RCC->APB1ENR |= (1<<17); // Enable the clock for USART2

	GPIOA->AFR[0] |= (1<<8);
	GPIOA->AFR[0] |= (1<<9);
	GPIOA->AFR[0] |= (1<<10);

	GPIOA->AFR[0] |= (1<<12);
	GPIOA->AFR[0] |= (1<<13);
	GPIOA->AFR[0] |= (1<<14);

	GPIOA->MODER |= (1<<5);

	GPIOA->MODER |= (1<<7);

	USART2->BRR = 0x08b;

	USART2->CR1 |= (1<<3);
	USART2->CR1 |= (1<<2);
	USART2->CR1 |= (1<<13);
}


void USART2_write(int ch){
	while(!(USART2->SR & (1<<7))){}

	USART2->DR = (ch & 0xFF);
}

void Timer_Precise_Delay(int delay){

	while(!(TIM1->SR & (1<<0))){}
	TIM1->SR &= ~(1<<0);

}

char USART2_read(){
	while(!(USART2->SR & (1<<5))){}
	return USART2->DR;

}

void Send_String(char *ch){
	while(*ch != '\0'){
		USART2_write(*ch);
		ch++;
	}
}


int main(void){



	USART2_init();

	while(1){

		Send_String("ARM-CORTEX M4");
		USART2_write('\r');
		USART2_write('\n');
		Timer_Precise_Delay(1000);
	}
}
//		Timer_Precise_Delay(1000);






