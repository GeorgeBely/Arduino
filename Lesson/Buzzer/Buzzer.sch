v 20130925 2
C 44700 40000 1 0 0 arduino_uno_rev3.sym
{
T 51100 48100 5 10 1 1 0 6 1
refdes=U?
T 45100 48300 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 45100 48500 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 54700 46200 1 0 0 led-1.sym
{
T 55500 46800 5 10 0 0 0 0 1
device=LED
T 55500 46600 5 10 1 1 0 0 1
refdes=LED
T 55500 47000 5 10 0 0 0 0 1
symversion=0.1
}
C 53200 46300 1 0 0 resistor-2.sym
{
T 53600 46650 5 10 0 0 0 0 1
device=RESISTOR
T 53400 46600 5 10 1 1 0 0 1
refdes=20кОМ
}
N 51400 46400 53200 46400 4
N 54100 46400 54700 46400 4
N 51400 46000 55600 46000 4
N 55600 46000 55600 46400 4
N 51400 42000 51900 42000 4
N 51900 42000 51900 42700 4
C 52500 42000 1 0 0 speaker-1.sym
{
T 53100 44000 5 10 1 1 0 0 1
refdes=Buzzer
T 52600 42800 5 10 1 1 0 0 1
+=+
}
N 52500 42700 51900 42700 4
N 52500 43900 52500 46400 4