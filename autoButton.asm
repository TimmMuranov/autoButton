;--- Регистры портов ---
.equ DDRB, 0x17
.equ PORTB, 0x18
;-----------------------
.equ PB0, 0x00
.equ PB1, 0x01
.equ PB2, 0x02
;---- 0-я координата ---
.ORG 0x0000
;--- Настройка портов --
sbi DDRB, PB0
;-----------------------
