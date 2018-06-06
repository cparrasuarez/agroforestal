#include <DHT.h>

DHT sensor(2, DHT11);

int mq2 = 0;
int temperatura = 0;
int fuego = 0;
int humedad = 0;

int umbralMq2 = 0;
int umbralTemperatura = 0;
int umbralFuego = 0;
int umbralHumedad = 0;

int sensibilidadMq2 = 50;
int sensibilidadTemperatura = 20;
int sensibilidadFuego = 120;
int sensibilidadHumedad = 100; // hay que ajustarlos segun las condiciones

void setup() {

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);

  sensor.begin();

  digitalWrite(12, HIGH);

  umbralMq2 = analogRead(A0);
  umbralFuego = analogRead(A2);
  umbralTemperatura = sensor.readTemperature();
  umbralHumedad = sensor.readHumidity();

  delay(100);

  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}

void loop() {
  mq2 = analogRead(A0);
  fuego = analogRead(A2);
  temperatura = sensor.readTemperature();
  humedad = sensor.readHumidity();

  Serial.println("MQ-2: ");
  Serial.println(mq2);

  Serial.println("IR: ");
  Serial.println(fuego);

  Serial.println("TEMP: ");
  Serial.println(temperatura);

  Serial.println("HUM: ");
  Serial.println(humedad);

  Serial.println();
  Serial.println();
  delay (500);
  
  if(mq2 >= umbralMq2 || fuego <= umbralFuego || temperatura >= umbralTemperatura || humedad >= umbralHumedad) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
}
