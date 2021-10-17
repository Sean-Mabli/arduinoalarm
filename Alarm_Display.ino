
void Alarm_Display()  {
  
  Time_Display();
  
  lcd.setCursor(0, 1);
  lcd.print("Alarm:");

  if (alarm_set == true) {
    if (alarm_hour.toInt() > 9) {
      lcd.setCursor(6, 1);
      lcd.print(alarm_hour.toInt());
    }
    else {
      lcd.setCursor(7, 1);
      lcd.print(alarm_hour.toInt());
    }

    lcd.setCursor(8, 1);
    lcd.print(":");

    if (alarm_min.toInt() > 9) {
      lcd.setCursor(9, 1);
      lcd.print(alarm_min.toInt());
    }
    else {
      lcd.setCursor(9, 1);
      lcd.print("0");
      lcd.setCursor(10, 1);
      lcd.print(alarm_min.toInt());
    }

    lcd.setCursor(12, 1);
    lcd.print(alarm_AM_PM);

    lcd.setCursor(11, 1);
    lcd.print(" ");
    lcd.setCursor(14, 1);
    lcd.print("    ");
  }
  Time_Display();
}
