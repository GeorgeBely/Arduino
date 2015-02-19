#include <IRremote.h>

int RECV_PIN = 11;//choose pin 11 for receiver
int ledPin = 9;


boolean ledValue = false;
int ledLevel = 0;

IRrecv irrecv(RECV_PIN);
decode_results remoteValue;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  String value = getRemoteValue();
  if (value != "") {
    Serial.println(value);
    if (value == "on")
      ledValue = !ledValue;
    else if (value == "+") {
      if (ledLevel > 245)
        ledLevel = 255;
      else
        ledLevel = ledLevel + 10;
    } else if (value == "-") {
      if (ledLevel < 10)
        ledLevel = 0;
      else 
        ledLevel = ledLevel - 10;
    }
    Serial.println(ledValue);
    Serial.println(ledLevel);
  }
  
  if (ledValue) {
    analogWrite(ledPin, ledLevel);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

String getRemoteValue() {
  if (irrecv.decode(&remoteValue)) {
    String result = String(remoteValue.value, HEX);
    irrecv.resume();
    
    if (result == "ffffffff")
      return "";
    else if (result == "ffa25d")
      return "on";
    else if (result == "ffe21d")
      return "menu";
    else if (result == "ff22dd")
      return "test";
    else if (result == "ff02fd")
      return "+";
    else if (result == "ffc23d")
      return "back";
    else if (result == "ffe01f")
      return "previous";
    else if (result == "ffa857")
      return "play";
    else if (result == "ff906f")
      return "next";
    else if (result == "ff6897")
      return "0";
    else if (result == "ff9867")
      return "-";
    else if (result == "ffb04f")
      return "c";
    else if (result == "ff30cf")
      return "1";
    else if (result == "ff18e7")
      return "2";
    else if (result == "ff7a85")
      return "3";
    else if (result == "ff10ef")
      return "4";
    else if (result == "ff38c7")
      return "5";
    else if (result == "ff5aa5")
      return "6";
    else if (result == "ff42bd")
      return "7";
    else if (result == "ff4ab5")
      return "8";
    else if (result == "ff52ad")
      return "9";
    }
  return "";
}
