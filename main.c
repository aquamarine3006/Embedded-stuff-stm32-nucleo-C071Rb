

int main(void)
{
		char* RCC_IOPENR = (char*)(0x40021000U + 0x34U);
	
		//char o_RCC_IOPENR = *RCC_IOPENR;
		*(volatile unsigned char*)RCC_IOPENR |= 5;
		
		volatile unsigned char delay = *(volatile unsigned char*)RCC_IOPENR;
	
		char* GPIO_MODER_PA5 = (char*)(0x50000000U + 0x00U);
		char* GPIO_MODER_PC9 = (char*)(0x50000800U + 0x00U);
		//char o_GPIO_MODER = *GPIO_MODER;
		*((volatile unsigned char*)(GPIO_MODER_PA5+1)) = 4;
		*((volatile unsigned char*)(GPIO_MODER_PC9+2)) = 4;
		
		char* GPIO_BSRR_PA5 = (char*)(0x50000000U + 0x14U);
		char* GPIO_BSRR_PC9 = (char*)(0x50000800U + 0x14U);
		//char o_GPIO_BSRR = *GPIO_BSRR;
		//*(volatile unsigned char*)RCC_IOPENR = o_RCC_IOPENR;
		//*((volatile unsigned char*)(GPIO_MODER+1)) = o_GPIO_MODER;
		
		while(1){
				*((volatile unsigned char*)GPIO_BSRR_PA5) = 32;
				*((volatile unsigned char*)(GPIO_BSRR_PC9 + 1)) = 2;
				for(int i=0;i<100000;i++);
				*((volatile unsigned char*)GPIO_BSRR_PA5) = 0;
				*((volatile unsigned char*)(GPIO_BSRR_PC9 + 1)) = 0;
				for(int i=0;i<100000;i++);
		};
}