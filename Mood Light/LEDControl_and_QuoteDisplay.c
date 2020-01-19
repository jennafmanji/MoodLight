// include the required library codes:
#include <LiquidCrystal.h> 
#include <DS3231.h>
#include <stdio.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
 int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//define LED strip pins 
#define REDPIN 13
#define GREENPIN 9
#define BLUEPIN 10

//Create an rtc object 
DS3231  rtc(SDA, SCL); 

//button pin s
const int button1 = 6;  
const int button2 = 7;

//Variables
int buttonState1 = 0;
int flag1=0;
int buttonState2 = 0;
int flag2= 0;
int mood = 0; 


void setup() {
  
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  
  // initialize the rtc object
  rtc.begin(); 

  //initialize the buttons 
  pinMode(button1, INPUT_PULLUP); 
  pinMode(button2, INPUT_PULLUP);

  //initialize the RGB lights on the LED strip 
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
 
}

void loop() {

  if (rtc.getTimeStr()== (7,0,0)){   //if it is the morning set mood to happy
    mood = 0;
  }

  else if (rtc.getTimeStr() == (21,0,0)){ //if it is the night set mood to sleepy 
    mood = 4;
  }
  

  //if the mood is happy (all colours)
  if (mood == 0){
   digitalWrite (REDPIN, 255);
   digitalWrite (GREENPIN, 255);
   digitalWrite (BLUEPIN, 255);
  }

  //if mood is energetic (red)
  else if (mood == 1){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 0);
  }

  //if mood is focused (green and red)
  else if (mood == 2){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 255);
    digitalWrite (BLUEPIN, 0);
  }
  
  //if mood is calm (green)
  else if (mood == 3){
    digitalWrite (REDPIN, 0);
    digitalWrite (GREENPIN, 255);
    digitalWrite (BLUEPIN, 0);
  }

  //if mood is sleepy (blue)
  else if (mood == 4){
    digitalWrite (REDPIN, 0);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 255);
  }

  //if mood is relaxed (blue and green)
  else if (mood == 5){
    digitalWrite (REDPIN, 255);
    digitalWrite (GREENPIN, 0);
    digitalWrite (BLUEPIN, 255);
  }
  
 // update current time 
  lcd.setCursor(0,0);
  lcd.print("Time:  ");
  lcd.print(rtc.getTimeStr());

  //Read button state of button one (viewing moods)
  buttonState1 = digitalRead(button1);
  
  //Read button state of button two (selecting mood)
  buttonState2 = digitalRead(button2);
  
  //If mood view button pressed ...
  if (buttonState1 == LOW) { 
    
    delay (500);

    //display the next mood
    if (flag1 == 0){
      lcd.setCursor(0,1);      
      lcd.print("Happy            ");
      mood = 0; 
      flag1=1; //move to the next mood  
    }

    else if ( flag1 == 1){
      lcd.setCursor(0,1);
      mood = 1; 
      lcd.print("Energetic         ");
      flag1=2; //move to the next mood  
    }
    else if ( flag1 == 2){
      lcd.setCursor(0,1);
      mood =2;
      lcd.print("Focused         ");
      flag1=3; //move to the next mood   
    }
    else if ( flag1 == 3){
      lcd.setCursor(0,1);
      mood = 3;
      lcd.print("Calm               ");
      flag1=4; //move to the next mood   
    }
    else if ( flag1 == 4){
      lcd.setCursor(0,1);
      mood = 4;
      lcd.print("Sleepy            ");
      flag1=5; //move to the next mood   
    }
       
    else if ( flag1 == 5){
      lcd.setCursor(0,1);
      mood = 5;
      lcd.print("Relaxed         ");
      flag1=0; ////move to the next mood   
    }

  }

  //see if the mood selection button has been pressed 
  if (buttonState2 == LOW){
     delay (1000);
     
     //if the mood is happy or calm display a random happy quote by calling the happyquote function
     if (mood == 0 || mood == 3){
       happyQuote ();
       
     }


     //if the mood is focused or energetic display a random motivational quote by calling the motivationalquote function
     if (mood == 1 || mood == 2){
       motivationalQuote ();
       
     }
     
     //if the mood is sleepy or relazed display a random relaxing quote by calling the relaxquote function
     if (mood == 4 || mood == 5){
       relaxQuote ();
       
     }
  }
    
    
  }

//function to display a random happy quote
  void happyQuote (){
    int hqrandomNum = rand() % 20 + 1;

    if (hqrandomNum == 1){
      
      lcd.setCursor(0,1);
       lcd.print ("Be thankful       ");
    }

    else if (hqrandomNum == 2){
      
      lcd.setCursor(0,1);
       lcd.print ("Create sunshine       ");
    }

    else if (hqrandomNum == 3){
    
      lcd.setCursor(0,1);
       lcd.print ("Enjoy today       ");
    }

    else if (hqrandomNum == 4){
      
      lcd.setCursor(0,1);
       lcd.print ("It's a new day       ");
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
       lcd.print ("Live more   ");
    }

    else if (hqrandomNum == 12){
      lcd.setCursor(0,1);
      
       lcd.print ("Worry less ");
    }

    else if (hqrandomNum == 13){
      
      lcd.setCursor(0,1);
       lcd.print ("This moment matters       ");
    }

    else if (hqrandomNum == 14){
      
      lcd.setCursor(0,1);
       lcd.print ("Life's a journey       ");
    }

    else if (hqrandomNum == 15){
      
      lcd.setCursor(0,1);
       lcd.print ("My sunshine       ");
    }

    else if (hqrandomNum == 16){
    
      lcd.setCursor(0,1);
       lcd.print ("Blue skies ahead       ");
    }

    else if (hqrandomNum == 17){
      
      lcd.setCursor(0,1);
       lcd.print ("No regrets       ");
    }

    else if (hqrandomNum == 18){
      
      lcd.setCursor(0,1);
       lcd.print ("You live once      ");
    }

    else if (hqrandomNum == 19){
      
      lcd.setCursor(0,1);
       lcd.print ("Be a light     ");
    }

    else if (hqrandomNum == 20){
      
      lcd.setCursor(0,1);
       lcd.print ("Good vibes only       ");
    }
  }



  
  void motivationalQuote (){
    int mqrandomNum = rand() % 20 + 1;

    if (mqrandomNum == 1){
      
      lcd.setCursor(0,1);
       lcd.print ("It is possible!     ");
    }

    else if (mqrandomNum == 2){
      
      lcd.setCursor(0,1);
       lcd.print ("Shoot for the moon!      ");
    }

    else if (mqrandomNum == 3){
    
      lcd.setCursor(0,1);
       lcd.print ("You can do it!     ");
    }

    else if (mqrandomNum == 4){
      
      lcd.setCursor(0,1);
       lcd.print ("Believe in you!       ");
    }

    else if (mqrandomNum == 5){
      
      lcd.setCursor(0,1);
       lcd.print ("Work hard!      ");
    }

    else if (mqrandomNum == 6){
      
      lcd.setCursor(0,1);
       lcd.print ("Stay Positive!             ");
    }

    else if (mqrandomNum == 7){
      
      lcd.setCursor(0,1);
       lcd.print ("I can and will!       ");
    }

    else if (mqrandomNum == 8){
      
      lcd.setCursor(0,1);
       lcd.print ("Dream big!       ");
    }

    else if (mqrandomNum == 9){
      
      lcd.setCursor(0,1);
       lcd.print ("Get Sh*t done!      ");
    }

    else if (mqrandomNum == 10){
      
      lcd.setCursor(0,1);
       lcd.print ("Don't look back!       ");
    }

    else if (mqrandomNum == 11){
      
      lcd.setCursor(0,1);
       lcd.print ("Become better!         ");
    }

    else if (mqrandomNum == 12){
      lcd.setCursor(0,1);
      
       lcd.print ("Actually, I can!       ");
    }

    else if (mqrandomNum == 13){
      
      lcd.setCursor(0,1);
       lcd.print ("Why not?             ");
    }

    else if (mqrandomNum == 14){
      
      lcd.setCursor(0,1);
       lcd.print ("It's never easy!       ");
    }

    else if (mqrandomNum == 15){
      
      lcd.setCursor(0,1);
       lcd.print ("Get back up!       ");
    }

    else if (mqrandomNum == 16){\
    
      lcd.setCursor(0,1);
       lcd.print ("Prove them wrong!        ");
    }

    else if (mqrandomNum == 17){
      
      lcd.setCursor(0,1);
       lcd.print ("Good, better, best!       ");
    }

    else if (mqrandomNum == 18){
      
      lcd.setCursor(0,1);
       lcd.print ("Be the change!     ");
    }

    else if (mqrandomNum == 19){
      
      lcd.setCursor(0,1);
       lcd.print ("You got this!     ");
    }

    else if (mqrandomNum == 20){
      
      lcd.setCursor(0,1);
       lcd.print ("Conquer from withtin!       ");
    }
  }


  void relaxQuote (){
    int rqrandomNum = rand() % 20 + 1;

    if (rqrandomNum == 1){
      
      lcd.setCursor(0,1);
       lcd.print ("Take a deep breath..     ");
    }

    else if (rqrandomNum == 2){
      
      lcd.setCursor(0,1);
       lcd.print ("Count to three..     ");
    }

    else if (rqrandomNum == 3){
    
      lcd.setCursor(0,1);
       lcd.print ("no rain, no flowers..    ");
    }

    else if (rqrandomNum == 4){
      
      lcd.setCursor(0,1);
       lcd.print ("It is what it is..       ");
    }

    else if (rqrandomNum == 5){
      
      lcd.setCursor(0,1);
       lcd.print ("It's a new day..      ");
    }

    else if (rqrandomNum == 6){
      
      lcd.setCursor(0,1);
       lcd.print ("Time will tell..             ");
    }

    else if (rqrandomNum == 7){
      
      lcd.setCursor(0,1);
       lcd.print ("This shall pass..     ");
    }

    else if (rqrandomNum == 8){
      
      lcd.setCursor(0,1);
       lcd.print ("Normal is boring..       ");
    }

    else if (rqrandomNum == 9){
      
      lcd.setCursor(0,1);
       lcd.print ("Life goes on..      ");
    }

    else if (rqrandomNum == 10){
      
      lcd.setCursor(0,1);
       lcd.print ("Begin again..      ");
    }

    else if (rqrandomNum == 11){
      
      lcd.setCursor(0,1);
       lcd.print ("make mistakes..    ");
    }

    else if (rqrandomNum == 12){
      lcd.setCursor(0,1);
      
       lcd.print ("Just breathe.. ");
    }

    else if (rqrandomNum == 13){
      
      lcd.setCursor(0,1);
       lcd.print ("One day at a time..       ");
    }

    else if (rqrandomNum == 14){
      
      lcd.setCursor(0,1);
       lcd.print ("a window open..");
    }

    else if (rqrandomNum == 15){
      
      lcd.setCursor(0,1);
       lcd.print ("C'est la vie..       ");
    }

    else if (rqrandomNum == 16){
    
      lcd.setCursor(0,1);
       lcd.print ("One door closes..      ");
    }

    else if (rqrandomNum == 17){
      
      lcd.setCursor(0,1);
       lcd.print ("be happy..      ");
    }

    else if (rqrandomNum == 18){
      
      lcd.setCursor(0,1);
       lcd.print ("love yourself..     ");
    }

    else if (rqrandomNum == 19){
      
      lcd.setCursor(0,1);
       lcd.print ("chill out & unwind..     ");
    }

    else if (rqrandomNum == 20){
      
      lcd.setCursor(0,1);
       lcd.print ("Slow down..       ");
    }
  }
  

