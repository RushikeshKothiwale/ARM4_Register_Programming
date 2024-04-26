#include "stm32f446xx.h"


int main(void){

	RCC->AHB1ENR |= (1<<2);

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER |= (1<<10);

	GPIOA->MODER &= ~(1<<11);

	GPIOC->MODER |= 0;


	while(1){
		if((GPIOC->IDR & (1<<13))==0){
			GPIOA->ODR |= (1<<5);
		}else{
			GPIOA->ODR &= ~(1<<5);
		}
	}


}
