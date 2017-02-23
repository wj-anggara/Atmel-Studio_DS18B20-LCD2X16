/*
 * DS18B20_LCD.c
 *
 * Created: 22/02/2017 13:56:39
 * Author : Anggara Wijaya
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "ds18b20.h"
#include "lcd.h"

char printbuff[5];
double T;

int main(void)
{
	DDRD |= (1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);		//DATA port 4 bit
	
	lcd_init(LCD_DISP_ON);														//inisialisasi
	lcd_clrscr();																//Bersihkan layar
	lcd_gotoxy(0,0);
	lcd_puts("==== DS18B20 ===");												//tulis baris 1 dan geser ke bawah
	lcd_gotoxy(0,1);
	lcd_puts("Waiting...");														//tulis baris 2
	
	while (1)
	{
		T=ds18b20_gettemp();
		dtostrf(T, 5, 3, printbuff);
		lcd_clrscr();
		lcd_gotoxy(0,0);
		lcd_puts("==== DS18B20 ===");											//tulis baris 1 dan geser ke bawah
		lcd_gotoxy(0,1);
		lcd_puts(printbuff);													//tulis baris 2		
		_delay_ms(10);
	}
}