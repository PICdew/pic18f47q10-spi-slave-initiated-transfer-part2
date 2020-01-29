/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB             :  MPLAB X 5.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"




void (*IOCAF4_InterruptHandler)(void);
void (*IOCBF4_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x05;
    LATD = 0x00;
    LATA = 0x10;
    LATB = 0x10;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x06;
    TRISA = 0xFF;
    TRISB = 0xF7;
    TRISC = 0xDF;
    TRISD = 0xFE;

    /**
    ANSELx registers
    */
    ANSELD = 0xFE;
    ANSELC = 0xC7;
    ANSELB = 0xE7;
    ANSELE = 0x02;
    ANSELA = 0xCF;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x04;
    WPUB = 0x10;
    WPUA = 0x10;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCAF - flag
    IOCAFbits.IOCAF4 = 0;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN4 = 1;
    //interrupt on change for group IOCAP - positive
    IOCAPbits.IOCAP4 = 1;
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF4 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN4 = 0;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP4 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCK1;    
    RD0PPS = 0x0B;   //RD0->EUSART2:TX2;    
    SSP1SSPPS = 0x05;   //RA5->MSSP1:SS1;    
    RC5PPS = 0x10;   //RC5->MSSP1:SDO1;    
    SSP1DATPPS = 0x14;   //RC4->MSSP1:SDI1;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCAF4
    if(IOCAFbits.IOCAF4 == 1)
    {
        IOCAF4_ISR();  
    }	
	// interrupt on change for pin IOCBF4
    if(IOCBFbits.IOCBF4 == 1)
    {
        IOCBF4_ISR();  
    }	
}

/**
   IOCAF4 Interrupt Service Routine
*/
void IOCAF4_ISR(void) {

    // Add custom IOCAF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF4_InterruptHandler)
    {
        IOCAF4_InterruptHandler();
    }
    IOCAFbits.IOCAF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF4 at application runtime
*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF4
*/
void IOCAF4_DefaultInterruptHandler(void){
    // add your IOCAF4 interrupt custom code
    // or set custom function using IOCAF4_SetInterruptHandler()
}

/**
   IOCBF4 Interrupt Service Routine
*/
void IOCBF4_ISR(void) {

    // Add custom IOCBF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF4_InterruptHandler)
    {
        IOCBF4_InterruptHandler();
    }
    IOCBFbits.IOCBF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF4 at application runtime
*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF4
*/
void IOCBF4_DefaultInterruptHandler(void){
    // add your IOCBF4 interrupt custom code
    // or set custom function using IOCBF4_SetInterruptHandler()
}

/**
 End of File
*/