/*
 * File:   3x4Keypad.c
 * Author: amr gouda
 *
 * Created on December 24, 2021, 5:49 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>

int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;

void main(void) {
    //Defining the output pins (columns) 
    TRISD0=0;// First column
    TRISD1=0;// Second column
    TRISD2=0;// Third column
    TRISD3=0;// Fourth column
    //Defining the input pins (rows)
    TRISD4=1;// First row
    TRISD5=1;// Second row
    TRISD6=1;// Third row
    TRISD7=1;// Fourth row
    //Output pin to indicate the status of the entered password (right or wrong)
    TRISB1=0;
    

    while(RB1==0){
    
        //Only the first column is turned on
        RD0=1;// First column
        RD1=0;// Second column
        RD2=0;// Third column
        RD3=0;// Fourth column
        
        
          //Checking if the required key within the first column is pressed
          //The first character of the password is assumed to be '1'
          if(RD4==1){  
            flag1=1;
        }else if(RD5==1||RD6==1||RD7==1){  //another key within the first column is pressed
            flag1=2;
        }    
            
        
        
        
        if (flag1==1 || flag1==2){
        //Only the second column is turned on
        RD0=0;// First column
        RD1=1;// Second column
        RD2=0;// Third column
        RD3=0;// Fourth column
        
        
            //Checking if the required key within the second column is pressed
            //The second character of the password is assumed to be '5'
            if(RD5==1){
            flag2=1;
                       }
            else if(RD4==1|| RD6==1|| RD7==1) {
            flag2=2;
            }
        }
        
        if (flag2==1 || flag2==2){
        //Only the third column is turned on
        RD0=0;// First column
        RD1=0;// Second column
        RD2=1;// Third column
        RD3=0;// Fourth column
        
        
        //Checking if the required key within the third column is pressed
        //The third character of the password is assumed to be '9'
        if(RD6==1){
            flag3=1;// The third character is correctly detected
        }else if(RD4==1|| RD5==1|| RD7==1){
            flag3=2;
        } }   // another key within the third column is pressed

        
        if (flag3==1 || flag3==2){
        //Only the fourth column is turned on
        RD0=0;// First column
        RD1=0;// Second column
        RD2=0;// Third column
        RD3=1;// Fourth column
        
        //Checking if the required key within the fourth column is pressed
        //The fourth character of the password is assumed to be 'D'
        if(RD7==1){
            flag4=1;//The fourth character is correctly detected
        }else if(RD4==1|| RD5==1|| RD6==1){ 
            flag4=2;
        } }   //another key within the fourth column is pressed
        //Checking the overall password
        if(flag4==1 && flag3==1 && flag2==1 && flag1==1){
            RB1=1;
            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
            break;//The password is entered correctly
        }else if(flag1==2||flag2==2||flag3==2||flag4==2){ 
            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
        }    //The password is entered wrongly
 
    }
        while (RB1==1){
        
        //Only the first column is turned on
        RD0=1;// First column
        RD1=0;// Second column
        RD2=0;// Third column
        RD3=0;// Fourth column
        
        //Checking if the required key within the first column is pressed
        //The first character of the password is assumed to be '1'
          if(RD4==1){
            flag1=1;
        }else if(RD5==1||RD6==1||RD7==1){  //another key within the first column is pressed
            flag1=2;
        }    
        
        
        
        if (flag1==1 || flag1==2){
        //Only the second column is turned on
        RD0=0;// First column
        RD1=1;// Second column
        RD2=0;// Third column
        RD3=0;// Fourth column
        
        //Checking if the required key within the second column is pressed
        //The second character of the password is assumed to be '5'
            if(RD5==1){
            flag2=1;
                       }
            else if(RD4==1|| RD6==1|| RD7==1) {
            flag2=2;
            }
        }
        
        if (flag2==1 || flag2==2){
        //Only the third column is turned on
        RD0=0;// First column
        RD1=0;// Second column
        RD2=1;// Third column
        RD3=0;// Fourth column
        
        
               
         //Checking if the required key within the third column is pressed
        //The third character of the password is assumed to be '9'
        if(RD6==1){
            flag3=1;// The third character is correctly detected
        }else if(RD4==1|| RD5==1|| RD7==1){
            flag3=2;
        } }   // another key within the third column is pressed

        
        if (flag3==1 || flag3==2){
        //Only the fourth column is turned on
        RD0=0;// First column
        RD1=0;// Second column
        RD2=0;// Third column
        RD3=1;// Fourth column
        
        //Checking if the required key within the fourth column is pressed
        //The fourth character of the password is assumed to be 'D'
        if(RD7==1){
            flag4=1;//The fourth character is correctly detected
        }else if(RD4==1|| RD5==1|| RD6==1){ 
            flag4=2;
        } }   //another key within the fourth column is pressed
        //Checking the overall password
        if(flag4==1 && flag3==1 && flag2==1 && flag1==1){
            RB1=0;
            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
            break;//The password is entered correctly
        }else if(flag1==2||flag2==2||flag3==2||flag4==2){ 
            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
        }    //The password is entered wrongly

    }
return;}