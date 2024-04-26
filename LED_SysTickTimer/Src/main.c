#include "stm32f446xx.h"

void SysTickDelayms(int delay);

int main(void){

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER |= (1<<10);

	while(1){
		GPIOA->ODR ^= (1<<5);
		SysTickDelayms(100);
	}




}


void SysTickDelayms(int delay){
	SysTick->LOAD = 16000;
	SysTick->VAL = 0;
	SysTick->CTRL = (1<<0)|(1<<2);
	for(int i=0; i<delay;i++){
		while((SysTick->CTRL & (1<<16))==0){}
	}


}


