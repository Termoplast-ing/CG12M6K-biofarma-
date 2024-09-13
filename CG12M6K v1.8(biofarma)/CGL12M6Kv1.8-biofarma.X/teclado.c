/*
 * File:   teclado.c
 * Author: Brian Avila
 *
 * Created on 27 de junio de 2020, 10:56
 */

#include <xc.h>
#define _XTAL_FREQ 4000000
#include "teclado.h"

void teclado(void) {
    
    tecla=PORTA&0b00111000;
    tecla=tecla>>3;
    if(tecla<8){
    __delay_ms(10);
    }else{
        tecla=0;
    }
    
    
    tecla=PORTA&0b00111000;
    tecla=tecla>>3;
    if(tecla<8){

    switch(tecla){
        case 6:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 1)){
                tecla1++;
            }else{
                tecla1=0;
            }
            break;
        }
        case 5:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 1)){
                tecla2++;
            }else{
                tecla2=0;
            }
            break;
        }
        case 4:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 1)){
                tecla3++;
            }else{
                tecla3=0;
            }
            break;
        }
        case 3:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 0)){
                tecla4++;
            }else{
                tecla4=0;
            }
            break;
        }
        case 2:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 0)){
                tecla5++;
            }else{
                tecla5=0;
            }
            break;
        }
        case 1:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 0)){
                tecla6++;
            }else{
                tecla6=0;
            }
            break;
        }
        case 0:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 0)){
                tecla7++;
            }else{
                tecla7=0;
            }
            break;
        }
    }
    
        
        if(tecla1 > 10){
            if(tecla1 > 200){
                tecla1=20;
            }
            accionTecla=1;
            tecla1=0x00;
        }
        if(tecla2 > 10){
            if(tecla2 > 200){
                tecla2=20;
            }
            accionTecla=2;
            tecla2=0x00;
        }
        if(tecla3 > 10){
            if(tecla3 > 200){
                tecla3=20;
            }
            accionTecla=3;
            tecla3=0x00;
        }
        if(tecla4 > 10){
            if(tecla4 > 200){
                tecla4 = 20;
            }
            accionTecla=4;
            tecla4=0x00;
        }
    if(tecla5>200){
        tecla5 = 101;
    }
    if(tecla6>200){
        tecla6 = 101;
    }
    if(tecla7>200){
        tecla7 = 101;
    }
    
    
    if((PORTAbits.RA3 == 1)&&(PORTAbits.RA4 == 1)&&(PORTAbits.RA5 == 1)){
        
        if(tecla5 > 10){
            accionTecla=5;
            if(tecla5 > 100){
                accionTecla = 8;
            }
            tecla5=0x00;
        }
        if(tecla6 > 10){
            accionTecla = 6;
            if(tecla6 > 100){
                accionTecla=9;
            }
            tecla6 = 0x00;
        }
        if(tecla7 > 10){
            accionTecla = 7;
            if(tecla7 > 100){
                accionTecla=10;
            }
            tecla7 = 0x00;
        }
    }
    }/*
        switch(tecla){
        case 6:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 1)){
                if(tecla1>0)
            }else{
                tecla = 0;
                accionTecla = 0;
            }
            break;
        }
        case 5:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 1)){
                accionTecla = 2;
            }else{
                tecla = 0;
                accionTecla = 0;
            }
            break;
        }
        
        case 4:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 1)){
                accionTecla = 3;
            }else{
                tecla=0;
            }
            break;
        }
        
        case 3:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 0)){
                accionTecla = 4;
            }else{
                tecla=0;
            }
            break;
        }
        
        case 2:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 0)){
                tecla5++;
                if(tecla5>20){
                    tecla5=10;
                }
            break;
        }
        }
        case 1:{
            if((PORTAbits.RA3 == 1) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 0)){
             tecla6++;
                if(tecla6>20){
                    tecla6=10;
                }
            break;
        }
        }
        case 0:{
            if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 0) && (PORTAbits.RA5 == 0)){
                tecla7++;
                if(tecla7>20){
                    tecla7=10;
                }
            break;
        }
    }
        }
        if((PORTAbits.RA3 == 1)&&(PORTAbits.RA4 == 1)&&(PORTAbits.RA5 == 1)){
            if(tecla5>0){
                if(tecla5>10){
                    accionTecla=8;
                    tecla5=0;
                }else{
                accionTecla = 5;
                tecla5=0;
                }
            }
            if(tecla6>0){
                if(tecla6>10){
                    accionTecla=9;
                    tecla6=0;
                }else{
                accionTecla = 6;
                tecla6=0;
                }
            }
            if(tecla7>0){
                if(tecla7>10){
                    accionTecla=10;
                    tecla7=0;
                }else{
                accionTecla = 7;
                tecla7=0;
                }
            }
        }
    }*/
    return;
}
