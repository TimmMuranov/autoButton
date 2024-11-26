#include <avr/io.h>
// Вставка реализации базовых функций из Core13 (core13_022_arduino_1_6)
void digitalWrite(uint8_t pin, uint8_t val){
    if(pin > 5 || pin < 0){return;}
    if(pin<2){turnOffPWM(pin);} //If its a PWM pin, make sure the PWM is off
    if(!val){
        PORTB &= ~_BV(pin);
    } else {
        PORTB |= _BV(pin);
    }
}

uint8_t digitalRead(uint8_t pin){
    if(pin > 5 || pin < 0){return 0;}
    if(pin < 2) turnOffPWM(pin); //If its PWM pin, makes sure the PWM is off
    return !!(PINB & _BV(pin));
}

uint8_t pinMode(uint8_t pin, char state) // i - INPUT, o - OUTPUT 
{
   if(pin > 5 || pin < 0) return 1;
   if(state == "i") DDRB &= ~(1 << PB(pin));
   else if(state == "o") DDRB |= (1 << PB(pin));
   else return 2;
}

int main(void)
{
    while(1)
    {
       
    }
}
