/*
 * TUTORIAL SENSOR TEGANGAN PADA ARDUINO
 * MEMBACA NILAI TEGANGAN DARI I/)
 * 
 * Pinout  :
 * Tegangan +  -> A3
 * 
 * Untuk membaca nilai tegangan masuk di pin analog A3
 */
#include <Arduino.h> 
#define pinVoltage A3
#define GAIN 0.11 //Vread = VIN * GAIN angka untuk kalibrasi
#define ADC_REF 5 //referensi voltage ADC adalah 5V

int samples = 10; //jumlah sampling
int nilaiSensor;

void setup() {
  pinMode(pinVoltage,INPUT); //set A3 menjadi input
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  delay(100);
  Serial.println("Mencoba baca nilai Voltage pada Arduino");
}

void loop() {
  long jumlah = 0;
  for(int i = 0;i<samples;i++){
    nilaiSensor=analogRead(pinVoltage);
    jumlah +=nilaiSensor;
    delay(2); 
  }
  nilaiSensor = jumlah / samples; //rata2 nya
  float voltage = nilaiSensor*ADC_REF/1024/GAIN;
  Serial.println("Voltage terbaca : " + String(voltage)); //tampilkan pada serial monitor
  delay(1000);  //jeda waktu 1000 uS
}
