v 20130925 2
C 43600 47500 1 0 0 input-1.sym
{
T 43600 47800 5 10 0 0 0 0 1
device=INPUT
}
C 44600 47500 1 0 0 resistor-2.sym
{
T 45000 47850 5 10 0 0 0 0 1
device=RESISTOR
T 44900 47800 5 10 1 1 0 0 1
refdes=R
}
C 46300 45300 1 0 0 gnd-1.sym
C 46200 48200 1 0 0 vcc-1.sym
N 45500 47600 45700 47600 4
T 43700 47500 9 10 1 0 0 0 1
V
T 43800 47500 9 6 1 0 0 0 1
B
N 44600 47600 44400 47600 4
T 44200 48000 9 6 1 0 0 0 3
резистор ограничивает ток с 
контроллера, чтобы не допустить 
короткого замыкания на землю
C 46200 46700 1 270 0 switcap-vsrc-1.sym
{
T 46700 46600 5 10 0 0 270 0 1
device=SWITCAP-vsrc
T 46000 46200 5 10 1 1 0 0 1
refdes=U
}
T 45200 46400 9 6 1 0 0 0 2
устройство, которым 
хочется управлять.
N 46400 45600 46400 45800 4
N 46400 46700 46400 47000 4
C 43700 46100 1 0 0 gnd-1.sym
N 46400 47000 43800 47000 4
N 43800 47000 43800 46400 4
T 43900 46300 9 6 1 0 0 0 1
земля контроллера
T 45500 45500 9 6 1 0 0 0 1
внешняя земля
T 43500 47200 9 6 1 0 0 0 2
пин с контроллера,
управляющий транзистором
T 45600 48600 9 6 1 0 0 0 1
внешнее питание
C 45700 47000 1 0 0 Transistor.sym
{
T 46700 47800 5 8 0 0 0 0 1
device=BC182
T 46700 47500 5 8 0 0 0 0 1
value=BC182
T 46700 47900 5 8 0 0 0 0 1
footprint=TO92
}
