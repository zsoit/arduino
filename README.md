
[def]: powtorka.c
# Owtórz plik [powtorka.c][def]

## Zaprogramować układ w taki sposób:

-  aby odczytywał temperaturę z czujnika MAX6675,
- a następnie na jej podstawie sterował prędkością silnika.

- Silnik ma się włączać, gdy temperatura przekroczy pewien próg.
Próg jest ustalany po wciśnięciu przycisku (jako bieżąca temperatura)

- Dodatkowo należy użyć diod LED do zwizualizowania poziomu temperatury.




# POLECENIA ARDUINO

```c
#define DIODA2 15;

// void setup()
pinMode(DIODA2,OUTPUT);

// void loop()
digitalWrite(DIODA2, HIGH);
digitalWrite(DIODA2, LOW);

analogWrite(SILNIK,PREDKOSC);

//opozninie milisekundy (1000 = 1sek)
delay(1000);


```


## 1. Ustawienie PINÓW - pinMode()

###
```c
// PINY
int dioda1 = 14;
int przycisk1 = 20;
int silnik = 18;

void setup()
{
    pinMode(dioda1,OUTPUT);
    pinMode(przycisk,INPUT);
    pinMode(silnik,OUTPUT);
}
```

## 2. DIODY


```c

int dioda1 = 15;

void loop()
{
    // WŁĄCZONA
    digitalWrite(dioda1, HIGH);

    // WYŁĄCZONA
    digitalWrite(dioda2, LOW);
}
```

## 3. PRZYCISK

### Wykrycie wciśnięcia
```c

//PRZYCISK
int przycisk = 16;

// setup ... pinMode(przycisk,INPUT)

void loop()
{
    int a = 0;
    int b = 0;

    if(digitalWrite(przycisk)) a=1;
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

int silnik = 19; // numer pinu

// setup ... pinMode(silnik,OUTPUT)

void loop()
{
    int predkosc = 120;
    // od 0 do 250, przy 60 sie uruchamia

    analogWrite(silnik,predkosc);
}
```

## 5. CZUJNIK MAX6675

### ustawienia czujnika MAX6675
```c
#include <SPI.h>
SPISettings parSPI(10000000,MSBFIRST,SPI,MODE0);

void setup()
{
    SPI.begin(true);
    Serial.begin(9600);
}

void loop()
{
    //CZUJNIK
    digitalWrite(czujnik,HIGH);

    SPI.beginTransaction(parSPI);
    digitalWrite(czujnik,LOW);

    uint16_t val = SPI.transfer16(0);
    digitalWrite(czujnik,HIGH);

    // TEMPERATURA
    double TEMPERATURA = ((val&0x7FFF)>>3)*0.25;
    Serial.print("TEMPERATURA - ");
    Serial.printLn(TEMPERATURA);

    SPI.endTransaction();

    delay(250); //opozninie milisekundy
}


```

