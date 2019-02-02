// by DojoDave and Tom Igoe
// modified by jesmahel

#define DIGIN12 12
#define DIGIN13 13
#define EINAUS 12
#define ZURUECK 13
#define OFF 0
#define ON -1

const int buttonPin = 12;
const int ledPin =  13;

int buttonState = LOW;
int OldButtonState = LOW;
int LichtAn = OFF;
int OldLichtAn = OFF;
 
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
}
 
void loop()
{

    // Taster abfragen, nur bei Statusänderung reagieren
    buttonState = digitalRead(buttonPin);
    if (buttonState != OldButtonState && buttonState == HIGH)
    {
        if (LichtAn == OFF)
        {
            LichtAn = ON;
        }
        else
        {
            LichtAn = OFF;
        }
    }

    // In alt status übernehmen
    OldButtonState = buttonState;
    
    // Lampe ein/ausschalten
    if (OldLichtAn != LichtAn)
    {
        if (LichtAn == ON)
        {
            digitalWrite(ledPin, HIGH);
        }
        else
        {
            digitalWrite(ledPin, LOW);
        }
        OldLichtAn = LichtAn;
        // 200ms warten
        delay(200);
    }
}