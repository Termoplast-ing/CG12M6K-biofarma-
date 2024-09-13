/*
 * File:   ds1307.c
 * Author: Brian Avila
 *
 * Created on 5 de junio de 2020, 19:15
 */


#include <xc.h>
#include <pic18f25k22.h>
#include "ds1307.h"
#define _XTAL_FREQ 4000000
#define BAUDRATE 100000UL
#define VALOR ((_XTAL_FREQ/(4UL*BAUDRATE))-1)

void I2C_init(){
    
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    
    SSP2STAT = 0b10000000;       //Velocidad standart, especificación I2C
	SSP2CON1 =  0b00101000;       //I2C habilitado en modo maestro velocidad=Fosc/(4*SSPADD-1)
	SSP2CON2 = 0x00;
    SSP2CON3 = 0x00;
	SSP2ADD = VALOR;
}

void I2C_start(void){   
   
    SSP2CON2bits.SEN = 1;           //inicia la comunicación i2c
    while((SSP2CON2bits.SEN == 1)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0;
}

void I2C_restart(void){    
   
    SSP2CON2bits.RSEN = 1;          //reinicia la comunicación i2c
    while((SSP2CON2bits.RSEN == 1)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0; 
}

void I2C_stop(void){    
    
    SSP2CON2bits.PEN = 1;           //detener la comunicación i2c
    while((SSP2CON2bits.PEN == 1)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0;
}

char I2C_read(void){
    
    PIR3bits.SSP2IF = 0;         	//clear SSP interrupt bit
    SSP2CON2bits.RCEN = 1;       	//set the receive enable bit to initiate a read of 8 bits from the serial eeprom
    while((PIR3bits.SSP2IF == 0)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0; 	//Espera que la transmisionse complete  
   
        return SSP2BUF;                  //Retorna el dato leido
}

void I2C_ack(void){
    PIR3bits.SSP2IF = 0;            //clear SSP interrupt bit
    SSP2CON2bits.ACKDT = 0;         //clear the Acknowledge Data Bit - this means we are sending an Acknowledge or 'ACK'
    SSP2CON2bits.ACKEN = 1;         //set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
    while((PIR3bits.SSP2IF == 0)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0;  //Wait for interrupt flag to go high indicating transmission is complete
        
    }

void I2C_nack(void){
    PIR3bits.SSP2IF = 0;            //clear SSP interrupt bit
    SSP2CON2bits.ACKDT = 1;         //set the Acknowledge Data Bit- this means we are sending a No-Ack or 'NAK'
    SSP2CON2bits.ACKEN = 1;         //set the ACK enable bit to initiate transmission of the ACK bit to the serial eeprom
    while((PIR3bits.SSP2IF == 0)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0;   // Wait for interrupt flag to go high indicating transmission is complete
    
    }

char  I2C_write(char I2C_data){    
    PIR3bits.SSP2IF = 0;             
    SSP2BUF = I2C_data;              //Envia data por I2C
    while((PIR3bits.SSP2IF == 0)&&(auxRTC<100)){// en la comparacion se cambio el valor maximo de auxRTC de 1000 a 50000
        auxRTC++;
    }
    auxRTC=0;  //Wait for interrupt flag to go high indicating transmission is complete
         
    if(SSP2CON2bits.ACKSTAT)
        return 1;
    
    else
        return 2;
}

void enviar_hora(void){
    
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x00);        //Posición de los segundos
    I2C_write(secS);         //Posición donde va leer
    I2C_write(minS);         //Posición donde va leer
    I2C_write(horaS);        //Posición donde va leer
    I2C_stop();             //Detiene la comunicaión I2C
}

void leer_hora(void){
    
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x00);        //Posición donde va leer
    I2C_restart();          //Reinicia la comuniación I2C
    I2C_write(0xD1);        //Leer posición
    secR = I2C_read();      //lee posicion de reloj
    I2C_ack();
    minR = I2C_read();      //lee posicion de reloj
    I2C_ack();
    horaR = I2C_read();      //lee posicion de reloj
    I2C_nack();
    I2C_stop();             //Termina comunicaion I2C
}

void enviar_fecha(void){
    
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x04);        //Posición de los segundos
    I2C_write(diaS);         //Posición donde va leer
    I2C_write(mesS);         //Posición donde va leer
    I2C_write(anioS);        //Posición donde va leer
    I2C_stop();             //Detiene la comunicaión I2C
}

void leer_fecha(void){
    
    I2C_start();            //Incia comunicaión I2C
    I2C_write(0xD0);        //Escoje dirección del reloj
    I2C_write(0x04);        //Posición donde va leer
    I2C_restart();          //Reinicia la comuniación I2C
    I2C_write(0xD1);        //Leer posición
    diaR = I2C_read();      //lee posicion de reloj
    I2C_ack();
    mesR = I2C_read();      //lee posicion de reloj
    I2C_ack();
    anioR = I2C_read();      //lee posicion de reloj
    I2C_nack();
    I2C_stop();             //Termina comunicaion I2C
}

void converBcdToVar(char horaR, char minR, char secR ){
        hora=(horaR & 0b00001111)+(((horaR>>4)&0b00000011)*10);
        minuto=(minR & 0b00001111)+(((minR>>4)&0b00001111)*10);
        segundo=(secR & 0b00001111)+(((secR>>4)&0b00001111)*10);
    }

/*void converVarToBcd(char hora,char minuto){
        horaS=(hora/10)<<4;
        horaS=(hora%10)+ hora;
        minS=(minuto/10)<<4;
        minS=(minuto%10)+ minuto;
    }*/

void ds1307 (char R_W) {
    
    I2C_init();
    
    if(R_W == 0){
        leer_hora();
        
            converBcdToVar(horaR,minR,secR);
            Segundos = segundo + (minuto * 60) + (hora * 3600);
             
            leer_fecha();  
            
            diaAUX=((diaR>>4)*10)+(diaR&0b00001111);
            mesAUX=((mesR>>4)*10)+(mesR&0b00001111);
            anioAUX=((anioR>>4)*10)+(anioR&0b00001111);
            diaR=diaAUX;
            mesR=mesAUX;
            anioR=anioAUX;
            switch(mesR){
                case 1:{
                    dia=diaR;
                    break;
                }
                case 2:{
                    dia=31+diaR;
                    break;
                }
                case 3:{
                    dia=59+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 4:{
                    dia=90+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 5:{
                    dia=120+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 6:{
                    dia=151+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 7:{
                    dia=181+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 8:{
                    dia=212+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 9:{
                    dia=243+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 10:{
                    dia=273+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 11:{
                    dia=304+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
                case 12:{
                    dia=334+diaR;
                    if((anioR%4)==0){
                        dia=dia+1;
                    }
                    break;
                }
            }
            // dia=((diaR>>4)*10)+(diaR&0b00001111);
            //  mes=((mesR>>4)*10)+(mesR&0b00001111);
            //  anio=((anioR>>4)*10)+(anioR&0b00001111);
        
    }
    
    
    if(R_W == 1){
        if(WRdia0==0){
            enviar_hora();
        }
        diaS=0b00000001;
        mesS=0b00000001;
        anioS=0b00000000;
        enviar_fecha();
        
    }
    
}

    
    
