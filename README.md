# Morse-code-trainer


Morse Code Trainer

Requirements Analysis

Group Member:   Wang Aoli, Chen Wenyu

Email：aoli.wang@tu-ilmenau.de
       
       wenyu.chen@tu-ilmenau.de

1. GENERAL INFORMATION

1.1	Purpose

The purpose of this requirements analysis is to provide documentation to the prospective solution of the project “Morse Code Trainer”, and to show necessary elements and functions for this project.

1.2	Scope

This document will outline the description of Morse Code Trainer, functional and non-functional requirements as the proposed solution for our project.

2. DESCRIPTION

2.1	Outline

Morse Code is a method use in telecommunication which encode letter a to z and Arabic number 0 to 9 as a sequence of two different signal. Our Morse Code Trainer aim to help users send morse code message more efficiently.

2.2	Configuration
 
Circuit Diagram: see Morsesketch.fzz

The configuration of the Morse Code Trainer is as follow:

•	Hardware: Arduino UNO microcontroller + Breadboard + LED + Buzzer speaker + Resistor + Pushbutton

•	Software: Fritzing 0.9.3b + Arduino IDE

3. FUNCTIONAL REQUIREMENTS 

3.1	Summary of Functions

The Morse Code Trainer requires an embedded system based solution for a program whose primary functions are to:

•	The display shows a random character

•	The beeper beeps corresponding to the users' input to support him via sound

•	The display shows the results (right or wrong)

•	The beeper should produce the correct sequence of beeps corresponding to the character

3.2	Functional Requirements

In order to accomplish the above articulated needs, the Morse Code Trainer requires the following functionality:
 
•	Ability to show random character on OLED

•	Ability to check if the input is correct

•	Ability to beep according to the input of button and the correct sequence after checking
 
4. NON-FUNCTIONAL REQUIREMENTS

4.1	Summary of Non-functional Characters

The non-functional requirements of the Morse Code Trainer describe the system's performance and constraints that enhance its functionality.

4.2	Non-functional Requirements

4.2.1	Reliability

•	Simple but high quality system, system works more than 360 days per year. Repairs should be completed in one day in the event of a system failure.

•	Widely used hardware, easy to replace when hardware is damaged.

4.2.1	High Efficient

•	Fast response, application response in 1s. 

•	Hardware like buzzer and LED can quickly act when receive instructions.
 
4.2.2 	User Friendly 

•	The design of application interface meets users’ habits.

•	Easy to use machine with simple human-machine interactions. 



