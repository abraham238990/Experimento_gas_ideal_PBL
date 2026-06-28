#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

int mostrador = 0;

void setup() {
  Serial.begin(9600);

  if (!bmp.begin(0x77))  // tente 0x77 se não funcionar
  {
    Serial.println("Sensor BMP280 nao encontrado!!");
    while (1)
      ;
  }

  Serial.println("BMP280 iniciado com sucesso!");
}

void loop() {
  float temperatura = bmp.readTemperature();
  float pressao = bmp.readPressure();
  float altitude = bmp.readAltitude(1013.25);

  Serial.println("========================");

  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" C");

  if (mostrador == 0) {
    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");
  } else {
    Serial.print("Pressao: ");
    Serial.print(pressao);
    Serial.println(" Pa");
  }

  Serial.println("========================\n");

  delay(3000);

  mostrador = !mostrador;  // alterna entre altitude e pressão
}