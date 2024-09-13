#include <xc.h>
#include "calibrar.h"
#include "ds1307.h"
#define _XTAL_FREQ 4000000

void wrEprom7(char dir , char dato){                                             //rutina para escribir eemprom
    
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
    INTCONbits.PEIE =1;                                                                     // empiezo escritura                                                       // desabilito escritura
    while (EECON1bits.WR){                                                      // espero hasta que WR se haga 0 por hardware(escritura terminada)
    }
    EECON1bits.WREN = 0; 
    __delay_ms(10);
}

void calibrar(void) {
    
    dis[0]=0xff;
    dis[1]=0xff;
    dis[2]=0xff;
    dis[3]=0xff;
    dis[4]=0xff;
    dis[5]=0xff;
    dis[6]=0xff;
    dis[7]=0xff;
    dis[8]=0xff;
    dis[9]=0xff;
    
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x01){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==0)&&(PORTAbits.RA4==1)&&(PORTAbits.RA5==1)){
            dis[0]=0x00;
            dis[1]=0x00;
        }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x02){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==1)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==1)){
            dis[3]=0x00;
            dis[4]=0x00;
        }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x03){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==0)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==1)){
            dis[6]=0x00;
            dis[7]=0x00;
        }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x04){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==1)&&(PORTAbits.RA4==1)&&(PORTAbits.RA5==0)){
            dis[8]=0x00;
            dis[9]=0x00;
        }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x05){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==0)&&(PORTAbits.RA4==1)&&(PORTAbits.RA5==0)){
            led4=1;
        }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x06){
        __delay_ms(5);
        auxINI=(~(PORTA>>3))&0x07;
        if((PORTAbits.RA3==1)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==0)){
            led1=1;
            }
    }
    __delay_ms(5);
    auxINI=(~(PORTA>>3))&0x07;
    while(auxINI != 0x07){
        auxINI=(~(PORTA>>3))&0x07;
    }
        led1=0;
        led4=0;
        dis[0]=0x89;
        dis[1]=0x6a;
        dis[2]=0xff;
        dis[3]=0x78;
        dis[4]=0x6a;
        dis[5]=0xff;
        dis[6]=0x2f;
        dis[7]=0xa4;
        dis[8]=0xc0;
        dis[9]=0xc0;
        
    while(PORTAbits.RA2==0){
        
    }
        while(PORTAbits.RA2==1){
        
    }
        while(PORTAbits.RA2==0){
        
    }
    __delay_ms(5);
    if(PORTAbits.RA2==1){
        for(mm = 50; mm > 0 ; mm--){
        PORTB = 0b00100001;//0b00010001;
        __delay_ms(20);
        PORTB = 0b00001001;//0b00100001;
        __delay_ms(20);
        PORTB = 0b00011000;//0b00011000;
        __delay_ms(20);
        PORTB = 0b00110000;//0b00011000;
        __delay_ms(20);
        }
    }
    
    T0CONbits.TMR0ON = 0;
    INTCONbits.TMR0IE = 0;
    INTCONbits.GIEH = 0;                                                        //habilita todas las interruciones de alta prioridad  
    INTCONbits.GIEL = 0;
    
    wrEprom7( 0x00,0x0c);
    madres=12;
        wrEprom7( 0x01,0x3c);
        kilos=60;
            wrEprom7( 0x02,0x00);
            manual=0;
                horaRST=12;
                wrEprom7( 0x03,0x0c);
                wrEprom7( 0x04,0x00);
                wrEprom7( 0x05,0x00);
                wrEprom7( 0x06,0x00);
                    minutoRST=0;
                    wrEprom7( 0x07,0x00);
                    wrEprom7( 0x08,0x00);
                    wrEprom7( 0x09,0x00);
                    wrEprom7( 0x0a,0x00);
                        dosis=50;
                        wrEprom7( 0x0b,0x32);
                            PasosMotor=200;
                            wrEprom7( 0x0c,0xc8);
                            wrEprom7( 0x0d,0x00);
                                ultimaDosis=0;
                                wrEprom7( 0x0e,0x00);
                                wrEprom7( 0x0f,0x00);
                                wrEprom7( 0x10,0x00);
                                wrEprom7( 0x11,0x00);
                                    diaActual=0;
                                    wrEprom7( 0x12,0x00);
                                    wrEprom7( 0x13,0x00);
                                        for(mm = 0 ; mm < 31 ; mm ++){
                                            acumulado[mm] = 0;
                                            wrEprom7(((mm*0x04)+0x64),0 );
                                            wrEprom7((0x01+(mm*0x04)+0x64),0 );
                                            wrEprom7((0x02+(mm*0x04)+0x64),0 );
                                            wrEprom7((0x03+(mm*0x04)+0x64),0 );
                                        }
    WRdia0=1;
    ds1307(1);
    return;
}
