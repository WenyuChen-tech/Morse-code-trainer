# Morse-code-trainer
Group Member:   
Wang Aoli   
Chen Wenyu   
Email:   
aoli.wang@tu-ilmenau.de   
wenyu.chen@tu-ilmenau.de   
    
MorseCodeTrainer_part1.mp4: discription of our project, explanation of hardware setup and test cases.    
MorseCodeTrainer_part2.mp4: explanation of source code.
## 1. Design Phase
### Requirements Analysis
#### 1) General Information
##### 1.1) Purpose

The purpose of this requirements analysis is to provide documentation to the prospective solution of the project “Morse Code Trainer”, and to show necessary elements and functions for this project.

##### 1.2)	Scope

This document will outline the description of Morse Code Trainer, functional and non-functional requirements as the proposed solution for our project.

#### 2) Description

##### 2.1)	Outline

Morse Code is a method use in telecommunication which encode letter a to z and Arabic number 0 to 9 as a sequence of two different signal. Our Morse Code Trainer aim to help users send morse code message more efficiently.

##### 2.2)	Configuration
 
Circuit Diagram: see Morsesketch.fzz


The configuration of the Morse Code Trainer is as follow:

•	Hardware: Arduino UNO microcontroller + Breadboard + LCD + Buzzer speaker + Resistor + Button

•	Software: Fritzing 0.9.3b + Arduino IDE

#### 3) Functional Requirements 

##### 3.1)	Summary of Functions

The Morse Code Trainer requires an embedded system based solution for a program whose primary functions are to:

•	The display shows a random character

•	The beeper beeps corresponding to the users' input to support him via sound

•	The display shows the results (right or wrong)

•	The beeper should produce the correct sequence of beeps corresponding to the character

##### 3.2)	Functional Requirements

In order to accomplish the above articulated needs, the Morse Code Trainer requires the following functionality:
 
•	Ability to show random character on OLED

•	Ability to check if the input is correct

•	Ability to beep according to the input of button and the correct sequence after checking
 
#### 4) Non-Functional Requirements

##### 4.1)	Summary of Non-functional Characters

The non-functional requirements of the Morse Code Trainer describe the system's performance and constraints that enhance its functionality.

##### 4.2)	Non-functional Requirements

###### 4.2.1)	Reliability

•	Simple but high quality system, system works more than 360 days per year. Repairs should be completed in one day in the event of a system failure.

•	Widely used hardware, easy to replace when hardware is damaged.

###### 4.2.1)	High Efficient

•	Fast response, application response in 1s. 

•	Hardware like buzzer and LED can quickly act when receive instructions.
 
###### 4.2.2) 	User Friendly 

•	The design of application interface meets users’ habits.

•	Easy to use machine with simple human-machine interactions. 


## 2. Implematation Phase
### 1) Hardware List
| Modules | Quantity |
| :----:|:----:|
|Breadboard|1|
|Arduino uno|1|
|LCD 16x2 I2C|1|
|Buzzer speaker|1|
|LED|1|
|Button|1|
|Resistors|3|
|Jump Line| many|
### 2) Wiring Method
####  LCD
| LCD | UNO |
| :----:|:----:|
|VCC|5V|
|GND|GND|
|SCL|A4|
|SDA|A5|
####  Button
| Button | UNO |
| :----:|:----:|
|1|A3|
|GND|GND|
####  Buzzer
| Buzzer | UNO |
| :----:|:----:|
|1|A12|
|GND|GND|
####  Red LED
| LED | UNO |
| :----:|:----:|
|1|A2|
|GND|GND|
### 3) Code Explaination
The complete code is in file MoreseCode.ino, there are only some examples.
#### Library we need
```
LiquidCrystal.h   
LiquidCrystal_I2C.h
```
#### Define Pins
Define pins of button, LED, buzzer.
```#define Button 3
#define LED 2
#define Buzzer 12
```
#### Variable Settings
Define variables
```int ButtonValue;
int randNum;                    //for a random character
int change = 1;                 //change when change=1
int str_len;                    //lenth of a morse code letter
int num = 0;                    //compared char
int score = 0;                  //init score
```
### Morse Code
Each letter and its corresponding Morse code.
```
// A to I
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
```
### Check Button
Function ```MakeString()```, to check trainer press a dot '.', a dash '-' or doesn't press.
```
char MakeString()
{
  if (pres_len < 450 && pres_len > 50)
    return '.';                        
  else if (pres_len >= 450)
    return '-';                        
  else
    return 'n';                        
}
```
### Create a random character
Function ```create()```.
```
char create() {
  randNum = random(65,90);
  letter = letters[randNum-65];       
  character=randNum;                  
  Serial.print(character);
  delay(2000);
}
```
### The beeper beeps and LED flashes corresponding to the character
Function ```voice()```.
```
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
```
### Initiate pins 
Codes in ```setup()```
### Main code 
Codes in ```loop()```   
The display shows a random character and the trainer press the button to input the corresponding morse code. The beeper beeps corresponding to the users' input. The display shows the results (Correct or Error). If the input is right, the trainer will get 1 point, if the input is wrong, the beeper will produce the correct sequence of beeps corresponding to the character, and at the same time, the score will be 0.



