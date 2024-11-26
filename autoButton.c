#include <avr/io.h>
// Вставка реализации базовых функций из Core13 (core13_022_arduino_1_6)
void digitalWrite(uint8_t pin, uint8_t val){
    if(pin > 5 || pin < 0){return;}
    if(pin < 0){turnOffPWM(pin);}
    if(!val){
        PORTB &= ~_BV(pin);
    } else {
        PORTB |= _BV(pin);
    }
}

uint8_t digitalRead(uint8_t pin){
    if(pin > 5 || pin < 0){return 0;}
    if(pin < 0) turnOffPWM(pin);
    return !!(PINB & _BV(pin));
}

// Эту писал сам ;)
uint8_t pinMode(uint8_t pin, char state) // i - INPUT, o - OUTPUT 
{
   if(pin > 5 || pin < 0) {return 1;}
   if(state == "i") {DDRB &= ~(1 << PB(pin));}
   else if(state == "o") {DDRB |= (1 << PB(pin));}
   else {return 2;}
}
/////////////////////////////////////////////////////////

// ATMEL ATTINY13 - ARDUINO
//
//                  +-\/-+
//            PB5  1|    |8  Vcc
//    Выход 1 PB3  2|    |7  PB2 Выход 2
//       Вход PB4  3|    |6  PB1 Светодиод
//            GND  4|    |5  PB0 Кнопка
//                  +----+

int main(void)
{
    pinMode(3, "o");
    pinMode(2, "o");
    pinMode(1, "o");
    
    while(1)
    {
       //основной цикл
    }
}
