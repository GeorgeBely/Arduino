v 20130925 2
C 40100 43200 1 0 0 arduino_uno_rev3.sym
{
T 46500 51300 5 10 1 1 0 6 1
refdes=U?
T 40500 51500 5 10 0 0 0 0 1
device=ARDUINO UNO R3
T 40500 51700 5 10 0 0 0 0 1
footprint=arduino_uno_rev3_fpt
}
C 47900 45100 1 0 0 relay-5pin.sym
{
T 48600 47250 5 10 0 1 0 0 1
device=RELAY
T 49700 46950 5 10 1 1 0 0 1
refdes=U?
}
C 47600 47900 1 0 0 BC547-1.sym
{
T 48500 48600 5 10 0 0 0 0 1
device=BC547
T 48500 48400 5 10 1 1 0 0 1
refdes=.
T 48400 48000 5 10 0 0 0 0 1
footprint=TO92
}
C 50500 44700 1 0 0 switch-pushbutton-no-1.sym
{
T 50900 45000 5 10 1 1 0 0 1
refdes=Комнатный выключатель
T 50900 45300 5 10 0 0 0 0 1
device=SWITCH_PUSHBUTTON_NO
}
N 48200 47900 48200 47100 4
N 40200 49200 39900 49200 4
N 39900 49200 39900 51900 4
N 39900 51900 48200 51900 4
N 48200 51900 48200 48900 4
N 40200 48400 39900 48400 4
N 39900 48400 39900 42600 4
N 39900 42600 48200 42600 4
N 48200 42600 48200 45100 4
T 50300 48400 9 10 1 0 0 0 1
Свет в комнате
B 50200 48100 1600 700 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
C 53000 49200 1 0 0 gnd-1.sym
C 52900 47900 1 0 0 vcc-1.sym
N 47600 48400 46800 48400 4
C 50800 47900 1 0 0 vcc-1.sym
C 50700 48600 1 0 0 vcc-minus-1.sym
N 51000 49200 51000 49500 4
N 51000 49500 53100 49500 4
N 49000 47900 51000 47900 4
N 49000 47900 49000 47100 4
N 53100 47900 53100 44700 4
N 53100 44700 51500 44700 4
N 50500 44700 49400 44700 4
N 49400 44700 49400 45100 4
T 53400 48100 9 10 1 0 0 0 1
Ток менее 240 вольт