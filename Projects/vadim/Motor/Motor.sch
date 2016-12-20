v 20130925 2
C 41400 45900 1 0 0 dc_motor-1.sym
{
T 41800 46900 5 10 0 0 0 0 1
device=DC_MOTOR
T 41900 46500 5 10 1 1 0 0 1
refdes=Мотор передний
}
C 48300 45900 1 0 0 dc_motor-1.sym
{
T 48700 46900 5 10 0 0 0 0 1
device=DC_MOTOR
T 48800 46500 5 10 1 1 0 0 1
refdes=Мотор задний
}
C 44300 45100 1 0 0 L293.sym
{
T 46900 47675 5 10 0 0 0 0 1
device=L293
T 46700 47900 5 10 1 1 0 6 1
refdes=U?
}
C 50900 42400 1 0 0 arduino_uno_rev3.sym
{
T 57300 50500 5 10 1 1 0 6 1
refdes=.
T 51300 50700 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 51300 50900 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 50400 39400 1 0 0 pushbutton.sym
C 53100 39400 1 0 0 pushbutton.sym
C 56200 39400 1 0 0 pushbutton.sym
C 59100 39400 1 0 0 pushbutton.sym
C 39800 44100 1 0 0 BC547-1.sym
{
T 40700 44800 5 10 0 0 0 0 1
device=BC547
T 40700 44600 5 10 1 1 0 0 1
refdes=.
T 40600 44200 5 10 0 0 0 0 1
footprint=TO92
}
C 39800 49400 1 0 0 BC547-1.sym
{
T 40700 50100 5 10 0 0 0 0 1
device=BC547
T 40700 49900 5 10 1 1 0 0 1
refdes=.
T 40600 49500 5 10 0 0 0 0 1
footprint=TO92
}
C 46200 51800 1 0 0 5V-plus-1.sym
C 45500 51800 1 0 0 5V-minus-1.sym
C 37200 48700 1 0 0 resistor-2.sym
{
T 37600 49050 5 10 0 0 0 0 1
device=RESISTOR
T 37400 49000 5 10 1 1 0 0 1
refdes=220
}
C 37200 43200 1 0 0 resistor-2.sym
{
T 37600 43550 5 10 0 0 0 0 1
device=RESISTOR
T 37400 43500 5 10 1 1 0 0 1
refdes=220
}
C 51200 39400 1 0 0 resistor-2.sym
{
T 51600 39750 5 10 0 0 0 0 1
device=RESISTOR
T 51400 39700 5 10 1 1 0 0 1
refdes=220
}
C 53900 39400 1 0 0 resistor-2.sym
{
T 54300 39750 5 10 0 0 0 0 1
device=RESISTOR
T 54100 39700 5 10 1 1 0 0 1
refdes=220
}
C 57000 39400 1 0 0 resistor-2.sym
{
T 57400 39750 5 10 0 0 0 0 1
device=RESISTOR
T 57200 39700 5 10 1 1 0 0 1
refdes=220
}
C 59900 39400 1 0 0 resistor-2.sym
{
T 60300 39750 5 10 0 0 0 0 1
device=RESISTOR
T 60100 39700 5 10 1 1 0 0 1
refdes=220
}
C 38100 43100 1 0 0 glow-lamp-1.sym
{
T 38300 43700 5 10 0 0 0 0 1
device=GLOW_LAMP
T 38900 43500 5 10 1 1 0 0 1
refdes=Задняя лампа
T 38300 43900 5 10 0 0 0 0 1
symversion=0.1
}
C 38100 48600 1 0 0 glow-lamp-1.sym
{
T 38300 49200 5 10 0 0 0 0 1
device=GLOW_LAMP
T 38900 49000 5 10 1 1 0 0 1
refdes=Передняя лампа
T 38300 49400 5 10 0 0 0 0 1
symversion=0.1
}
N 44300 45400 43900 45400 4
N 43900 45400 43900 50200 4
N 43900 50200 46400 50200 4
N 46400 50200 46400 51800 4
N 44300 46600 43600 46600 4
N 43600 46600 43600 51800 4
N 37200 51800 45700 51800 4
N 47000 46600 47300 46600 4
N 47300 46600 47300 51000 4
N 47300 51000 45700 51000 4
N 45700 51000 45700 51800 4
N 47000 47500 49200 47500 4
N 49200 48400 51000 48400 4
N 49200 47500 49200 48400 4
N 47000 46300 47900 46300 4
N 50300 45400 50300 47600 4
N 50300 47600 51000 47600 4
N 44300 46300 43600 46300 4
N 43600 44600 43600 46300 4
N 43600 44600 47900 44600 4
N 47900 44600 47900 46300 4
N 47000 45700 47300 45700 4
N 47300 41800 47300 45700 4
N 47300 41800 58900 41800 4
N 58900 41800 58900 46000 4
N 58900 46000 57600 46000 4
N 47000 47200 48800 47200 4
N 48800 47200 48800 51400 4
N 48800 51400 58800 51400 4
N 58800 51400 58800 46400 4
N 58800 46400 57600 46400 4
N 47000 46900 48500 46900 4
N 47000 46000 48500 46000 4
N 48500 46000 48500 45900 4
N 47900 45400 50300 45400 4
N 44300 46900 41600 46900 4
N 41600 45900 44300 45900 4
N 44300 45900 44300 46000 4
N 44300 45700 44300 42300 4
N 44300 42300 58500 42300 4
N 58500 42300 58500 47200 4
N 58500 47200 57600 47200 4
N 44300 47200 44100 47200 4
N 44100 47200 44100 49000 4
N 44100 49000 50300 49000 4
N 50300 49000 50300 51000 4
N 50300 51000 58000 51000 4
N 58000 48000 58000 51000 4
N 58000 48000 57600 48000 4
N 50600 48400 50600 41000 4
N 50400 41000 59100 41000 4
N 59100 41000 59100 39500 4
N 57600 48800 60800 48800 4
N 60800 48800 60800 39500 4
N 59900 39500 59900 44000 4
N 59900 44000 57600 44000 4
N 57900 39500 58200 39500 4
N 58200 39500 58200 41300 4
N 52100 41300 60800 41300 4
N 57000 39500 57000 42000 4
N 57000 42000 59500 42000 4
N 59500 42000 59500 45200 4
N 59500 45200 57600 45200 4
N 56200 39500 56200 41000 4
N 53100 39500 53100 41000 4
N 50400 39500 50400 41000 4
N 54800 39500 54800 41300 4
N 52100 41300 52100 39500 4
N 51200 39500 51200 41600 4
N 51200 41600 60400 41600 4
N 60400 41600 60400 44800 4
N 60400 44800 57600 44800 4
N 53900 39500 53900 42000 4
N 53900 42000 61400 42000 4
N 61400 42000 61400 44400 4
N 61400 44400 57600 44400 4
N 37200 43300 37200 51800 4
N 39000 43300 40400 43300 4
N 40400 43300 40400 44100 4
N 40400 45100 40400 48300 4
N 40400 48300 43900 48300 4
N 39000 48800 40400 48800 4
N 40400 48800 40400 49400 4
N 40400 50400 40400 50500 4
N 40400 50500 46400 50500 4
N 47300 43800 39800 43800 4
N 39800 43800 39800 44600 4
N 48800 49300 39800 49300 4
N 39800 49300 39800 49900 4
