#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int ledPin = 6;
int fadeValue = 0;

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);
 DallasTemperature sensors(&oneWire);

DeviceAddress insideThermometer = { 0x28, 0xAD, 0x81, 0x5F, 0x07, 0x00, 0x00, 0x36 };
DeviceAddress outsideThermometer = { 0x28, 0xBF, 0x45, 0x5F, 0x07, 0x00, 0x00, 0x3E };


void setup(void) 
{
  sensors.begin();
  sensors.setResolution(insideThermometer, 10);
  sensors.setResolution(outsideThermometer, 10);
{
  pinMode(ledPin, OUTPUT);
  for (int fadeValue = 0 ; fadeValue <= 1; fadeValue += 1)
  analogWrite(ledPin, fadeValue);
  delay(1);
}
  lcd.begin(16,2);
  lcd.print("   ARDUTERMO");
  lcd.setCursor(0, 1);
  lcd.print("  V1.0 240716");
  delay(1500);
  lcd.clear();
}  
  
  void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) 
{
  lcd.print(" Error");
} 
  else 
{
  lcd.print(tempC);
}
}
  
  void loop(void)
{ 
  delay(3000);
  sensors.requestTemperatures();
    lcd.setCursor(0,0);
      lcd.print("Inside: ");
  printTemperature(insideThermometer);
    lcd.setCursor(0,1);
      lcd.print("Outside: ");
  printTemperature(outsideThermometer);
}

