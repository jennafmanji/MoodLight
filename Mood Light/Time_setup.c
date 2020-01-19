// DS3231 - Version: Latest 
#include <DS3231.h>


//Create an rtc object 
DS3231  rtc(SDA, SCL); 

void setup() {
// Setup Serial connection
  Serial.begin(115200);
  
  // Initialize the rtc object
  rtc.begin();
  
  //rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(8, 58, 00);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(30, 10, 2018);   // Set the date to January 1st, 2014
}

void loop() {
     Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating
  delay (1000);
}