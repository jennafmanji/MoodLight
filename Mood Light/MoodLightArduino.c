// DS3231 - Version: Latest 
#include <DS3231.h>

#include <stdio.h>

// include the required library codes:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
 int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define REDPIN 1
#define GREENPIN 9
#define BLUEPIN 10

#define MAXCHAR 100

//Create an rtc object 
DS3231  rtc(SDA, SCL); 

const int button1 = 6;  
const int button2 = 7;

//Variables
int buttonState1 = 0;
int flag1=0;
int buttonState2 = 0;
int flag2= 0;

int mood = 0; 
int quoteFile = 0; 


void setup() {
  
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  
  // Initialize the rtc object
  rtc.begin(); 
  
  pinMode(button1, INPUT_PULLUP); 
  pinMode(button2, INPUT_PULLUP);
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
 
}

void loop() {

  if (mood == 0){
   digitalWrite (REDPIN, 255);
   digitalWrite (GREENPIN, 255);
   digitalWrite (BLUEPIN, 255);
  }

  else if (mood == 1){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 0);
  }

  else if (mood == 2){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 255);
    digitalWrite (BLUEPIN, 0);
  }

  else if (mood == 3){
    digitalWrite (REDPIN, 0);
    digitalWrite (GREENPIN, 255);
    digitalWrite (BLUEPIN, 0);
  }

  else if (mood == 4){
    digitalWrite (REDPIN, 0);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 255);
  }

  else if (mood == 5){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 255);
  }
  
 // update current time 
  lcd.setCursor(0,0);
  lcd.print("Time:  ");
  lcd.print(rtc.getTimeStr());

//Read button state (pressed or not pressed?)
  buttonState1 = digitalRead(button1);
  
  //Read button state (pressed or not pressed?)
  buttonState2 = digitalRead(button2);
  
  //If button pressed...
  if (buttonState1 == LOW) { 
    Serial.println ("Button 1 pressed");
    delay (500);
    
    if (flag1 == 0){
      lcd.setCursor(0,1);      
      lcd.print("Happy            ");
      mood = 0; 
      flag1=1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag1 == 1){
      lcd.setCursor(0,1);
      mood = 1; 
      lcd.print("Energetic         ");
      flag1=2; //change flag variable again 
    }
    else if ( flag1 == 2){
      lcd.setCursor(0,1);
      mood =2;
      lcd.print("Focused         ");
      flag1=3; //change flag variable again 
    }
    else if ( flag1 == 3){
      lcd.setCursor(0,1);
      mood = 3;
      lcd.print("Calm         ");
      flag1=4; //change flag variable again 
    }
    else if ( flag1 == 4){
      lcd.setCursor(0,1);
      mood = 4;
      lcd.print("Sleepy         ");
      flag1=5; //change flag variable again 
    }
    
    
    else if ( flag1 == 5){
      lcd.setCursor(0,1);
      mood = 5;
      lcd.print("Relaxed         ");
      flag1=0; //change flag variable again 
    }

  }
  if (buttonState2 == LOW){
     delay (1000);
     Serial.println (mood);
     //happy quotes
     if (mood == 0 || mood == 3){
       lcd.setCursor(0,1);
       lcd.print ("Be thankful       ");
      //happyQuote ();
     }


     //motivational quotes
     if (mood == 1 || mood == 2){
      Serial.println ("Motivational Quotes"); 
     }
     //relaxing quotes
     if (mood == 4 || mood == 5){
      Serial.println ("Relaxing Quotes");
     }
  }
    
    
  }


 /* void happyQuote (){
    int hqrandomNum = rand() % 20 + 1;

    if (hqrandomNum == 1){
      
      lcd.setCursor(0,1);
       lcd.print ("Be thankful       ");
    }

    else if (hqrandomNum == 2){
      
      lcd.setCursor(0,1);
       lcd.print ("Create your own sunshine       ");
    }

    else if (hqrandomNum == 3){
    
      lcd.setCursor(0,1);
       lcd.print ("Enjoy today       ");
    }

    else if (hqrandomNum == 4){
      
      lcd.setCursor(0,1);
       lcd.print ("Today is a new day       ");
    }

    else if (hqrandomNum == 5){
      
      lcd.setCursor(0,1);
       lcd.print ("Live, Laugh, Love      ");
    }

    else if (hqrandomNum == 6){
      
      lcd.setCursor(0,1);
       lcd.print ("Sm;)e             ");
    }

    else if (hqrandomNum == 7){
      
      lcd.setCursor(0,1);
       lcd.print ("Give Love       ");
    }

    else if (hqrandomNum == 8){
      
      lcd.setCursor(0,1);
       lcd.print ("Do it with love       ");
    }

    else if (hqrandomNum == 9){
      
      lcd.setCursor(0,1);
       lcd.print ("See the good       ");
    }

    else if (hqrandomNum == 10){
      
      lcd.setCursor(0,1);
       lcd.print ("Choose happiness       ");
    }

    else if (hqrandomNum == 11){
      
      lcd.setCursor(0,1);
       lcd.print ("Live more, worry less    ");
    }

    else if (hqrandomNum == 12){
      lcd.setCursor(0,1);
      
       lcd.print ("Live life to the fullest ");
    }

    else if (hqrandomNum == 13){
      
      lcd.setCursor(0,1);
       lcd.print ("Every moment matters       ");
    }

    else if (hqrandomNum == 14){
      
      lcd.setCursor(0,1);
       lcd.print ("Life's a journey       ");
    }

    else if (hqrandomNum == 15){
      
      lcd.setCursor(0,1);
       lcd.print ("You're my sunshine       ");
    }

    else if (hqrandomNum == 16){\
    
      lcd.setCursor(0,1);
       lcd.print ("Blue skies ahead       ");
    }

    else if (hqrandomNum == 17){
      
      lcd.setCursor(0,1);
       lcd.print ("No regrets       ");
    }

    else if (hqrandomNum == 18){
      
      lcd.setCursor(0,1);
       lcd.print ("You only live once      ");
    }

    else if (hqrandomNum == 19){
      
      lcd.setCursor(0,1);
       lcd.print ("Be a light     ");
    }

    else if (hqrandomNum == 20){
      
      lcd.setCursor(0,1);
       lcd.print ("Good vibes only       ");
    }
  }*/

  

  
  