
# ARDUINO IDE
Raspberry Pi Pico W C/C++\
Emulator Online: https://wokwi.com/projects/new/pi-pico
# ZADANIA
<!-- SILNIK
- [Polecenia](zadania/powtorka/polecenia.md)
- [Zadanie 1](zadania/powtorka/zadanie1.c)
- [Zadanie 2](zadania/powtorka/zadanie1.c)

CZUJNIK
- [Polecenia](zadania/powtorka/polecenia.md)
- [Zadanie 1](zadania/powtorka/zadanie1.c)
- [Zadanie 2](zadania/powtorka/zadanie1.c) -->

PROTOKÓŁ 12C
- [Zadanie 1](zadania/rejestr/Zadanie1.c)
- [Zadanie 2](zadania/rejestr/Zadanie2.c)


POWTÓRKA
- [Polecenia](zadania/powtorka/polecenia.md)
- [Zadanie 1](zadania/powtorka/zadanie1.c)



# SPIS TREŚCI
1. [USTAWIENIA PINÓW](#1-ustawienie-pinów---pinmode)
2. [DIODY](#2-diody)
3. [PRZYCISK](#3-przycisk)
4. [SILNIK](#4-silnik)
5. [CZUJNIK MAX6675](#5-czujnik-max6675)
6. [OBSŁUGA PROTOKOŁU 12C](#6-obsługa-protokołu-12-c)



# POLECENIA

```c
// ustawienia pinow
#define DIODA 15
#define SILNIK 18

// void setup()
pinMode(DIODA,OUTPUT);

// void loop()
// DIODA/CZUJNIK
digitalWrite(DIODA,HIGH);
digitalWrite(DIODA,LOW);

// SILNIK
int predkosc = 120;
// od 0 do 250, przy 60 sie uruchamia
analogWrite(SILNIK,predkosc);

//opozninie milisekundy (1000 = 1sek)
delay(1000);

// SYSTEM MONITOR
Serial.print("TEMPERATURA - ");
Serial.println(TEMPERATURA);

```

## 1. Ustawienie PINÓW - pinMode()

###
```c
// ustawienia pinow
#define DIODA1 14
#define SILNIK 19
#define PRZYCISK 20

void setup()
{
    pinMode(DIODA1,OUTPUT);
    pinMode(SILNIK,OUTPUT);
    pinMode(PRZYCISK,INPUT);
}
```

## 2. DIODY


```c

#define DIODA1 14

void loop()
{
    // WŁĄCZONA
    digitalWrite(DIODA1,HIGH);

    // WYŁĄCZONA
    digitalWrite(DIODA1,LOW);
}
```

## 3. PRZYCISK

### Wykrycie wciśnięcia
```c
#define PRZYCISK 16
int a,b;
// setup ... pinMode(przycisk,INPUT)

void loop()
{
    a = 0;
    b = 0;

    if(digitalWrite(PRZYCISK)) a=1;
    else a=0;

    // WYKRYWA WCISNIECIE
    if((a==1) && (b==0))
    {
        // RESZTA KODU
    }
}


```

## 4. SILNIK
- void loop()

### Uruchomienie silnika - analogWrite(silnik,predkosc);

```c

#define SILNIK 18

// setup ... pinMode(silnik,OUTPUT)

void loop()
{
    int predkosc = 120;
    // od 0 do 250, przy 60 sie uruchamia

    analogWrite(SILNIK,predkosc);
}
```

## 5. CZUJNIK MAX6675

### ustawienia czujnika MAX6675
```c
#include <SPI.h>
SPISettings parSPI(10000000,MSBFIRST,SPI,MODE0);

#define CZUJNIK 20

double TEMPERATURA;

void setup()
{
    SPI.begin(true);
    Serial.begin(9600);
}

void loop()
{
    //CZUJNIK-POMIAR
    digitalWrite(CZUJNIK,HIGH);

    SPI.beginTransaction(parSPI);
    digitalWrite(CZUJNIK,LOW);

    uint16_t val = SPI.transfer16(0);
    digitalWrite(CZUJNIK,HIGH);

    // TEMPERATURA
    TEMPERATURA = ((val&0x7FFF)>>3)*0.25;
    Serial.print("TEMPERATURA - ");
    Serial.println(TEMPERATURA);
    //!TEMPERATURA

    SPI.endTransaction();
    //!CZUJNIK-POMIAR


    delay(250); //opozninie milisekundy
}


```


## 6. OBSŁUGA PROTOKOŁU 12C
```c

#define DevAddress 0x40
#define Rejestr 0x00 //0x4127
#define RejestrPradu 0x01 //1 bit to 25uA
#define RejestrNapiecia 0x02 //1 bit to 1.25mV

// delay(28) - opoznienie minimum 28s

void setup()
{
    // deklarcja pinow do komunikacji
    Wire.setSDA(PIN_1);
    Wire.setSDA(PIN_2);

    // deklaracja czestoliwosci komunikacji
    Wire.setClock(1000);
    // 1000-ilosc bitow na sekunde

    // uruchomienie modułu komunikacji
    Wire.begin();
}

void loop()
{
    // start komunikacji
    Wire.beginTransmission(DevAddress);

    // wyslanie danych na szyne
    Wire.write(0x00);

    // koniec komunikacji
    Wire.endTransmission();

    delay(100);

    // odczyt danych z szyny
    Wire.requestFrom(DevAddress, 2, true);
}
```