/*
  Project Name : Smart Motion Detection Security System
  Prepared By  : [Shihanul Islam Rian]
  Institute    : [MoulviBazar Polytechnic Institute]
  Date         : [25-06-2026]
*/

int pirPin    = 7;
int buzzerPin = 8;
int ledPin    = 13;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Serial.println("System Ready...");
}

void loop()
{
  int val = digitalRead(pirPin);

  if (val == HIGH)
  {
    Serial.println("Alert! Motion Detected");

    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);

    delay(3000);

    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);

    Serial.println("System OK");
    delay(500);
  }
}