
[def]: powtorka.c
# Owtórz plik [powtorka.c][def]

## Zaprogramować układ w taki sposób:

-  aby odczytywał temperaturę z czujnika MAX6675,
- a następnie na jej podstawie sterował prędkością silnika.

- Silnik ma się włączać, gdy temperatura przekroczy pewien próg.
Próg jest ustalany po wciśnięciu przycisku (jako bieżąca temperatura)

- Dodatkowo należy użyć diod LED do zwizualizowania poziomu temperatury.




# POLECENIA ARDUINO


## 1. VOID SETUP ()

### ustawienie PINU
```c
int dioda1 = 14;
int przycisk1 = 20;

void setup()
{
    pinMode(dioda1,OUTPUT);
    pinMode(przycisk,INPUT);
}
```

### ustawienia czujnika MAX6675
```c
#include <SPI.h>
SPISettings parSPI(10000000,MSBFIRST,SPI,MODE0);

void setup()
{
    SPI.begin(true);
    Serial.begin(9600);
}
```


## 2. DIODY

## 3. PRZYCISK

## 4. CZUJNIK MAX6675

## 5. SILNIK
