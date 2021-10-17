#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DS3231 clock;
RTCDateTime dt;

int buzzer = 2; //Alarm
int button = 4; //Snooze
int button_read;
bool alarm_set;
bool alarm_beep;
String alarm_hour;
String alarm_min;
String alarm_AM_PM;
int time_hour;
String time_AM_PM;
int i; //Frequency of Alarm

void setup() {

  lcd.begin(16, 2);

  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  clock.begin();
  //clock.setDateTime(__DATE__, __TIME__);

  lcd.setCursor(6, 1);
  lcd.print(" Set Alarm");

  Serial.print("Enter Hour of Alarm");
  Serial.println();

  alarm_set =  false;
  alarm_beep = true;
}

void loop() {
  dt = clock.getDateTime();

  if (alarm_hour == 0) {
    if (Serial.available() > 0) {
      alarm_hour = Serial.readString();
      Serial.println("Alarm Hour Set: " + alarm_hour);
      lcd.clear();
      Serial.print("Enter Minute of Alarm");
      Serial.println();
      Serial.end();
      Serial.begin(9600);
    }
  }
  if (alarm_min == 0) {
    if (Serial.available() > 0) {
      alarm_min = Serial.readString();
      Serial.println("Alarm Minute Set: " + alarm_min);
      lcd.clear();
      Serial.print("Enter Ante Meridiem of Alarm");
      Serial.println();
      Serial.end();
      Serial.begin(9600);
    }
  }
  if (alarm_AM_PM == 0) {
    if (Serial.available() > 0) {
      alarm_AM_PM = Serial.readString();
      Serial.println("Alarm Ante Meridiem Set: " + alarm_AM_PM);
      lcd.clear();
      Serial.print("Alarm Set!");
      Serial.println();
      Serial.end();
      Serial.begin(9600);
      alarm_set = true;
    }
  }

  Time_Display();

  Alarm_Display();

  if ((alarm_beep == true) && (alarm_set == true) && (alarm_min.toInt() == dt.minute) && (alarm_hour.toInt() == time_hour) && (time_AM_PM == alarm_AM_PM)) {
    for (i = 0; i < 80; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
      Time_Display();
    }
    for (i = 0; i < 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
      Time_Display();
    }
    button_read = digitalRead(button);
    if (button_read == LOW) {
      alarm_beep = false;
      Time_Display();
    }
  }
}
