#include <SPI.h>
SPISettings parSPI(10000000,MSBFIRST,SPI,MODE0);

#define SILNIK 15
#define CZUJNIK 20
#define PRZYCISK 19

#define  DIODA1 7
#define  DIODA2 8
#define  DIODA3 9
#define  DIODA4 10
#define DIODA5 11
#define  DIODA6 12
#define  DIODA7 13
#define  DIODA8 14

double PROG;
double TEMPERATURA;

int PrzyciskA, PrzyciskB;

void setup()
{
    SPI.begin(true);
    Serial.begin(9600);

    pinMode(SILNIK,OUTPUT);
    pinMode(CZUJNIK,OUTPUT);
    pinMode(PRZYCISK,INPUT);

    pinMode(DIODA1,OUTPUT);
    pinMode(DIODA2,OUTPUT);
    pinMode(DIODA3,OUTPUT);
    pinMode(DIODA4,OUTPUT);
    pinMode(DIODA5,OUTPUT);
    pinMode(DIODA6,OUTPUT);
    pinMode(DIODA7,OUTPUT);
    pinMode(DIODA8,OUTPUT);
}

void loop()
{
    // <!== CZUJNIK
    digitalWrite(CZUJNIK,HIGH);

    SPI.beginTransaction(parSPI);
    digitalWrite(CZUJNIK,LOW);

    uint16_t val = SPI.transfer16(0);
    digitalWrite(CZUJNIK,HIGH);

    TEMPERATURA = ((val&0x7FFF)>>3)*0.25;

    //PRZYCISK
    PrzyciskA=0;
    PrzyciskB=0;

    if(digitalWrite(PRZYCISK)) PrzyciskA=1;
    else PrzyciskB=0;

    // PRZYCISK - WCISNIECIE
    if((PrzyciskA==1) && (PrzyciskB==0))
    {
        PROG = TEMPERATURA;

        Serial.print("PROG - ");
        Serial.printLn(PROG);
    }

    SPI.endTransaction();
    // CZUJNIK =!>


    Serial.print("TEMPERATURA - ");
    Serial.printLn(TEMPERATURA);

    if(TEMPERATURA >= PROG)
    {

        // SILNIK - UROCHUMIENIE
        analogWrite(SILNIK,120);

        // DIODY WIZUALIZACJA
        switch(TEMPERATURA)
        {
            case 27:
                digitalWrite(DIODA1, HIGH);
                break;

            case 28:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                break;

            case 29:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                break;

            case 29.55:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                digitalWrite(DIODA4, HIGH);
                break;

            case 29.75:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                digitalWrite(DIODA4, HIGH);
                digitalWrite(DIODA5, HIGH);
                break;

            case 29.5:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                digitalWrite(DIODA4, HIGH);
                digitalWrite(DIODA5, HIGH);
                digitalWrite(DIODA6, HIGH);
                break;

            case 30:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                digitalWrite(DIODA4, HIGH);
                digitalWrite(DIODA5, HIGH);
                digitalWrite(DIODA6, HIGH);
                digitalWrite(DIODA7, HIGH);
                break;

            case 31:
                digitalWrite(DIODA1, HIGH);
                digitalWrite(DIODA2, HIGH);
                digitalWrite(DIODA3, HIGH);
                digitalWrite(DIODA4, HIGH);
                digitalWrite(DIODA5, HIGH);
                digitalWrite(DIODA6, HIGH);
                digitalWrite(DIODA7, HIGH);
                digitalWrite(DIODA8, HIGH);
                break;
            default:
                break;

        }
    }
    delay(300);
}


