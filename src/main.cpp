#include <Arduino.h>
#include <Bounce2.h>

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define ZEIT 1000

#define SCHALTER1 6

Bounce Button = Bounce();

void setup()
{
  Serial.begin(57600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(SCHALTER1, INPUT);

  Button.attach(SCHALTER1, INPUT);
  Button.interval(5);
}
unsigned long lastBlink = 0;
int counter = 0;
int counter2,countbut = 0;
unsigned long timer = 0;
int i = 0;

void loop()
{

  Button.update();
  if (Button.rose())
  {
    digitalWrite(LED1, HIGH);
    countbut++;
    i = true;
  }
  if (i == true)
  {
    if (millis() - timer > ZEIT)
    {
      counter++;
      Serial.print("Counter1: ");
      Serial.println(counter);
      Serial.print("Counter2: ");
      Serial.println(counter2);
      Serial.println("---------------------");
      timer = millis();
    }
    if (counter == 10)
    {
      counter = 0;
      counter2++;
    }
    if (counter2 == 1)
    {
      digitalWrite(LED2, HIGH);
    }
    if (counter2 == 2)
    {
      digitalWrite(LED3, HIGH);
    }
    if (counter2 == 3)
    {
      digitalWrite(LED4, HIGH);
    }
  }
 if (countbut % 2 == 0 && i == true)
 {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    counter = 0;
    counter2 = 0;
    i = false;
 }
 
}
