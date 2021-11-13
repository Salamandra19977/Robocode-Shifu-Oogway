String str;
byte redLed = 9;
byte greenLed = 10;
byte blueLed = 11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    str = Serial.readString();
    byte firstComaIndex = str.indexOf(',');
    byte secondComaIndex = str.indexOf(',', firstComaIndex + 1);

    String red = str.substring(0, firstComaIndex);
    String green = str.substring(firstComaIndex + 1, secondComaIndex);
    String blue = str.substring(secondComaIndex + 1);

    int r = red.toInt();
    int g = green.toInt();
    int b = blue.toInt();

    Serial.print(r);

    analogWrite(redLed, r);
    analogWrite(greenLed, g);
    analogWrite(blueLed, b);
    }
}
