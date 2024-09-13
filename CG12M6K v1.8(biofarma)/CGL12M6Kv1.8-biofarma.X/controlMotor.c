/*
 * File:   controlMotor.c
 * Author: Brian Avila
 *
 * Created on 6 de junio de 2020, 16:51
 */

#include <xc.h>
#include "controlMotor.h"
#include "ds1307.h"
#define _XTAL_FREQ 4000000

/*void wrEprom(char dir ,char dato){                                             //rutina para escribir eemprom
    
    EEADR = dir;                                                                //seteo la direccion que se va grabar de memori    EEDATA = dato;                                                              //cargo el dato que se va a grabar
    EECON1bits.CFGS = 0;                                                        //se selecta que se va a usar la memoria eeprom
    EECON1bits.EEPGD = 0;                                                       //se selecta que se va a usar la memoria eeprom
    EECON1bits.WRERR = 0;                                                       //pone a cero la bandera de error
    EECON1bits.WREN = 1;                                                        // habilito escritura
    INTCONbits.GIE = 0;                                                         // desabilito las interrupciones
    EECON2 = 0x55;                                                              // destrabo escritura
    EECON2 = 0xAA;                                                              //destrabo escritura
    EECON1bits.WR = 1;                                                          // empiezo escritura
    INTCONbits.GIE = 1;                                                         // habilito la interrupcion
    INTCONbits.PEIE =1;
    EECON1bits.WREN = 0;                                                        // desabilito escritura
    while (EECON1bits.WR){                                                      // espero hasta que WR se haga 0 por hardware(escritura terminada)
    }
}*/
void controlMotor(void) {

    led4=1;
    cantDePaso = 0;


while(cantDePaso>(PasosMotor*100)){
    PORTBbits.RB0=1;
    if((PasosMotor%400)==0){
    ds1307(0);
    }
}
    PORTBbits.RB0=0;
    cantDePaso=0;
/*    
 * PasosMotor/4;
 * for(m = cantDePaso; m > 0 ; m--){
        PORTB = 0b00100001;//0b00010001;
        __delay_ms(15);     //__delay_ms(10);
        PORTB = 0b00001001;//0b00100001;
        __delay_ms(15);     //__delay_ms(10);
        PORTB = 0b00011000;//0b00011000;
        __delay_ms(15);     //__delay_ms(10);
        PORTB = 0b00110000;//0b00011000;
        __delay_ms(15);     //__delay_ms(10);
        if((m%3)==0){
*/              
/*
switch(restoPaso){
    case 1:{
        PORTB = 0b00100001;
        __delay_ms(15);
        break;
    }
    case 2:{
        PORTB = 0b00100001;//0b00010001;
        __delay_ms(15);
        PORTB = 0b00001001;//0b00100001;
        __delay_ms(15);
        break;
    }
    case 3:{
        PORTB = 0b00100001;//0b00010001;
        __delay_ms(15);
        PORTB = 0b00001001;//0b00100001;
        __delay_ms(15);
        PORTB = 0b00011000;//0b00011000;
        __delay_ms(15);
        break;
    }
}*/
//PORTB=PORTB & 0b11000110;
    
habilitaDosis = 0;
ledParpa4=1;
habilitaOptico = 0;

ds1307(0);

ultimaDosis = Segundos;
ultimaDosis1=ultimaDosis;
/*for(ll=0;ll<4;ll++){
    edato=ultimaDosis1;    
    wrEprom(0x0e + ll,edato);
    ultimaDosis1=ultimaDosis1>>8;
}*/
acumulado[0]=acumulado[0]+dosis;
led4=0;
f=0;
seg24=0;
    return;
}
