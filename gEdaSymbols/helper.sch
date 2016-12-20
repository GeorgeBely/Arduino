v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 40300 50100 1 0 0 pot-bourns.sym
{
T 41100 51000 5 10 0 0 0 0 1
device=VARIABLE_RESISTOR
T 40900 50500 5 10 1 1 0 0 1
refdes=Потенциометр
}
C 40300 48800 1 0 0 led-1.sym
{
T 41100 49400 5 10 0 0 0 0 1
device=LED
T 41100 49200 5 10 1 1 0 0 1
refdes=Светодиод
T 41100 49600 5 10 0 0 0 0 1
symversion=0.1
}
C 40400 47700 1 0 0 pushbutton.sym
{
T 41000 48000 5 10 1 1 0 0 1
Имя=Кнопка
}
C 40400 46900 1 0 0 resistor-2.sym
{
T 40800 47250 5 10 0 0 0 0 1
device=RESISTOR
T 40600 47200 5 10 1 1 0 0 1
refdes=Резистор
}
C 49800 42400 1 0 0 arduino_uno_rev3.sym
{
T 56200 50500 5 10 1 1 0 6 1
refdes=Ардуино
T 50200 50700 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 50200 50900 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 40300 45500 1 0 0 BC547-1.sym
{
T 41200 46200 5 10 0 0 0 0 1
device=BC547
T 41200 46000 5 10 1 1 0 0 1
refdes=Транзистор
T 41100 45600 5 10 0 0 0 0 1
footprint=TO92
}
