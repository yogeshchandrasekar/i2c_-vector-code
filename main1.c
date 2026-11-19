#include <LPC21xx.h>
#include "types.h"
#include "i2c.h"
#include "i2c_eeprom.h"
#include "delay.h"
#include <string.h>

//#define I2C_EEPROM_SA 0x50 //7Bit Slave Addr

#define gLED 1<<16 //P1.16
#define rLED 1<<17 //P1.17


int main()
{
	u8 ch;
	 init_i2c();
	 IODIR1=gLED|rLED;
	
	   i2c_eeprom_write(0X50,0x00,'A');
	   ch=i2c_eeprom_read(0X50,0x00);
	  delay_ms(100);
	 
	 if(ch=='A')
	 {
		 IOPIN1=gLED;
   }		
	 else
   {
		 IOPIN1=rLED;
   }
	 while(1);
}
