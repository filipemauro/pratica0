#include<p18f45k20.h>


void delay(void);
void Inic_Regs(void);


void main(void)							// funcao main
{		
	char Port_D,Port_D1,Port_D2;
	
	int ch=1,a,b, k=200;
	

	Inic_Regs();
	while(1)
		{

			switch(ch)
				{
			
				case 1: Port_D = 0b00000001;
						//Port_D2 = 0b01000000;
						//Port_D = Port_D1;// | Port_D2;
						PORTD=Port_D;
			
						while(1)							// loop infinito
							{
			
								delay();
									
								Port_D = Port_D<<1;	
								//Port_D2 = Port_D2>>1;
			
								if(Port_D==0b00000000)
									{
					
										Port_D=0b00000001;
																				
									}
				
								//Port_D = Port_D1;// | Port_D2;			
								//if(PORTBbits.RB0==0){
									while(PORTBbits.RB0==0)
									{
										k--;
										if(k==0){
											ch=ch+1;
												
										}
									//}	
									/*if(PORTBbits.RB0==0)
									{
										ch=ch+1;
										Port_D=0b10000000;
										
										break;
									}*/
									}
													//}
								PORTD = Port_D;
							}
							break;
			
				case 2: Port_D=0b10000000;
						//Port_D2=0b1000000;
						Port_D = Port_D;// | Port_D2;
						PORTD=Port_D;
			
						while(1)							// loop infinito
							{
			
								delay();
															
								Port_D = Port_D>>1;
								//Port_D2 = Port_D2<<1;	
			
								/*if(Port_D==0b10000001)
									{
					
										ch=1;
										break;
													
									}*/
									if(PORTBbits.RB0==0)
									{
										ch=ch--;
										Port_D=0b00000001;
										if(ch==2)
										{
											ch=1;
										}
										break;
									}

								//Port_D = Port_D | Port_D2;	
								PORTD = Port_D;
					
							}
							break;
				}
		}
}


	


void Inic_Regs(void)
{	
	
	TRISA = 0x02;	    	// pino RA1 entrada e os demais pinos da PORTA saida
	TRISB = 0x02;    	// PORTB saida
	//TRISC = 0x00;	    	// PORTC saida
	TRISD = 0x00;	    	// PORTD saida
	//TRISE = 0x00;		    // PORTE saida

	ADCON1= 0x0F;
	
	PORTA = 0;				//limpa PORTA
	//PORTB = 0;				// ''
	//PORTC = 0;				// ''
	PORTD = 0b11111111;			// ''
	//PORTE = 0;				// ''
	//LATD = 0b11111111;
}

void delay(void) 
{
	int a,b;

	for(a=0;a<=100;a++) 
		{	
		for(b=0;b<=1000;b++);
		}

}

