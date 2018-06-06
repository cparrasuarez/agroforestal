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

int sensibilidadMq2 = 40;
int sensibilidadTemperatura = 5;
int sensibilidadFuego = -10;
int sensibilidadHumedad = 20; // hay que ajustarlos segun las condiciones

void setup() {

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3,INPUT);

  Serial.begin(9600);

  sensor.begin();

  digitalWrite(12, HIGH);

  umbralMq2 = analogRead(A0) + sensibilidadMq2;
  umbralFuego = digitalRead(3) + sensibilidadFuego;
  umbralTemperatura = sensor.readTemperature() + sensibilidadTemperatura;
  umbralHumedad = sensor.readHumidity() + sensibilidadHumedad;

  delay(1000);

  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}

void loop() {
  mq2 = analogRead(A0);
  fuego = digitalRead(3);
  temperatura = sensor.readTemperature();
  humedad = sensor.readHumidity();

  Serial.print("MQ-2: ");
  Serial.print(mq2);

  Serial.print("   IR: ");
  Serial.print(fuego);

  Serial.print("   TEMP: ");
  Serial.print(temperatura);

  Serial.print("   HUM: ");
  Serial.println(humedad);


  delay (500);

  if (mq2 >= umbralMq2 || fuego <= umbralFuego || temperatura >= umbralTemperatura || humedad >= umbralHumedad) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
}
