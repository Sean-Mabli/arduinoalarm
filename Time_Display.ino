
void Time_Display()  {
  lcd.setCursor(0, 0);
  lcd.print("Time:");

  if (dt.hour > 12) {
    time_hour = (dt.hour - 12);
    if (time_hour > 9) {
      lcd.setCursor(6, 0);
      lcd.print(time_hour);
    }
    else {
      lcd.setCursor(7, 0);
      lcd.print(time_hour);
    }

    lcd.setCursor(8, 0);
    lcd.print(":");

    if (dt.minute > 9) {
      lcd.setCursor(9, 0);
      lcd.print(dt.minute);
    }
    else {
      lcd.setCursor(9, 0);
      lcd.print("0");
      lcd.setCursor(10, 0);
      lcd.print(dt.minute);
    }
    if (dt.hour != 12) {
      lcd.setCursor(12, 0);
      lcd.print("PM\n");
      time_AM_PM = "PM\n";
    }
    else {
      lcd.setCursor(12, 0);
      lcd.print("AM\n");
      time_AM_PM = "AM\n";
    }
  }
  else {
    time_hour = dt.hour;
    if (dt.hour > 9) {
      lcd.setCursor(6, 0);
      lcd.print(dt.hour);
    }
    else {
      lcd.setCursor(7, 0);
      lcd.print(dt.hour);
    }
    lcd.setCursor(8, 0);
    lcd.print(":");
    if (dt.minute > 9) {
      lcd.setCursor(9, 0);
      lcd.print(dt.minute);
    }
    else {
      lcd.setCursor(9, 0);
      lcd.print("0");
      lcd.setCursor(10, 0);
      lcd.print(dt.minute);
    }
    if (dt.hour != 12) {
      lcd.setCursor(12, 0);
      lcd.print("AM\n");
      time_AM_PM = "AM\n";
    }
    else {
      lcd.setCursor(12, 0);
      lcd.print("PM\n");
      time_AM_PM = "PM\n";
    }
  }
  lcd.setCursor(11, 0);
  lcd.print(" ");
  lcd.setCursor(14, 0);
  lcd.print(" ");
}
