v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 41300 42100 1 0 0 arduino_uno_rev3.sym
{
T 47700 50200 5 10 1 1 0 6 1
refdes=U?
T 41700 50400 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 41700 50600 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 53300 48400 1 0 0 led-1.sym
{
T 54100 49000 5 10 0 0 0 0 1
device=LED
T 54100 48800 5 10 1 1 0 0 1
refdes=LED
T 54100 49200 5 10 0 0 0 0 1
symversion=0.1
}
C 51100 48500 1 0 0 resistor-2.sym
{
T 51500 48850 5 10 0 0 0 0 1
device=RESISTOR
T 51300 48800 5 10 1 1 0 0 1
refdes=20кОМ
}
C 51000 44500 1 0 0 buzzer.sym
N 48000 48500 51100 48500 4
N 52000 48600 53300 48600 4
N 48000 48100 54200 48100 4
N 54200 48100 54200 48600 4
N 51100 48500 51100 48600 4
N 49900 44600 49900 48500 4
N 49900 44600 51100 44600 4
N 48000 44100 49100 44100 4
N 49100 44100 49100 45200 4
N 49100 45200 51100 45200 4
N 51100 45200 51100 45000 4