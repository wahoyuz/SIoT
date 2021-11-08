// AUTHOR: wahoyuz (https://github.com/wahoyuz)
// TUTORIAL LINK: https://www.arducoding.com/2017/12/simulasi-proteus-arduino-lcd-16x2_30.html
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// Change group member and group name to your own group.
const char* group[] = {"Wahyu Priambodo", "Bagus Fathoni", "Dafa Abdurrohman", "Mahesa Adiputra"};
const char* groupName = "Wahyu";

void setup(){
  Serial.begin(9600);
  lcd.init();
}

void loop(){
  // print group name.
  lcd.backlight(); // to turn on lcd light.
  lcd.setCursor(0, 0); // to set first line.
  lcd.print("Nama Kelompok");
  lcd.setCursor(0, 1); // to set second line
  lcd.print(groupName);
  delay(1000);
  lcd.clear();

  // print letter
  const char* letter = "Ketua & Anggota Kelompok";
  const char* loading = "########################"; // for loading animation.
  
  lcd.setCursor(16, 0);
  lcd.print(letter);
  lcd.setCursor(16, 1);
  lcd.print(loading);
  for (int i = 0; i < strlen(letter) + 16; i++) { // don't change + by 16 because that statement will print the letter and loading bar till disappear from screen.
    lcd.scrollDisplayLeft();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  
  // print all members begin.
  // first.. group leader.
  lcd.setCursor(0, 0);
  lcd.print("Ketua Kelompok");
  delay(1000);
  
  lcd.setCursor(0, 1);
  lcd.print(group[0]); // print the first member (group leader).
  delay(1500);
  lcd.clear();

  // then.. all members.
  lcd.setCursor(0, 0);
  lcd.print("Anggota Kelompok");
  delay(1000);
  
  for (int i = 1; i < (sizeof(group) / sizeof(group[0])); i++) {
    lcd.setCursor(0, 1);
    lcd.print(group[i]);
    lcd.print("                  "); // clear line 2.
    delay(1500);
  }
  // print all members end.
  lcd.clear(); // clear entire lcd screen.
  delay(1500); // pause 1,5s before start the loop back.
}
