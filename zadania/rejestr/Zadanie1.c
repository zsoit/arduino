// odczytanie rejestru urzadzenia

#include <Wire.h>
#define DevAddress 0x40

void setup()
{
    Wire.setSDA(0);
    Wire.setSCL(1);

    Wire.setClock(1000);
    Wire.begin();
}

int data;

void loop()
{
    Wire.beginTransmission(DevAddress);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);

    Wire.requestFrom(DevAddress, 2, true);

    data = 0;
    data = Wire.read();

    data = (data << 8) | Wire.read();

    Serial.print("rejestr: ");
    Serial.println(data);
    delay(100);
}