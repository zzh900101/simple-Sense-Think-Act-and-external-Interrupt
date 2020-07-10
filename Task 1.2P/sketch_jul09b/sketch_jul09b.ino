#define SIGNAL_PIN 2


//Globals
uint8_t led_state = LOW;
uint8_t sensor_state = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN), red, CHANGE);
}

void loop() {
  if(digitalRead(SIGNAL_PIN) == sensor_state){
    Serial.println("Movement detected.");
    digitalWrite(8,HIGH);
    delay(300);
    digitalWrite(8,LOW);
    delay(200);
    digitalWrite(8,HIGH);
    delay(300);
    digitalWrite(8,LOW);
  }
  delay(1000);
}

void red()
{
  Serial.println("Movement not detect.");
  led_state = !led_state;
  digitalWrite(8,LOW);
  digitalWrite(10,led_state);
  }
