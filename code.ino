#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define I2C_ADDR    0x20
#define BACKLIGHT_PIN  7
#define En_pin  4
#define Rw_pin  5
#define Rs_pin  6
#define D4_pin  0
#define D5_pin  1
#define D6_pin  2
#define D7_pin  3
#define LED_OFF  0
#define LED_ON  1


#define DHTPIN 2
#define DHTTYPE DHT22

float temp;
float humi;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.begin (16,2);
  dht.begin(); 
  lcd.setBacklightPin(BACKLIGHT_PIN,NEGATIVE);
  lcd.setBacklight(LED_ON);
}

void loop()
{
// Clear the screen
  lcd.clear();
  lcd.backlight(); 

  // Temperature
  temp= dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(12,0);
  lcd.print(temp);
  lcd.setCursor(14,0);
  lcd.write(B11011111); // Degree symbol
  lcd.setCursor(15,0);
  lcd.print("C");

  // On affiche l'humidité
  humi = dht.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("Humidite:");
  lcd.setCursor(9,1);
  lcd.print(humi);
  lcd.setCursor(15,1);
  lcd.write(B00100101); // Percent symbol


  delay(10000); // 10 seconds delay before restarting
}
