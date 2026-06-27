/*
  Project Name : Smart Motion Detection Security System
  Prepared By  : [Shihanul Islam Rian]
  Institute    : [MoulviBazar Polytechnic Institute]
  Date         : [25-06-2026]
*/

int pirPin = 7;
int buzzerPin = 8;
int ledPin = 13;

bool noObjectPrinted = false;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("No Object");
  noObjectPrinted = true;
}

void loop()
{
  int val = digitalRead(pirPin);

  if (val == HIGH)
  {
    Serial.println("Motion Detected!");

    noObjectPrinted = false;

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    delay(3000);

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  else
  {
    if (!noObjectPrinted)
    {
      Serial.println("No Object");
      noObjectPrinted = true;
    }
  }

  delay(300);
}