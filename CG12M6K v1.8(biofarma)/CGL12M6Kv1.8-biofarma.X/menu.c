/*
 * File:   menu.c
 * Author: Admin
 *
 * Created on 6 de julio de 2020, 11:37
 */


#include <xc.h>
#include "menu.h"
#include "controlMotor.h"
#include "ds1307.h"


void wrEprom1(char dir , char dato){                                             //rutina para escribir eemprom
    
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
    INTCONbits.PEIE =1;                                                                     // empiezo escritura
                                                         // desabilito escritura
    while (EECON1bits.WR){                                                      // espero hasta que WR se haga 0 por hardware(escritura terminada)
    }
    EECON1bits.WREN = 0;
    __delay_ms(10);
}

char rdEprom(char dir , char dato){
    
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

void pruebaDosis(int unsigned step){
    cantDePaso= 0;
    
    while(cantDePaso>(step*100)){
    PORTBbits.RB0=1;
    if((step%400)==0){
    ds1307(0);
    }
}
    PORTBbits.RB0=0;
    cantDePaso=0;
    
/*    for(m = cantStep; m > 0 ; m--){
        PORTB = 0b00100001;//0b00010001;
        __delay_ms(20);
        PORTB = 0b00001001;//0b00100001;
        __delay_ms(20);
        PORTB = 0b00011000;//0b00011000;
        __delay_ms(20);
        PORTB = 0b00110000;//0b00011000;
        __delay_ms(20);
    }
    m=0;
switch(restoStep){
    case 1:{
        PORTB = 0b00010001;
        __delay_ms(20);
        break;
    }
    case 2:{
        PORTB = 0b00010001;
        __delay_ms(20);
        PORTB = 0b00100001;
        __delay_ms(20);
        break;
    }
    case 3:{
        PORTB = 0b00010001;
        __delay_ms(20);
        PORTB = 0b00100001;
        __delay_ms(20);
        PORTB = 0b00101000;
        __delay_ms(20);
        break;
    }
}*/

}
        
void menu(void) {
            
    if(selMenu > 20){
        selMenu = 0;
    }
    
    switch(selMenu){
        case 0:{
            switch(accionTecla){
                case 1:{
                    madres ++ ;
                    if(madres > 12){
                        madres = 7;
                    }
                    do{
                        wrEprom1(0x00,madres);
                        __delay_us(20);
                        auxLect=rdEprom(0x00,auxLect);
                    }while(madres!=auxLect);
                    auxLect=0;
                    accionTecla = 0;
                break;
                }
                case 2:{
                    madres -- ;
                    if((madres > 12)||(madres < 7)){
                        madres = 12;
                    }
                    do{
                        wrEprom1(0x00,madres);
                        __delay_us(20);
                        auxLect=rdEprom(0x00,auxLect);
                    }while(madres!=auxLect);
                    auxLect=0;
                    accionTecla = 0;
                break;
                }
                case 3:{
                    kilos ++ ;
                    if(kilos > 60){
                        kilos = 1;
                    }
                    do{
                        wrEprom1(0x01,kilos);
                        __delay_us(20);
                        auxLect=rdEprom(0x01,auxLect);
                    }while(kilos!=auxLect);
                    auxLect=0;
                    accionTecla = 0;
                break;
                }
                case 4:{
                    kilos --;
                    if((kilos > 60)||(kilos < 1)){
                        kilos = 60;
                    }
                    do{
                        wrEprom1(0x01,kilos);
                        __delay_us(20);
                        auxLect=rdEprom(0x01,auxLect);
                    }while(kilos!=auxLect);
                    auxLect=0;
                    accionTecla = 0;
                break;
                }
                case 5:{
                    if(((diaMostrado > 0)&&(diaMostrado < 31))&&((manual==0)||((manual==1)&&(diaTerminado==0)))){
                       
                        acumulado[diaMostrado] = 0;
                        do{
                        wrEprom1( (0x64+(diaMostrado*0x04)),0x00);
                        wrEprom1( (0x64+(diaMostrado*0x04)+0x01),0x00);
                        wrEprom1( (0x64+(diaMostrado*0x04)+0x02),0x00);
                        wrEprom1( (0x64+(diaMostrado*0x04)+0x03),0x00);
                        __delay_us(20);
                        auxLectLong= rdEprom((0x64+(diaMostrado*0x04)),auxLectLong);
                        auxLectLong=(auxLectLong<<8)+ rdEprom((0x64+(diaMostrado*0x04)+0x01),auxLectLong);
                        auxLectLong=(auxLectLong<<8)+ rdEprom((0x64+(diaMostrado*0x04)+0x02),auxLectLong);
                        auxLectLong=(auxLectLong<<8)+ rdEprom((0x64+(diaMostrado*0x04)+0x03),auxLectLong);
                        }while(acumulado[diaMostrado]!= auxLectLong);
                    }else{
                        if(diaMostrado == 0){
                            if(manual == 1){
                                resetDia = 1;
                            }
                        }
                    }
                    accionTecla = 0;
                break;
                }
                case 8:{
                    controlMotor();
                    senOptDisTime = 2000;
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    manual=rdEprom(0x02,manual);       
                                          
                    if(manual > 0){
                        manual = 0;
                        led1=0;
                    }else{
                        manual = 1;
                        led1=1;
                    }
                    wrEprom1( 0x02,manual);
                    accionTecla = 0x00;
                break;
                }
                case 9:{
                    selMenu = 10;
                    accionTecla = 0;
                break;
                }
                case 7:{
                    diaMostrado++;
                    if(diaMostrado > 30){
                        diaMostrado = 0;
                    }
                    accionTecla = 0;
                break;
                }
                case 10:{
                    if(diaMostrado == 0){
                        for(a1 = 1 ; a1 < 31 ; a1 ++){
                            acumulado[a1] = 0;
                            do{
                                wrEprom1(((a1*0x04)+0x64),0 );
                                wrEprom1((0x01+(a1*0x04)+0x64),0 );
                                wrEprom1((0x02+(a1*0x04)+0x64),0 );
                                wrEprom1((0x03+(a1*0x04)+0x64),0 );
                                __delay_us(20);
                                auxLectLong= rdEprom(((a1*0x04)+0x64),auxLectLong);
                                auxLectLong=(auxLectLong<<8)+ rdEprom((0x01+(a1*0x04)+0x64),auxLectLong);
                                auxLectLong=(auxLectLong<<8)+ rdEprom((0x02+(a1*0x04)+0x64),auxLectLong);
                                auxLectLong=(auxLectLong<<8)+ rdEprom((0x03+(a1*0x04)+0x64),auxLectLong);
                            }while(acumulado[a1]!= auxLectLong);
                            
                        }
                    }else{
                        diaMostrado = 0;
                    }
                    accionTecla = 0 ;
                break;
                }
            }
        break;
        }
        case 1:{
            switch(accionTecla){
                case 1:{
                    selMenu = 2;
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    selMenu = 4;
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    selMenu = 11;
                    ds1307(0);
                    digito0=(horaR >> 4) & 0b00000011;
                    digito1=horaR &0b00001111;
                    digito2=(minR >> 4) & 0b00001111;
                    digito3=minR & 0b00001111;
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 0 ;
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
            accionTecla=0;
            }
            break;
        }
        case 11:{
            switch(accionTecla){
                case 1:{
                    if(digito == 0){
                        digito0 ++;
                        if(digito0>2){
                            digito0=0;
                        }
                    }
                    if(digito == 1){
                        digito1 ++;
                        if(digito0>1){
                            if(digito1>3){
                                digito1=0;
                            }
                        }else{
                            if(digito1>9){
                                digito1=0;
                            }
                        }
                    }
                    if(digito == 2){
                        digito2 ++;
                        if(digito2 > 5){
                            digito2 = 0;
                        }
                    }
                    if(digito == 3){
                        digito3 ++;
                        if(digito3 > 9){
                            digito3 = 0;
                        }
                    }
                    break;
                }
                case 2:{
                    if(digito == 0){
                        digito0 --;
                        if(digito0 > 2){
                            digito0 = 2;
                        }
                    }
                    if(digito == 1){
                        digito1 --;
                        if(digito0>1){
                            if(digito1>3){
                                digito1=3;
                            }
                        }else{
                            if(digito1>9){
                                digito1=9;
                            }
                        }
                    }
                    if(digito == 2){
                        digito2 --;
                        if(digito2 > 5){
                            digito2 = 5;
                        }
                    }
                    if(digito == 3){
                        digito3 --;
                        if(digito3 > 9){
                            digito3 = 9;
                        }
                    }
                    break;
                }
                case 3:{
                    digito ++;
                    if(digito > 3){
                        digito = 0;
                    }
                    break;
                }
                case 4:{
                    digito --;
                    if(digito > 3){
                        digito = 3;
                    }
                    break;
                }
                case 6:{
                    horaS=digito0<<4;
                    horaS=horaS+digito1;//+0b01000000;
                    minS=digito2<<4;
                    minS=minS+digito3;
                    ds1307(1);
                    selMenu = 5;
                    break;
                }
                case 10:{
                    selMenu= 1;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 2:{
            switch(accionTecla){
                case 1:{
                    selMenu = 3;
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    selMenu = 1;
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    selMenu = 12;
                    horaReset= rdEprom(0x06,horaReset);
                    horaReset=(horaReset<<8)+ rdEprom(0x05,horaReset);
                    horaReset=(horaReset<<8)+ rdEprom(0x04,horaReset);
                    horaReset=(horaReset<<8)+ rdEprom(0x03,horaReset);
                    horaReset=horaReset & 0x000000ff;
                    digito0=horaReset/10;
                    digito1=horaReset%10;
                    // digito0=(horaReset>>4) & 0b00000011;
                   // digito1=(horaReset & 0b00001111);
                    minReset=rdEprom(0x0a,minReset);
                    minReset=(minReset<<8)+ rdEprom(0x09,minReset);
                    minReset=(minReset<<8)+ rdEprom(0x08,minReset);
                    minReset=(minReset<<8)+ rdEprom(0x07,minReset);
                    minReset=minReset & 0x000000ff;
                    digito2=minReset/10;
                    digito3=minReset%10;
                    //digito2=(minReset>>4) & 0b00001111;
                    //digito3=(minReset & 0b00001111);
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 0 ;
                    accionTecla = 0;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 12:{
            switch(accionTecla){
                case 1:{
                    if(digito == 0){
                        digito0 ++;
                        if(digito0>2){
                            digito0=0;
                        }
                    }
                    if(digito == 1){
                        digito1 ++;
                        if(digito0>1){
                            if(digito1>3){
                                digito1=0;
                            }
                        }else{
                            if(digito1>9){
                                digito1=0;
                            }
                        }
                    }
                    if(digito == 2){
                        digito2 ++;
                        if(digito2 > 5){
                            digito2 = 0;
                        }
                    }
                    if(digito == 3){
                        digito3 ++;
                        if(digito3 > 9){
                            digito3 = 0;
                        }
                    }
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    if(digito == 0){
                        digito0 --;
                        if(digito0 > 2){
                            digito0 = 2;
                        }
                    }
                    if(digito == 1){
                        digito1 --;
                        if(digito0>1){
                            if(digito1>3){
                                digito1=3;
                            }
                        }else{
                            if(digito1>9){
                                digito1=9;
                            }
                        }
                    }
                    if(digito == 2){
                        digito2 --;
                        if(digito2 > 5){
                            digito2 = 5;
                        }
                    }
                    if(digito == 3){
                        digito3 --;
                        if(digito3 > 9){
                            digito3 = 9;
                        }
                    }
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    digito ++;
                    if(digito > 3){
                        digito = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    digito --;
                    if(digito > 3){
                        digito = 3;
                    }
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    //horaReset=(digito0<<4)+digito1;
                    //minReset= (digito2<<4)+digito3;
                    horaReset=(digito0*10)+digito1;
                    minReset= (digito2*10)+digito3;
               //     ultimaDosis1=ultimaDosis;
                    horaResetAux=horaReset; 
                    do{
                        for(ll=0;ll<4;ll++){

                            wrEprom1(0x03 + ll,horaResetAux);
                            horaResetAux=horaResetAux>>8;
                        }
                        auxLectIntLong = rdEprom(0x06,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x05,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x04,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x03,auxLectIntLong);
                        horaResetAux=horaReset; 
                    }while(auxLectIntLong!=horaResetAux);
                            
                    minResetAux=minReset; 
                    
                    do{
                        for(ll=0;ll<4;ll++){   
                            wrEprom1(0x07 + ll,minResetAux);
                            minResetAux=minResetAux>>8;
                        }
                        auxLectIntLong = rdEprom(0x0a,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x09,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x08,auxLectIntLong);
                        auxLectIntLong=(auxLectIntLong<<8)+ rdEprom(0x07,auxLectIntLong);
                        minResetAux=minReset;  
                    }while(auxLectIntLong!=minResetAux);
                    
                    horaRST = horaReset;
                    minutoRST = minReset;
                    selMenu = 5;
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu= 2;
                    accionTecla = 0;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 3:{
            switch(accionTecla){
                case 1:{
                    selMenu = 6;
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    selMenu = 2;
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    selMenu = 13;
                    dosis=rdEprom(0x0b,dosis);
                    dosisAux = dosis;
                    PasosMotor=rdEprom(0x0d,PasosMotor);
                    PasosMotor=(PasosMotor<<8)+rdEprom(0x0c,PasosMotor);
                    digito0=PasosMotor/1000;
                    digito1=(PasosMotor%1000)/100;
                    digito2=(PasosMotor%100)/10;
                    digito3=(PasosMotor%10);
                    
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 0 ;
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 13:{
            switch(accionTecla){
                case 1:{
                    dosisAux=dosisAux+5;
                    if(dosisAux>95){
                        dosisAux=5;
                    }
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    dosisAux = dosisAux - 5;
                    if((dosisAux>95)||(dosisAux<5)){
                        dosisAux = 95;
                    }
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    if(digito==0){
                        digito0 ++;
                        if(digito0>9){
                            digito0=0;
                        }
                    }
                    if(digito==1){
                        digito1++;
                        if(digito1>9){
                            digito1=0;
                        }
                    }
                    if(digito==2){
                        digito2++;
                        if(digito2>9){
                            digito2=0;
                        }
                    }
                    if(digito==3){
                        digito3++;
                        if(digito3>9){
                            digito3=0;
                        }   
                    }
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    digito ++ ;
                    if(digito>3){
                        digito = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    dosisPrueba = ((digito0*1000)+(digito1*100)+(digito2*10)+(digito3));
                    if(dosisPrueba<100){
                        dosisPrueba=100;
                    }
                    pruebaDosis(dosisPrueba);
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    PasosMotor=((digito0*1000)+(digito1*100)+(digito2*10)+(digito3));
                    if(dosisPrueba<100){
                        PasosMotor=100;
                    }
                    dosis = dosisAux;
                    do{
                    wrEprom1( 0x0b,dosis);
                    __delay_us(20);
                    auxLect=rdEprom(0x0b,auxLect);
                    }while(auxLect!=dosis);
                    
                    pasosMotorAux=PasosMotor; 
                    do{
                    wrEprom1(0x0c ,pasosMotorAux);
                    pasosMotorAux=pasosMotorAux>>8;
                    wrEprom1(0x0d ,pasosMotorAux);
                    __delay_us(20);
                    auxLectInt=rdEprom(0x0d,auxLectInt);
                    auxLectInt=(auxLectInt<<8)+(rdEprom(0x0c,auxLectInt));
                    pasosMotorAux=PasosMotor;
                    }while(pasosMotorAux!=auxLectInt);
                    timeMotor=PasosMotor/1000;       //timeMotor=PasosMotor/25; //timeMotor=PasosMotor/100;
                    accionTecla = 0;
                    selMenu = 5;
                    break;
                }
                case 10:{
                    accionTecla=0;
                    selMenu=3;
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla=0;
                    break;
                }
                case 8:{
                    accionTecla=0;
                    break;
                }
                case 9:{
                    accionTecla=0;
                    break;
                }
            accionTecla = 0; 
            }
            break;
        }
        case 6:{
            switch(accionTecla){
                case 1:{
                    selMenu = 4;
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    selMenu = 3;
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    selMenu=16;
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 0 ;
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 4:{
            switch(accionTecla){
                case 1:{
                    selMenu = 1;
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    selMenu = 6;
                    ReseteoAux=0;
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    selMenu = 14;
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 0 ;
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
            }
            accionTecla = 0;
            break;
        }
        case 16:{
            switch(accionTecla){
                case 1:{
                    if(ReseteoAux == 0){
                        ReseteoAux = 1;
                    }else{
                        ReseteoAux = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    if(ReseteoAux == 0){
                        ReseteoAux = 1;
                    }else{
                        ReseteoAux = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    if(ReseteoAux == 1){
                        acumulado[0]=0;
                        //
                        //
                        //
                        selMenu = 5;
                    }else{
                        selMenu = 6; 
                    }
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 6;
                    accionTecla = 0;
                    break;                          
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
                break;
            }
        break;    
        }
        case 14:{
            switch(accionTecla){
                case 1:{
                    if(xDefecto == 0){
                        xDefecto = 1;
                    }else{
                        xDefecto = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    if(xDefecto == 0){
                        xDefecto = 1;
                    }else{
                        xDefecto = 0;
                    }
                    accionTecla = 0;
                    break;
                }
                case 6:{
                    if(xDefecto == 1){
                        wrEprom1( 0x00,0x0c);
                        madres=12;
                        wrEprom1( 0x01,0x3c);
                        kilos=60;
                        wrEprom1( 0x02,0x00);
                        manual=0;
                        wrEprom1( 0x03,0x0c);
                        horaRST=12;
                        wrEprom1( 0x04,0x00);
                        wrEprom1( 0x05,0x00);
                        wrEprom1( 0x06,0x00);
                        wrEprom1( 0x07,0x00);
                        wrEprom1( 0x08,0x00);
                        wrEprom1( 0x09,0x00);
                        wrEprom1( 0x0a,0x00);
                        wrEprom1( 0x0b,0x32);
                        dosis=50;
                        wrEprom1( 0x0c,0xc8);
                        PasosMotor=200;
                        wrEprom1( 0x0d,0x00);
                        selMenu = 5;
                    }else{
                        selMenu = 4; 
                    }
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    selMenu = 4;
                    accionTecla = 0;
                    break;                          
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    accionTecla = 0;
                    break;
                }
                break;
            }
        break;    
        }
        case 10:{
            switch(accionTecla){
                case 1:{
                    if(pass == 0){
                        pass0 ++;
                        if(pass0 > 9){
                            pass0 = 0;
                        }
                    }
                    if(pass == 1){
                        pass1 ++;
                        if(pass1 > 9){
                            pass1 = 0;
                        }
                    }
                    if(pass == 2){
                        pass2 ++;
                        if(pass2 > 9){
                            pass2 = 0;
                        }
                    }
                    if(pass == 3){
                        pass3 ++;
                        if(pass3 > 9){
                            pass3 = 0;
                        }
                    }
                    accionTecla = 0;
                    break;
                }
                case 2:{
                    if(pass == 0){
                        pass0 --;
                        if(pass0 > 9){
                            pass0 = 9;
                        }
                    }
                    if(pass == 1){
                        pass1 --;
                        if(pass1 > 9){
                            pass1 = 9;
                        }
                    }
                    if(pass == 2){
                        pass2 --;
                        if(pass2 > 9){
                            pass2 = 9;
                        }
                    }
                    if(pass == 3){
                        pass3 --;
                        if(pass3 > 9){
                            pass3 = 9;
                        }
                    }
                    accionTecla = 0;
                    break;
                }
                case 5:{
                    pass++;
                    if(pass>3){
                        pass=0;
                    }
                    accionTecla = 0;
                    break;
                } 
                case 6:{
                    if((pass0 == 1)&&(pass1 == 5)&&(pass2 == 0)&&(pass3 == 2)){
                        selMenu =1;
                        pass = 0;                                                       //se reinicia todas las variables
                        pass0 = 0;                                                      //que verifican el pass
                        pass1 = 0;                                                      // para que  quede listo 
                        pass2 = 0;   
                        pass3 = 0;
                    }else{
                        selMenu=10;
                    }
                    accionTecla = 0;
                    break;
                }
                case 9:{
                    selMenu= 0;  
                    accionTecla = 0;
                    break;
                }
                case 3:{
                    accionTecla = 0;
                    break;
                }
                case 4:{
                    accionTecla = 0;
                    break;
                }
                case 7:{
                    accionTecla = 0;
                    break;
                }
                case 8:{
                    accionTecla = 0;
                    break;
                }
                case 10:{
                    accionTecla = 0;
                    break;
                }
            }
            break;
        }
        case 5:{
            auxMenu++;
            if(auxMenu > 200){
                auxMenu = 0;
                selMenu = 1;
            }
        }
        break;
    }
    return;
}
