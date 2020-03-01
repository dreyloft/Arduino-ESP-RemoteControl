int analogValue;
bool buttonpressed = false;

void setup() {
  //LED
  pinMode(D0, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  //Buttons
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  //Serial
  Serial.begin(9600);
  //Poti
  pinMode(A0, INPUT);
}

void loop() {
  
  if (analogRead(A0) < (analogValue - 5) || analogRead(A0) > (analogValue + 5)){
    analogValue = analogRead(A0);
    Serial.println(analogRead(A0));
  }

  digitalWrite(D0, true);
  digitalWrite(D5, true);
  digitalWrite(D6, true);

  if(digitalRead(D1) && !digitalRead(D2))
  {
    if (!buttonpressed)
    {
      buttonpressed = true;
      Serial.println("red");
    }
    digitalWrite(D0, false);
  } 
  else if(digitalRead(D2) && !digitalRead(D1))
  {
    if (!buttonpressed)
    {
      buttonpressed = true;
      Serial.println("blue");
    }
    digitalWrite(D5, false);
  } 
  else 
  {
    if (buttonpressed){
      buttonpressed = false;
      Serial.println("green");
    }
    digitalWrite(D6, false);
  }
}

