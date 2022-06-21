#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd_1(12, 9, 5, 4, 3, 2);
SoftwareSerial bluetooth(10, 11); // RX, TX
const int button = 7;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(button,INPUT);
  lcd_1.begin(16, 2); 
}

void loop(){
  int buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    bluetooth.print(1);
    Serial.println(1);
    botClicado();
    delay(5000);
  }
  if(buttonState==LOW){
    inicio();}
}

int inicio(){
  lcd_1.setCursor(0,0);
  lcd_1.print("      Tocar    ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("    Campainha    ");
  }

void pontos(){
  lcd_1.setCursor(0,1);
  lcd_1.print("       .");
  delay(1000);
  lcd_1.setCursor(8,1);
  lcd_1.print(".");
  delay(1000);
  lcd_1.setCursor(9,1);
  lcd_1.print(".");
  delay(1500);
}

void botClicado(){
  Serial.println("Botão clicado");
    lcd_1.setCursor(0,0);
    lcd_1.print("     Aguarde    ");
    lcd_1.setCursor(0,1);
    lcd_1.print("                ");
    delay(500);
    pontos();
    lcd_1.setCursor(0,1);
    lcd_1.print("                ");
    delay(500);
    pontos();
}
