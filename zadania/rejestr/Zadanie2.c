// prad DATA*0.000025
// napiecie DATA*0.00125

#include <Wire.h>
#define DevAddress 0x40
#define RejestrPradu 0x01
#define RejestrNapiecia 0x02

void setup()
{
    Wire.setSDA(0);
    Wire.setSCL(1);

    Wire.setClock(1000);
    Wire.begin();
}

int data1, data2;
float wynik, wynik2;

void loop()
{
    // PRAD
    Wire.beginTransmission(DevAddress);
    Wire.write(RejestrPradu);
    Wire.endTransmission();
    delay(100);

    Wire.requestFrom(DevAddress, 2, true);

    data1 = 0;
    data1 = Wire.read();

    data1 = (data1 << 8) | Wire.read();

    wynik = (float)data1 * 0.000025;
    Serial.print("Rejestr pradu: ");
    Serial.println(wynik, 5);
    delay(100);

    // NAPIECIE
    Wire.beginTransmission(DevAddress);
    Wire.write(RejestrNapiecia);
    Wire.endTransmission();
    delay(100);

    Wire.requestFrom(DevAddress, 2, true);

    data2 = 0;
    data2 = Wire.read();

    data2 = (data2 << 8) | Wire.read();

    wynik2 = (float)data2 * 0.00125;
    Serial.print("Rejestr napiecia: ");
    Serial.println(wynik2, 5);
    delay(100);
}