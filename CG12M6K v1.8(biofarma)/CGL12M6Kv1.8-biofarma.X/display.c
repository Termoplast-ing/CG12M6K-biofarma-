/*
 * File:   display.c
 * Author: Admin
 *
 * Created on 29 de julio de 2020, 10:19
 */


#include <xc.h>
#include "display.h"

    char conv7Seg(char dig){
    switch (dig) {
        case 0:{//0
            digitos = 0xc0;
            break;
        }case 1:{//1
            digitos = 0xf9;
            break;
        }
        case 2:{//2
            digitos = 0xa4;
            break;
        }
        case 3:{//3
            digitos = 0xb0;
            break;
        }
        case 4:{//4
            digitos = 0x99;
            break;
        }
        case 5:{//5
            digitos = 0x92;
            break;
        }
        case 6:{//6
            digitos = 0x82;
            break;
        }
        case 7:{//7
            digitos = 0xf8;
            break;
        }
        case 8:{//8
            digitos = 0x80;
            break;
        }
        case 9:{//9
            digitos = 0x90;
            break;
        }//* significa  que para los display dispuestos la mitad corrida
        case 10:{//0*
            digitos = 0x09;
            break;
        }case 11:{//1*
            digitos = 0xcf;
            break;
        }
        case 12:{//2*
            digitos = 0x1a;
            break;
        }
        case 13:{//3*
            digitos = 0x0e;
            break;
        }
        case 14:{//4*
            digitos = 0xcc;
            break;
        }
        case 15:{//5*
            digitos = 0x2c;
            break;
        }
        case 16:{//6*
            digitos = 0x28;
            break;
        }
        case 17:{//7*
            digitos = 0x8f;
            break;
        }
        case 18:{//8*
            digitos = 0x08;
            break;
        }
        case 19:{//9*
            digitos = 0x0c;
            break;
        }
    }
    return(digitos);
}

void convBCD2C(char bcd2,char dign,char dignn,char puntoDec){
    dig0 = bcd2/10;
    dig1 = bcd2%10;
    if(dign<7){
        dig0=dig0+10;
    }
    if(dignn<7){
        dig1=dig1+10;
    }
    dis[dign]=conv7Seg(dig0);
    dis[dignn]=conv7Seg(dig1);
    if(puntoDec == 1){
        dis[dign]=dis[dign]&0b11110111;
    }
    if(puntoDec == 2){
        dis[dignn]=dis[dignn]&0b11110111;
    }
    if(puntoDec == 0){
    }    
}

void convBCD5C(unsigned long bcd5){
    dig0 = bcd5/10000;
    dig1 = (bcd5%10000)/1000;
    dig2 = (bcd5%1000)/100;
    dig3 = (bcd5%100)/10;
    dig4 = (bcd5%10);
    if(dig0==0){
        dis[6]=conv7Seg(dig1);
        dis[6]=dis[6] - 0x80;
        dis[7]=conv7Seg(dig2);
        dis[8]=conv7Seg(dig3);
        dis[9]=conv7Seg(dig4);
    }else{
        dis[6]=conv7Seg(dig0);
        dis[7]=conv7Seg(dig1);
        dis[7]=dis[7] - 0x80;
        dis[8]=conv7Seg(dig2);
        dis[9]=conv7Seg(dig3);
    }
}

void display(void) {
    

    
    switch(selMenu){
        case 0:{
            if(((msjDiaFin>0)&&(msjDiaFin<50))||((diaTerminado==1)&&(manual==1))){
                msjDiaFin++;
                dis[0]=0x4a;
                dis[1]=0x3b;
                dis[3]=0x0a;
                dis[4]=0xff;
                dis[6]=0x87;
                dis[7]=0x84;
                dis[8]=0xaf;
                dis[9]=0x48;
                if(msjDiaFin>14){
                    msjDiaFin = 0;
                }
                
            }else{
            if(diaMostrado == 0){
                convBCD2C(madres,0,1,0);
                convBCD2C(kilos,3,4,1);
                convBCD5C(acumulado[0]);
            }else{
                convBCD2C(diaMostrado,0,1,0);
                dis[3]=0xff;
                dis[4]=0xff;
               // dis[6]=0xff;
                convBCD5C(acumulado[diaMostrado]);
            }
            }
            break;
        }
        case 1:{
            dis[0] = 0x39;
            dis[1] = 0x0a;
            dis[3] = 0x79;
            dis[4] = 0xf7;
            dis[6] = 0x09;
            dis[7] = 0xad;
            dis[8] = 0xc8;
            dis[9] = 0x66;
            break;
        }
        case 2:{
            dis[0] = 0x39;
            dis[1] = 0x0a;
            dis[3] = 0x79;
            dis[4] = 0xf7;
            dis[6] = 0x09;
            dis[7] = 0xaf;
            dis[8] = 0x92;
            dis[9] = 0x07;
            break;
        }
        case 3:{
            dis[0] = 0x39;
            dis[1] = 0x0a;
            dis[3] = 0x79;
            dis[4] = 0xf7;
            dis[6] = 0xa1;
            dis[7] = 0xa3;
            dis[8] = 0x92;
            dis[9] = 0xe6;
            break;
        }
        case 4:{
            if(xDefecto == 0){
                dis[0] = 0xea;
                dis[1] = 0x6a;
            }else{
                dis[0] = 0x2c;
                dis[1] = 0xbb;
            }
            dis[3] = 0x4a;
            dis[4] = 0x18;
            dis[6] = 0x8e;
            dis[7] = 0xa0;
            dis[8] = 0xe3;
            dis[9] = 0xc7;
            break;
        }
        case 6:{
            dis[0] = 0xfa;
            dis[1] = 0x18;
            dis[3] = 0x2c;
            dis[4] = 0x18;
            dis[6] = 0x87;
            dis[7] = 0xff;
            dis[8] = 0xff;
            dis[9] = 0xff;
            break;
        }
        case 16:{
            dis[0] = 0xfa;
            dis[1] = 0x18;
            dis[3] = 0x2c;
            dis[4] = 0x18;
            dis[6] = 0x87;
            dis[7] = 0xff;
            if(ReseteoAux==0){
                dis[8] = 0xab;
                dis[9] = 0xa3;
            }
            if(ReseteoAux==1){
                dis[8] = 0x92;
                dis[9] = 0x66;
            }
            break;
        }
        case 11:{
            
            auxSelec++;
            if(auxSelec >100){
                auxSelec = 0;
            }
            
            if((auxSelec < 50)&(digito == 0)){
                dis[0]=0xff;
            }else{
                dis[0]=conv7Seg(digito0 + 10); 
            }
            if((auxSelec < 50)&(digito == 1)){
                dis[1]=0xff;
            }else{
                dis[1]=conv7Seg(digito1 + 10);               
            }
            if((auxSelec < 50)&(digito == 2)){
                dis[3]=0xff;
            }else{
                dis[3]=conv7Seg(digito2 + 10); 
            }
            if((auxSelec < 50)&(digito == 3)){
                dis[4]=0xff;
            }else{
                dis[4]=conv7Seg(digito3 + 10);
                
            }
            dis[6] = 0xff;
            dis[7] = 0xff;
            dis[8] = 0xff;
            dis[9] = 0xff;
            break;
        }
        case 12:{
            auxSelec++;
            if(auxSelec >100){
                auxSelec = 0;
            }
            
            if((auxSelec < 50)&(digito == 0)){
                dis[0]=0xff;
            }else{
                dis[0]=conv7Seg(digito0 + 10); 
            }
            if((auxSelec < 50)&(digito == 1)){
                dis[1]=0xff;
            }else{
                dis[1]=conv7Seg(digito1 + 10);               
            }
            if((auxSelec < 50)&(digito == 2)){
                dis[3]=0xff;
            }else{
                dis[3]=conv7Seg(digito2 + 10); 
            }
            if((auxSelec < 50)&(digito == 3)){
                dis[4]=0xff;
            }else{
                dis[4]=conv7Seg(digito3 + 10);
                
            }
            dis[6] = 0xff;
            dis[7] = 0xff;
            dis[8] = 0xff;
            dis[9] = 0xff;
            break;
        }
        case 13:{
            auxSelec++;
            if(auxSelec >100){
                auxSelec = 0;
            }
            
            if((auxSelec < 50)&(digito == 0)){
                dis[6]=0xff;
            }else{
                dis[6]=conv7Seg(digito0); 
            }
            if((auxSelec < 50)&(digito == 1)){
                dis[7]=0xff;
            }else{
                dis[7]=conv7Seg(digito1);               
            }
            if((auxSelec < 50)&(digito == 2)){
                dis[8]=0xff;
            }else{
                dis[8]=conv7Seg(digito2); 
            }
            if((auxSelec < 50)&(digito == 3)){
                dis[9]=0xff;
            }else{
                dis[9]=conv7Seg(digito3);
                
            }
            dis[3] = 0xff;
            dis[4] = 0xff;
            dis[5] = 0xff;
            
            convBCD2C(dosisAux,0,1,0);
            
            break;
        }
        case 14:{
            auxSelec++;
            if(auxSelec >100){
                auxSelec = 0;
            }
            if(auxSelec < 50){
                if(xDefecto == 0){
                    dis[0] = 0xea;
                    dis[1] = 0x6a;
                }else{
                    dis[0] = 0x2c;
                    dis[1] = 0xbb;
                }
            }else{
                dis[0] = 0xff;
                dis[1] = 0xff;
            }
            
            dis[3] = 0x4a;
            dis[4] = 0x18;
            dis[6] = 0x8e;
            dis[7] = 0xa0;
            dis[8] = 0xe3;
            dis[9] = 0x47;
            break;
        }
        case 10:{
            auxSelec++;
            if(auxSelec >100){
                auxSelec = 0;
            }
            dis[0] = 0x98;
            dis[1] = 0x0a;
            dis[3] = 0x2c;
            dis[4] = 0x24;
            if((pass == 0)&&(auxSelec<50)){
                dis[6]=0xff;
            }else{
                dis[6]=conv7Seg(pass0);
            }
            if((pass == 1)&&(auxSelec<50)){
                dis[7]=0xff;
            }else{
                dis[7]=conv7Seg(pass1);
            }
            if((pass == 2)&&(auxSelec<50)){
                dis[8]=0xff;
            }else{
                dis[8]=conv7Seg(pass2);
            }
            if((pass == 3)&&(auxSelec<50)){
                dis[9]=0xff;
            }else{
                dis[9]=conv7Seg(pass3);
            }
            break;
        }
        case 5:{
            dis[0]=0xff;
            dis[1]=0xff;
            dis[3]=0xff;
            dis[4]=0xff;
            dis[6]=0x92;
            dis[7]=0xa0;
            dis[8]=0xe3;
            dis[9]=0x84;
            break;
        }
        /*case 101:{
            dis[0]=;
            dis[0]=;*/
    }
    return;
}
