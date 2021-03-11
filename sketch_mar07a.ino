#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned volatile FLAG=0;
ISR(INT0_vect)
{
  FLAG=1;
}
int main(void)
{
  DDRB|=(1<<PB0);

 
  DDRD&=~(1<<PD2);
  PORTD|=(1<<PD2);

  EICRA |= (1<<ISC00);
  EIMSK |= (1<<INT0);
  sei();

 while(1)
  {
    if(FLAG==1)
    {
      PORTB|=(1<<PB0);
      _delay_ms(1000);
      FLAG=0;
    }
    else{
      PORTB&=~(1<<PB0);
      _delay_ms(1000);
    }
  }
  return 0;
}
