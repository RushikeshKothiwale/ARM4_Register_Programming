#include "stm32f446xx.h"


int main(void){

	unsigned char flag = 1;

	unsigned char count = 0;

	RCC->AHB1ENR |= (1<<2);

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER |= (1<<10);

	GPIOA->MODER &= ~(1<<11);

	GPIOC->MODER |= 0;


	while(1){
		if((GPIOC->IDR & (1<<13))==0){// Check if PC13 is pressed

			count++;

			if((count>50)&& flag){   //wait to avoid de-bouncing
				flag = 0;           // clear flag to indicate button is pressed
				count =0;
				GPIOA->ODR ^= (1<<5);
			}
		}else{
			count++;

			if(count>50){
				flag =1;           //set flag to indicate button is released
				count =0;
			}
		}
	}


}
