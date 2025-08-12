//Gerekli Kütüphaneler Tanımlanıyor
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

// Step motor ayarları
const int stepsPerRevolution = 2048;
Stepper motorSol(stepsPerRevolution, 8, 10, 9, 11);
Stepper motorSag(stepsPerRevolution, 4, 6, 5, 7);

// IR alıcı pini ayarları
const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

// LCD ayarları
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int role = 3;
const int ADIM_SAYISI = 500; // Aşağı inilecek ve yukarı çıkılacak adım sayısı

void setup() {
  Serial.begin(9600);
  lcd.init();               
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Robot Hazir");

  irrecv.enableIRIn();

  motorSol.setSpeed(10);
  motorSag.setSpeed(10);

  pinMode(role, OUTPUT);
  digitalWrite(role, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    long irKod = results.value;
    irrecv.resume();
   
    if (irKod == 0xFFA25D) {  // 1 tuşu
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1.BUTON");
    lcd.setCursor(0, 1);
    lcd.print("Temizlik Basladi");

    OrtaNoktadanCaprazSagUstKose();
    //digitalWrite(role, LOW);
    solaGit();
    solaGit();
    temizlikAsagiIn();
    sagaGit();
    sagaGit();
    //temizlikAsagiIn();
    //digitalWrite(role, HIGH);
    SagAltKosedenCaprazOrtaNokta();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temizlik Bitti");
    }

    if (irKod == 0xFF629D) {  // 2 tuşu
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2: L Noktasi");
    lcd.setCursor(0, 1);
    lcd.print("Sola Gidiliyor");
    solaGit();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ortaya Donuluyor");
    sagaGit();

    lcd.setCursor(0, 1);
    lcd.print("Donus Tamam ");
    }

    if (irKod == 0xFFE21D) {  // 3 tuşu
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("3: R Noktasi");
    lcd.setCursor(0, 1);
    lcd.print("Asagi Iniliyor");
    asagiIn();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ortaya Cikiliyor");
    yukariCik();

    lcd.setCursor(0, 1);
    lcd.print("Donus Tamam ");
    }
  }
}

//Hareket Fonksiyonları

// Orta noktadan alt köşeye düz inme (Y ekseni boyunca)
void yukariCik() {
  for (int i = 0; i < 7*ADIM_SAYISI; i++) {
    motorSag.step(-1);  // Aşağı yön
    motorSol.step(-1);
  }
  delay(200);
}

// Alt köşeden tekrar orta noktaya düz çıkma
void asagiIn() {
  for (int i = 0; i < 5*ADIM_SAYISI; i++) {
    motorSag.step(1);   // Yukarı yön 
    motorSol.step(1);
  }
  delay(200);
}

// Orta noktadan sola gitme (X ekseni boyunca)
void solaGit() {
  for (int i = 0; i < 20 * ADIM_SAYISI; i++) {
    motorSol.step(-1);   // Sola gitme
    motorSag.step(1);    
  }
  delay(200);
}

// Soldan orta noktaya geri dönme
void sagaGit() {
  for (int i = 0; i < 20 * ADIM_SAYISI; i++) {
    motorSol.step(1);    // Sağa gelme
    motorSag.step(-1);
  }
  delay(200);
}

// Aşağı inme
void temizlikAsagiIn() {
  for (int i = 0; i < 1*ADIM_SAYISI; i++) {
    motorSag.step(1);  // Aşağı yön
    motorSol.step(1);
  }
  delay(200);
}

void OrtaNoktadanCaprazSagUstKose() {
  for (int i = 0; i < 7*ADIM_SAYISI; i++) {
    motorSol.step(-1);   // Sol motor daha fazla çeker
    if (i % 2 == 0) {   // Sağ motor yarı hızla çeker
      motorSag.step(-1);
    }
  }
  delay(200);
}

void SagAltKosedenCaprazOrtaNokta() {
  for (int i = 0; i < 7*ADIM_SAYISI; i++) {
    motorSol.step(1);   // Sol motor ip salar
    if (i % 2 == 0) {
      motorSag.step(1); // Sağ motor da salar ama daha az
    }
  }
  delay(200);
}

//IR KUMANDA HEX KODLARI
//  1     : FFA25D
//  2     : FF629D
//  3     : FFE21D
//  4     : FF22DD
//  5     : FF02FD
//  6     : FFC23D
//  7     : FFE01F
//  8     : FFA857
//  9     : FF906F
//  0     : FF9867
//  *     : FF6897
//  #     : FFB04F
//  Yukarı: FF18E7
//  Aşağı : FF4AB5
//  Sağ   : FF5AA5
//  Sol   : FF10EF
//  OK    : FF38C7