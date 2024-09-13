/*
 * File:   inicializacion.c
 * Author: Brian Avila
 *
 * Created on 5 de junio de 2020, 18:22
 */


#include <xc.h>
#include "inicializacion.h"
#include "ds1307.h"
#include "calibrar.h"
#define _XTAL_FREQ 4000000

void wrEprom2(char dir , char dato){                                             //rutina para escribir eemprom
    
    EEADR = dir;                                                                //seteo la direccion que se va grabar de memoria
    EEDATA = dato;                                                              //cargo el dato que se va a grabar
    EECON1bits.CFGS = 0;                                                        //se selecta que se va a usar la memoria eeprom
    EECON1bits.EEPGD = 0;                                                       //se selecta que se va a usar la memoria eeprom
    EECON1bits.WRERR = 0;                                                       //pone a cero la bandera de error
    EECON1bits.WREN = 1;                                                        // habilito escritura
    INTCONbits.GIE = 1;//destrabo escritura
    INTCONbits.PEIE =1;                                                         // desabilito las interrupciones
    EECON2 = 0x55;                                                              // destrabo escritura
    EECON2 = 0xAA;     
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;                                                         // habilito la interrupcion
    INTCONbits.PEIE =1;
    while (EECON1bits.WR){                                                      // espero hasta que WR se haga 0 por hardware(escritura terminada)
    }// empiezo escritura
    EECON1bits.WREN = 0; 
    __delay_ms(10);// desabilito escritura
    
}
char rdEprom5(char dir , char dato){
    
        EEADR = dir ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        dato= EEDATA;
        __delay_ms(10);
        return(dato);
}

/*char rdEprom5(char dir){
        char dato;
        EEADR = dir ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        dato= EEDATA;
        return(dato);
}*/

void inicializacion(void) {
    
    TRISA = 0b00111100;                                                               
    TRISB = 0b111110;                                                               
    TRISC = 0x00;                                                               
    ANSELA= 0x00;                                                              
    ANSELB = 0x00;
    ANSELC = 0x00;
    PORTAbits.RA0=1;
    PORTAbits.RA1=1;
    PORTAbits.RA6=1;
    PORTAbits.RA7=1;
    char WhoraRST;
    
    PORTB = 0b000000;                                                           
    PORTC =0xff; 
    

    
   /* for(q = 0; q < 8 ; q++){                                                    //bucle para llamar todos los parametros en memoria eeprom
        EEADR = q ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        switch(q){                                                                  //se le asigna a la variable el valor leido en la posicion 00h de la mem eeprom
            case 0:{
                horaRST= EEDATA;
               break;
            }
            case 1:{
                 minutoRST= EEDATA;
                break;
            }
            case 2:{
                 madres= EEDATA; 
            break;
            }
            case 3:{
                 kilos= EEDATA;
            break;
            }
            case 4:{
                dosis = EEDATA;
            break;
            }
            case 5:{
                fecha[0] = EEDATA;
            break;
            }
            case 6:{
                fecha[1] = EEDATA;
            break;
            }
            case 7:{
                ultimaDosis = EEDATA;
            break;
            }
        }                                                  
    }*/
        
    q = 0;
    PORTC = 0xff;
    auxC = 0xff;
    auxCC = 0xff;
    
    for(q = 0 ; q < 9 ; q++){
        for(j = 0; j<90 ; j++ ){
            for( i=0 ; i<10; i++){
                if(i<6){
                    PORTC= auxC;
                }else{
                    PORTC = auxCC;
                }
                PORTA=(i&0b00000011)+((i<<4)&0b11000000);
                __delay_ms(1);
                PORTAbits.RA0=1;
                PORTAbits.RA1=1;
                PORTAbits.RA6=1;
                PORTAbits.RA7=1;
            }
        }
        auxCC = 0b11111110 << q;
        switch(q){
            case 0:{
                auxC=0b10111111;
                break;
            }
            case 1:{
                auxC=0b10011111;
                break;
            }
            case 2:{
                auxC=0b10001111;
                break;
            }
            case 3:{
                auxC=0b00001111;
                break;
            }
            case 4:{
                auxC=0b00001011;
                break;
            }case 5:{
                auxC=0b00001001;
                break;
            }
            case 6:{
                auxC=0b00001000;
                break;
            }
            case 7:{
                auxC=0b00000000;
                break;
            }
        }
    }
    
    PORTAbits.RA0=1;
    PORTAbits.RA1=1;
    PORTAbits.RA6=1;
    PORTAbits.RA7=1;
    
    PORTC = 0xff;
    
   
    for(i = 0; i < 90 ; i++){
        PORTAbits.RA0=1;
        PORTAbits.RA1=0;
        PORTAbits.RA6=1;
        PORTAbits.RA7=1;
        __delay_ms(10);
        }
    for(i = 0; i < 90 ; i++){
        PORTAbits.RA0=0;
        PORTAbits.RA1=1;
        PORTAbits.RA6=0;
        PORTAbits.RA7=1;
        __delay_ms(10);
        }

    T0CONbits.TMR0ON = 0;                                                       //temporizador apagado
    T0CONbits.T08BIT = 1;                                                       //temporizador de 8 bit
    T0CONbits.T0CS = 0;                                                         //ciclo de reloj interno (CLKOUT)
    T0CONbits.T0SE = 0;                                                         //incrementa en el flanco ascendente T0CKI pin
    T0CONbits.PSA = 0;                                                          //se le asigna un preescaler
    T0CONbits.T0PS = 0b001;                                                     //se configura un preescaler de 8
    TMR0H = 0x00;                                                               //se le asigna 0 al byte mas significativo del carga del timer 0 xq trabaja en 8 bit este
    TMR0L = 0x06;                                                               //se le asigana 6 al byte de carga del timer para un timer de 1ms TMR0 = 256 - ( 2ms / ( 1us x 8))
    INTCONbits.TMR0IF = 0;                                                      //pone a 0 el flag de desbordamiento del timer, cuando se desborda se pone a 1 
    INTCONbits.TMR0IE = 1;                                                      //en 1 habilita la interrupcion por desbordamiento
    INTCON2bits.TMR0IP = 0;                                                     //en 1 lo asigna como alta prioridad al timer
    RCONbits.IPEN = 1;                                                          //habilita la prioridad de niveles de interrupcion
    INTCONbits.GIEH = 1;                                                        //habilita todas las interruciones de alta prioridad  
    INTCONbits.GIEL = 1;
    T0CONbits.TMR0ON = 1; 

    
    //__delay_ms(100);
    
     if((PORTAbits.RA3==1)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==0)){
     //   __delay_ms(1000);
    }
    if((PORTAbits.RA3==1)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==0)){
        calibrar();
    }
    
    
    
    T0CONbits.TMR0ON = 0;
    INTCONbits.TMR0IE = 0;
    INTCONbits.GIEH = 0;                                                        //habilita todas las interruciones de alta prioridad  
    INTCONbits.GIEL = 0;
    
    
    
        do{
        madres=rdEprom5(0x00,auxiliar);
        if(cantLect>5){
            madres=12;
        }
        cantLect++;
    }while((madres<7)&&(madres>12));
    
    cantLect=0;
    
    do{
        kilos=rdEprom5(0x01,auxiliar);
        if(cantLect>5){
            kilos=60;
        }cantLect++;
    }while((kilos<1)&&(kilos>60));
    
    cantLect=0;
    
    do{
        manual=rdEprom5(0x02,auxiliar);
        if(manual==1){
            led1=1;
        }else{
            led1=0;
        }
        if(cantLect>5){
            manual=0;
            led1=0;
        }
        cantLect++;
    }while(manual>1);
    
    cantLect=0;
   
    do{
        horaRST=rdEprom5(0x06,auxiliar);
        horaRST=(horaRST<<8)+ rdEprom5(0x05,auxiliar);
        horaRST=(horaRST<<8)+ rdEprom5(0x04,auxiliar);
        horaRST=(horaRST<<8)+ rdEprom5(0x03,auxiliar);
        if(cantLect>5){
            horaRST=12;
        }
        cantLect++;
    }while(horaRST>24);
    
    cantLect=0;
    
    do{
        minutoRST=rdEprom5(0x0a,auxiliar);
        minutoRST=(minutoRST<<8)+ rdEprom5(0x09,auxiliar);
        minutoRST=(minutoRST<<8)+ rdEprom5(0x08,auxiliar);
        minutoRST=(minutoRST<<8)+ rdEprom5(0x07,auxiliar);
        if(cantLect>5){
            minutoRST=00;
        }
        cantLect++;
    }while(horaRST>59);
    
    cantLect=0;
    
    do{
        dosis=rdEprom5(0x0b,auxiliar);
        if(cantLect>5){
            dosis=50;
        }
        cantLect++;
    }while((dosis<5)&&(dosis>95));
    
    cantLect=0;
    
    do{
        PasosMotor=rdEprom5(0x0d,auxiliar);
        PasosMotor=(PasosMotor<<8)+rdEprom5(0x0c,auxiliar);
        if(cantLect>5){
            PasosMotor=500;
        }
        cantLect++;
    }while((PasosMotor<1)||(PasosMotor>10000));
    
    cantLect=0;
    
    do{
        ultimaDosis=rdEprom5(0x11,auxiliar);
        ultimaDosis=(ultimaDosis<<8)+ rdEprom5(0x10,auxiliar);
        ultimaDosis=(ultimaDosis<<8)+ rdEprom5(0x0f,auxiliar);
        ultimaDosis=(ultimaDosis<<8)+ rdEprom5(0x0e,auxiliar); 
        if(cantLect>5){
            ultimaDosis=0;
        }
        cantLect++;
    }while(ultimaDosis>87000);
    
    cantLect=0;
    
    do{
        diaActual=rdEprom5(0x13,auxiliar);
        diaActual=(diaActual<<8)+rdEprom5(0x12,auxiliar);
        if(cantLect>5){
            diaActual=1;
        }
        cantLect++;
    }while(diaActual>367);
    
    cantLect=0;
    
    for(q = 0; q < 31 ; q++){
        do{
          //  acumulado[q]=rdEprom5(0x67+(q*4),auxiliar);
          //  acumulado[q]=(acumulado[q]<<8)+rdEprom5(0x66+(q*4),auxiliar);
          //  acumulado[q]=(acumulado[q]<<8)+rdEprom5(0x65+(q*4),auxiliar);
          //  acumulado[q]=(acumulado[q]<<8)+rdEprom5(0x64+(q*4),auxiliar);
            
            auxiliar=rdEprom5(0x67+(q*4),auxiliar);
            auxiliar=(auxiliar<<8)+rdEprom5(0x66+(q*4),auxiliar);
            auxiliar=(auxiliar<<8)+rdEprom5(0x65+(q*4),auxiliar);
            auxiliar=(auxiliar<<8)+rdEprom5(0x64+(q*4),auxiliar);
            acumulado[q]=auxiliar;
            if(cantLect>5){
                acumulado[q]=0;
            }
            cantLect++;
        }while(acumulado[q]>72000);
        cantLect=0;
  }
    
    T0CONbits.TMR0ON = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIEH = 1;                                                        //habilita todas las interruciones de alta prioridad  
    INTCONbits.GIEL = 1;
    
   // madres= 12;
    //kilos=60;
   // acumulado[0]=0;
    R_W = 0;
    
    
        WRdia0=1;
        
        ds1307(0);
        
        WRdia0=0;
        
        horaAux=hora;
        
    if(dosis>95){
        dosis=0;
    }
   /* wrEprom2( 0x0b,50);
    wrEprom2(0x0c ,0xc8);
    wrEprom2(0x0d ,0x00);
    horaRST=12;
    wrEprom2(0x00,0x12);
    minutoRST=00;
    wrEprom2(0x01,0x00);*/
    
    
    
        
    return;
}
