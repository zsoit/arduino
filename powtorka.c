include <SPI.h>
SPISettings parSPI(100000),MSBFIRST,SPI,MODE0;

int silnik = 15;
int czujnik = 20;
int przycisk = 19;

int dioda1=7;
int dioda2=8;
int dioda3=9;
int dioda4=10;
int dioda5=11;
int dioda6=12;
int dioda7=13;
int dioda8=14;

double PROG;
double TEMPERATURA;


void setup()
{
    SPI.begin(true);
    Serial.begin(9600);

    pinMode(silnik,OUTPUT);
    pinMode(czujnik,OUTPUT);
    pinMode(przycisk,INPUT);

    pinMode(dioda1,OUTPUT);
    pinMode(dioda2,OUTPUT);
    pinMode(dioda3,OUTPUT);
    pinMode(dioda4,OUTPUT);
    pinMode(dioda5,OUTPUT);
    pinMode(dioda6,OUTPUT);
    pinMode(dioda7,OUTPUT);
    pinMode(dioda8,OUTPUT);
}

void loop()
{
    //CZUJNIK
    digitalWrite(czujnik,HIGH);

    SPI.beginTransaction(parSPI);
    digitalWrite(czujnik,LOW);

    uint16_t val = SPI.transfer16(0);
    digitalWrite(czujnik,HIGH);

    TEMPERATURA = ((val&0x7FFF)>>3)*0.25;

    //PRZYCISK
    int a = 0;
    int b = 0;

    if(digitalWrite(przycisk)) a=1;
    else a=0;

    // PRZYCISK - WCISNIECIE
    if((a==1) && (b==0))
    {
        PROG = TEMPERATURA ;

        Serial.print("PROG - ");
        Serial.printLn(TEMPERATURA);

    }

    SPI.endTransaction();

    Serial.print("Temperatura - ");
    Serial.printLn(TEMPERATURA);

    if(TEMPERATURA >= PROG)
    {

        // SILNIK - UROCHUMIENIE
        analogWrite(silnik,120);

        // DIODY WIZUALIZACJA
        switch(TEMPERATURA)
        {
            case 27:
                digitalWrite(dioda1, HIGH);
                break;

            case 28:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                break;

            case 29:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                break;

            case 29.55:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                digitalWrite(dioda4, HIGH);
                break;

            case 29.75:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                digitalWrite(dioda4, HIGH);
                digitalWrite(dioda5, HIGH);
                break;

            case 29.5:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                digitalWrite(dioda4, HIGH);
                digitalWrite(dioda5, HIGH);
                digitalWrite(dioda6, HIGH);
                break;

            case 30:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                digitalWrite(dioda4, HIGH);
                digitalWrite(dioda5, HIGH);
                digitalWrite(dioda6, HIGH);
                digitalWrite(dioda7, HIGH);
                break;

            case 31:
                digitalWrite(dioda1, HIGH);
                digitalWrite(dioda2, HIGH);
                digitalWrite(dioda3, HIGH);
                digitalWrite(dioda4, HIGH);
                digitalWrite(dioda5, HIGH);
                digitalWrite(dioda6, HIGH);
                digitalWrite(dioda7, HIGH);
                digitalWrite(dioda8, HIGH);
                break;
            default:
                break;

        }
    }
    delay(300);
}


