v 20130925 2
C 38900 42000 1 0 0 arduino_uno_rev3.sym
{
T 45300 50100 5 10 1 1 0 6 1
refdes=U?
T 39300 50300 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 39300 50500 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 46700 45800 1 0 0 Transistor.sym
{
T 47700 46600 5 8 0 0 0 0 1
device=BC182
T 47700 46400 5 10 1 1 0 0 1
refdes=BC547
T 47700 46300 5 8 0 0 0 0 1
value=BC182
T 47700 46700 5 8 0 0 0 0 1
footprint=TO92
}
C 47200 48000 1 0 0 12V-plus-1.sym
C 49000 48300 1 180 1 gnd-1.sym
C 47700 43900 1 0 0 led-1.sym
{
T 48500 44500 5 10 0 0 0 0 1
device=LED
T 48500 44300 5 10 1 1 0 0 1
refdes=LED
T 48500 44700 5 10 0 0 0 0 1
symversion=0.1
}
C 47300 45400 1 270 0 resistor-2.sym
{
T 47650 45000 5 10 0 0 270 0 1
device=RESISTOR
T 47600 45200 5 10 1 1 270 0 1
refdes=220 Ом
}
N 47400 48000 47400 47000 4
N 46700 46400 45600 46400 4
N 47400 45400 47400 45800 4
N 47400 44500 47400 44100 4
N 47400 44100 47700 44100 4
N 48600 44100 49100 44100 4
N 49100 44100 49100 48000 4
