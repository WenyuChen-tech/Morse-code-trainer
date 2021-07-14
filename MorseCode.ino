#include <LiquidCrystal.h>

#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//define pins
#define Button 3
#define LED 2
#define Buzzer 12


int ButtonValue;
int randNum;                    //for a random character
int change = 1;                 //change when change=1
int str_len;                    //lenth of a morse code letter
int num = 0;                    //compared char
int score = 0;                  //init score

unsigned long pres_len = 0, rel_time, pres_time = 0, old_pres = 0;

char morse;//.or-
String letter;//morse code letter
char character;

String letters[26]={
// A to I
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

char MakeString()
{
  if (pres_len < 450 && pres_len > 50)
    return '.';                        //if button press less than 0.6sec, it is a dot
  else if (pres_len >= 450)
    return '-';                        //if button press more than 0.6sec, it is a dash
  else
    return 'n';                        //if button haven't pressed
}

char create() {
  randNum = random(65,90);
  letter = letters[randNum-65];       //create a character morse code  = .-
  character=randNum;                  // = A
  Serial.print(character);
  delay(2000);
}

void voice(){
  for(int i=0;i<str_len;i++)
  {
    if (letter.charAt(i)=='.')
    {
      digitalWrite(LED, HIGH);
      tone(Buzzer, 1000);
      delay(400);
    }
    else
    {
      digitalWrite(LED, HIGH);
      tone(Buzzer, 1000);
      delay(700);
    }
    digitalWrite(LED, LOW);
    noTone(Buzzer);
    delay(400);
  }
}

void setup() {
 
  Serial.begin(9600);
  
  pinMode(Button, INPUT);

  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.backlight();
  lcd.init();
  
  randomSeed(analogRead(0));

}



void loop() {
  ButtonValue = digitalRead(Button);
  
  if(change == 1){
    create();                        //create a character
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(character);           //print character
    lcd.setCursor(14, 0);
    lcd.print(score);               //A           0
    str_len = letter.length();      //length of the morse code of character
    num = 0;                        //move compared place to 0
    change = 0;
  }
  
  if (change == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(character);           //unchange character
    lcd.setCursor(14, 0);
    lcd.print(score);               //A           0
  }
  
  if (ButtonValue != 0){
    old_pres = rel_time;            //start time = last timestamp of LOW
    pres_time = millis();
    digitalWrite(LED, HIGH);
    tone(Buzzer, 1000);
  }
  else 
  {
    rel_time = millis();
    digitalWrite(LED, LOW); 
    noTone(Buzzer);
    pres_len = pres_time-old_pres;  //pres_time = last timestamp of HIGH = finish time of HIGH
    morse = MakeString();           //.or-or n
    pres_time = 0;
    old_pres = 0;
    pres_len = 0;
    if(morse == 'n')
    { 
    }
    else if(morse == '.'||morse == '-')
    {
      if(morse == letter.charAt(num))     //correct
      {
        num++;                            //input correct, ready to compare next code
        if(num == str_len)
        {
          change = 1;                     //all code correct, creat a new character
          score++;
          lcd.setCursor(0, 0);
          lcd.print("Correct!");
          lcd.setCursor(14, 0);
          lcd.print(score);               //A           1
          delay(2000);
        }
      }
      else if(morse != letter.charAt(num)){
        change = 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error!");
        lcd.setCursor(14, 0);
        lcd.print(score);           //Error!      1
        delay(3000);
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(character);       //show character
        lcd.setCursor(14, 0);
        lcd.print(score);           //A           1
                                    //.-
        lcd.setCursor(0, 1);
        lcd.print(letter);
        voice();                    //show correct morse code
        morse='n';
        score = 0;                  //fail score = 0
        delay(2000);
      }
    }
    morse = 'n';
  }
}
