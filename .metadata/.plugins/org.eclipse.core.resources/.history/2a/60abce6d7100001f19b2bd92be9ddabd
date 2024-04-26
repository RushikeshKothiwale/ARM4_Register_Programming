#include "stm32f446xx.h"


int main(void){

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER |= (1<<10);

	GPIOA->MODER &= ~(1<<11);


	while(1){

		GPIOA->ODR |= (1<<5);
		for(int i=0; i<1000000; i++){}
		GPIOA->ODR &= ~(1<<5);
		for(int i=0; i<1000000; i++){}
	}


}
