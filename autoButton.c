#define F_CPU 1200000UL
#include <avr/io.h>
#include <util/delay.h> // _delay_ms(время_в_мс) - команда задержки

// Вставка реализации базовых функций (и ASCII арт) из Core13 (core13_022_arduino_1_6)
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
//      Ресет PB5  1|    |8  Vcc
//    Выход 1 PB3  2|    |7  PB2 Выход 2
//  Доп. вход PB4  3|    |6  PB1 Светодиод
//            GND  4|    |5  PB0 Кнопка
//                  +----+

byte flag_work_mode = 0;
/*
0 - рабочий цикл
1 - настройка 1 выхода, времени высокого уровня.
2 - настройка 1 выхода, время задержки.
3 - настройка 2 выхода, время высокого уровня
4 - настройка 2 выхода, время задержки.
5 - отладка или что-то другое
*/

unsigned long time_delay_1 = 1000;
unsigned long time_work_1 = 1000; 
unsigned long time_delay_2 = 1000;
unsigned long time_work_2 = 1000; 

void output_set()
{
    
}

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
