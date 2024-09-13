/*
 * File:   main.c
 * Author: Brian Avila
 *
 * Created on 3 de abril de 2020, 17:25
 */


// PIC18F25K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = INTIO67   // Oscillator Selection bits (Internal oscillator block)
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = ON     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = ON  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 250       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF       // Watchdog Timer Enable bits (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<5:0> pins are configured as digital I/O on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTB5   // ECCP2 B output mux bit (P2B is on RB5)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF       // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f25k22.h>




/*// PIC18F25K22 Configuration Bit Settings

// 'C' source line config statements

//CONFIG1H


#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 190       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bits (Watch dog timer is always disabled. SWDTEN has no effect.)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTB5   // ECCP2 B output mux bit (P2B is on RB5)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
*/
#include <xc.h>
#include <pic18f25k22.h>
#define _XTAL_FREQ 4000000
#include "inicializacion.h"
#include "ds1307.h"
#include "controlMotor.h"
#include "display.h"
#include "menu.h"
#include "teclado.h"


char auxInt;
char dis[11];
int long unsigned horaRST;
char unsigned fecha[3];
int unsigned dia;
char unsigned mes;
char unsigned anio;
int long unsigned minutoRST;
char unsigned madres;
int long unsigned kilos;
char unsigned dosis;
unsigned long acumulado[31];
unsigned long acumuladoAUX;
char z;
int long unsigned cantGramosTotal;
int long unsigned cantDosis;
int long unsigned segEntDosis;
int long unsigned ultimaDosis;
char habilitaDosis;
char sensorOptico;
char cambioAnimalAux;
char cambioAnimal;
int cantPasoXGramo;
int long unsigned Segundos;
int long signed segundosDia;
int long hora;
int long minuto;
int long segundo;
char R_W;
int long unsigned SegundosRST;
int unsigned diaActual;
int long unsigned segundosRestante;
int long secRestante;
int long ultimaDosisAux;
int c;
int d;
char led1;
char led2;
char led3;
char led4;
char ledParpa1;
char ledParpa2;
char ledParpa3;
char ledParpa4;
char rele;
char unsigned selMenu;
char unsigned diaMostrado;
char unsigned manual;
char unsigned resetDia;
int unsigned senOptDisTime;
char unsigned accioneTecla;
char unsigned xDefecto;
int unsigned PasosMotor;
char unsigned accionTecla;
char unsigned diaTerminado;
char unsigned habilitaOptico;
char unsigned WRdia0;
char bat_baja;
char unsigned diaTerminadoAux;
int unsigned x;
char unsigned y;
int unsigned p;
int unsigned msjDiaFin;
int long horaAux;
int long ultimaDosisWR;
unsigned long acumuladoWR;
int kk;
char ResetDiaAUX;
int long unsigned timeMotor;
char unsigned ReseteoAux;
unsigned char cantLect=0;
unsigned char auxLect;
unsigned long auxLectLong;
unsigned int long auxLectIntLong;
unsigned int auxLectInt;
unsigned int WRseg;
unsigned int WRmin;
unsigned int WRAcum;
unsigned int f;
unsigned int long seg24;
unsigned int long TentreDosis24;
unsigned int long cantDosis24;
unsigned char luzFallaReloj=0;
unsigned int long cantDePaso;

void calculoEntreDosis(int long unsigned kilos, char madres, char dosis){
    
    cantGramosTotal = ((madres * (kilos*100))-acumulado[0]);
    cantDosis = cantGramosTotal / dosis;
    
        segundosRestante = segundosRestante-(cantDosis*(timeMotor+2));
    if(segundosRestante > 86405){
        segundosRestante=1;
    }
    segEntDosis = segundosRestante / cantDosis;
    if(segEntDosis < 2){
        segEntDosis = 2;
    }
    
    cantDosis24=(madres*(kilos*100))/dosis;
    TentreDosis24=86400/cantDosis24;
}

void wrEprom6(char dir , char dato){    //rutina para escribir eemprom
    
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
    while (EECON1bits.WR){ // espero hasta que WR se haga 0 por hardware(escritura terminada)
    }// empiezo escritura
    EECON1bits.WREN = 0; 
    __delay_ms(10);
    // desabilito escritura
    
}

char rdEprom6(char dir , char dato){
    
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

void ResetDia(void){
    z=30;
    for(z = 30;z > 0;z--){
        acumulado[z]=acumulado[z-1];
    }
    acumulado[0]=0;
    for(z = 0 ; z <31 ; z++){
            acumuladoWR=acumulado[z];
            do{
                for(kk=0;kk<4;kk++){   
                    wrEprom6(0x64+(z*4)+kk,acumuladoWR);
                    __delay_ms(10);
                    acumuladoWR=acumuladoWR>>8;
                }
                auxLectLong=rdEprom6((0x64+(z*4)+3),auxLectLong);
                auxLectLong=(auxLectLong<<8)+rdEprom6((0x64+(z*4)+2),auxLectLong);
                auxLectLong=(auxLectLong<<8)+rdEprom6((0x64+(z*4)+1),auxLectLong);
                auxLectLong=(auxLectLong<<8)+rdEprom6((0x64+(z*4)),auxLectLong);  
                acumuladoWR=acumulado[z];
            }while(auxLectLong!=acumulado[z]);
    }
    ds1307(0); 
    resetDia=0;
    ledParpa1=0;
    ledParpa4=0;
    diaTerminado=0;
    diaTerminadoAux=1;
    ResetDiaAUX=0;
    p=0;
    f=0;
    seg24=0;
    if(manual == 1){
        led1=1;
    }
    diaActual=dia;
    wrEprom6(0x12,diaActual);
    diaActual=diaActual>>8;
    wrEprom6(0x13,diaActual);
    
}

void segundosRestantes(void){
    /*if((fecha[0])!=(dia)){
        diaActual=1;
    }else{
        diaActual= 0;
    }
    */
    SegundosRST = ((horaRST * 3600)+(minutoRST*60));
    //if(diaActual == 0){
        if(Segundos > SegundosRST){
            segundosRestante = ((86400 - Segundos) + SegundosRST);
           diaTerminadoAux=0;
            // if(diaTerminadoAux!=0){
            //}
        }if(SegundosRST > Segundos){
            segundosRestante = SegundosRST -Segundos;
            
        }
//    }
    
}
///////////////////
//RUTINA MUESTREO//
///////////////////
void __interrupt(low_priority) myLoIsr(void){
    

    T0CONbits.TMR0ON = 0; 
    INTCONbits.TMR0IF = 0;
    INTCONbits.PEIE=1;
c++;

cantDePaso++;
if(c >1023){
    c=0;
}

f++;
if(f>1000){
    f=0;
    seg24++;
}

if(seg24>TentreDosis24){
    habilitaDosis=1;
    luzFallaReloj=1;
    ledParpa4=0;
    seg24=0;
}

WRseg++;
if(WRseg>60000){
    WRseg=0;
    WRmin++;
    if(WRmin>40){
        WRmin=0;
        WRAcum=1;
    }
}
//if(diaTerminado==1){
  //  p+;
    //if(p > 30000){
      //  p=1801;
   // }
//}
/*SegundosRST = ((horaRST * 3600)+(minutoRST*60));
    if(Segundos==SegundosRST){
        if(manual==0){
            if(diaTerminadoAux==0){
                diaTerminado=1;
                msjDiaFin=1;
                ResetDiaAUX=1;
            }
        }else{
            if(resetDia==1){
                diaTerminado=1;
                msjDiaFin=1;
                ResetDiaAUX=1;
                
            }
        }
    }*/
SegundosRST = ((horaRST * 3600)+(minutoRST*60));
    if(Segundos==SegundosRST){
            if(diaTerminadoAux==0){
                diaTerminado=1;
                msjDiaFin=1;
                ResetDiaAUX=1;
            }
        }
    

y++;
d=auxInt;
PORTC = 0xff;
    T0CONbits.TMR0ON = 0; 
    INTCONbits.TMR0IF = 0;
    INTCONbits.PEIE=1;
switch(d){
    case 0:{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 0;
        if(luzFallaReloj==1){
            dis[d]=dis[d]&0b11110111;
        }
        PORTC = dis[d];
        break;
    }
    case 1:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 0;
        if(luzFallaReloj==1){
            dis[d]=dis[d]&0b11110111;
        }
        PORTC = dis[d];
        break;
    }
    case 2:{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 1;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 3:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 1;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 4:{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 1;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 5:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 1;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 6:{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 1;
        PORTAbits.RA6 = 1;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 7:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 1;
        PORTAbits.RA6 = 1;
        PORTAbits.RA7 = 0;
        PORTC = dis[d];
        break;
    }
    case 8:{
        PORTAbits.RA0 = 0;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 1;
        PORTC = dis[d];
        break;
    }
    case 9:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 0;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 1;
        PORTC = dis[d];
        break;
    }
    case 10:{
        if((led1 == 1)||((ledParpa1==1)&&(c<512))){
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 0;
            PORTAbits.RA7 = 1;
        }else{
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }
        break;
    }
    case 11:{
        if((led2 == 1)||((ledParpa2==1)&&(c<512))){
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 0;
            PORTAbits.RA7 = 1;
        }else{
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }
        break;
    }
    case 12:{
        if((led3 == 1)||((ledParpa3==1)&&(c<512))){
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 0;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }else{
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }
        break;
    }
    case 13:{
        if((led4 == 1)||((ledParpa4==1)&&(c<512))){
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 0;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }else{
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }
        break;
    }
    case 14:{
        if(rele == 1){
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }else{
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 1;
            PORTAbits.RA6 = 1;
            PORTAbits.RA7 = 1;
        }
        break;
    }
    case 15:{
        PORTAbits.RA0 = 1;
        PORTAbits.RA1 = 1;
        PORTAbits.RA6 = 1;
        PORTAbits.RA7 = 1;
        break;
    }
}
    
    auxInt ++;
    if(auxInt > 14){
        auxInt = 0;
    }
    TMR0H = 0x00;                                                               //se le asigna 0 al byte mas significativo del carga del timer 0 xq trabaja en 8 bit este
    TMR0L = 0x06; 
    T0CONbits.TMR0ON = 1; 
    INTCONbits.PEIE =1;
}

        
void main(void){
OSCCONbits.IRCF0=1;
OSCCONbits.IRCF2=1;
OSCCONbits.IRCF1=0;

auxInt = 0x00;
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
dis[10]=0xff;
horaRST=0x00;
minutoRST=0x00;
madres=0x00;
kilos=00;
dosis=00;
z=0;
cantGramosTotal=0x00;
cantDosis=0x00;
segEntDosis=0x00;
habilitaDosis=0x00;
sensorOptico=0x00;
cantPasoXGramo=0x00;
R_W=0x00;
SegundosRST=0x00;
segundosRestante=0x00;
secRestante=0x00;
ultimaDosisAux=0x00;
c=0x00;
d=0x00;
led1=0x00;
led4=0x00;
ledParpa1=0x00;
ledParpa4=0x00;
selMenu=0x00;
diaMostrado=0x00;
resetDia=0x00;
senOptDisTime=0x00;
accioneTecla=0x00;
xDefecto=0x00;
PasosMotor=0x00;
accionTecla=0x00;
diaTerminado=0x00;
habilitaOptico=0x00;
diaTerminadoAux=0x00;
x=0x00;
y=0x00;
p=0x00;
msjDiaFin=0x00;
WRseg=0;
WRmin=0;
WRAcum=0;
f=0;
seg24=0;

for(i=0;i<=31;i++){
    acumulado[i]=0;
}

    inicializacion();
    ResetDiaAUX=0;
    
    SegundosRST = ((horaRST * 3600)+(minutoRST*60));
    
    if(((dia==diaActual)&&(Segundos<SegundosRST))||((dia==(diaActual+1))&&(Segundos>SegundosRST))||(((dia-diaActual)>1)||((dia-diaActual)>1))){
    if(Segundos<SegundosRST){
        
        if(manual==0){
            ResetDia();
        }
        if(manual==1){
            dis[0]=0x4a;
            dis[1]=0x3b;
            dis[3]=0x0a;
            dis[4]=0xff;
            dis[6]=0x87;
            dis[7]=0x84;
            dis[8]=0xaf;
            dis[9]=0x48;
            while(accionTecla!=5){
                teclado();
            }
            ResetDia();
        }
    }}
    
   /* if((dia==diaActual)&&(Segundos<SegundosRST)){
        if(manual==0){
          //  ResetDia();
        }
        if(manual==1){
            dis[0]=0x4a;
            dis[1]=0x3b;
            dis[3]=0x0a;
            dis[4]=0xff;
            dis[6]=0x87;
            dis[7]=0x84;
            dis[8]=0xaf;
            dis[9]=0x48;
            while(accionTecla!=5){
                teclado();
            }
            ResetDia();
        }
    }
    
    if((dia==(diaActual+1))&&(Segundos>SegundosRST)){
    if(manual==0){
            ResetDia();
        }
        if(manual==1){
            dis[0]=0x4a;
            dis[1]=0x3b;
            dis[3]=0x0a;
            dis[4]=0xff;
            dis[6]=0x87;
            dis[7]=0x84;
            dis[8]=0xaf;
            dis[9]=0x48;
            while(accionTecla!=5){
                teclado();
            }
            ResetDia();
        }
    }
    
    if((dia!=diaActual)&&(dia!=(diaActual +1))){
    if(manual==0){
            ResetDia();
        }
        if(manual==1){
            dis[0]=0x4a;
            dis[1]=0x3b;
            dis[3]=0x0a;
            dis[4]=0xff;
            dis[6]=0x87;
            dis[7]=0x84;
            dis[8]=0xaf;
            dis[9]=0x48;
            while(accionTecla!=5){
                teclado();
            }
            ResetDia();
        }
    }*/

    while(1){
        
        display();
        menu();

        ds1307(0);
      
  
        
        if(((ResetDiaAUX==1)&&(manual==0))||((manual==1)&&(ResetDiaAUX==1)&&(resetDia==1))){
            ResetDia();
        }
      //  if((manual==1)&&(resetDia==1)&&(diaTerminadoAux==1)){
      //      ResetDia();    
      //  }
     //   if((diaTerminado==1)&&(manual==0)&&(diaTerminadoAux == 0)){
      //      ResetDia();
      //  }
        if(WRAcum==1){
            ultimaDosisWR=ultimaDosis;
            do{
                ultimaDosisWR=ultimaDosis;
            for(kk=0;kk<4;kk++){   
                wrEprom6(0x0e + kk,ultimaDosisWR);
                ultimaDosisWR=ultimaDosisWR>>8;
            }
            auxLectIntLong=rdEprom6(0x11,auxLectIntLong);
            auxLectIntLong=(auxLectIntLong<<8)+(rdEprom6(0x10,auxLectIntLong));
            auxLectIntLong=(auxLectIntLong<<8)+(rdEprom6(0x0f,auxLectIntLong));
            auxLectIntLong=(auxLectIntLong<<8)+(rdEprom6(0x0e,auxLectIntLong));
            ultimaDosisWR=ultimaDosis;
            }while(auxLectIntLong!=ultimaDosis);
            
            acumuladoWR=acumulado[0];
            do{
                acumuladoWR=acumulado[0];
                for(kk=0;kk<4;kk++){   
                    wrEprom6( (0x64 + kk),acumuladoWR);
                    acumuladoWR=acumuladoWR>>8;
                }
                auxLectLong=rdEprom6(0x67,auxLectLong);
                auxLectLong=(auxLectLong<<8)+(rdEprom6(0x66,auxLectLong));
                auxLectLong=(auxLectLong<<8)+(rdEprom6(0x65,auxLectLong));
                auxLectLong=(auxLectLong<<8)+(rdEprom6(0x64,auxLectLong));
                
            }while(auxLectLong!=acumulado[0]);
            
            WRAcum=0;
        }
            
        if(accionTecla == 0){
            TRISAbits.RA3 = 1;
            TRISAbits.RA4 = 1;
            TRISAbits.RA5 = 1;
            teclado();
        }else{
            if(accionTecla > 10){
                accionTecla = 0;
            }
        }
        /*while(y>200){
            for(x=0;x<30;x++){

                EEADR = (x*2)+100;                                                                //seteo la direccion que se va grabar de memoria
                EEDATA = acumulado[x];                                                              //cargo el dato que se va a grabar
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
            }
            y=0;
        }*/

        if(diaTerminado != 1){
        
       segundosRestantes();
        
        calculoEntreDosis(kilos,madres,dosis);
        
        acumuladoAUX = (kilos*100)*madres;
        if(ultimaDosis>Segundos){
            ultimaDosisAux=(86400-ultimaDosis)+Segundos;
            if(ultimaDosisAux > segEntDosis){
                if(acumulado[0]<=(acumuladoAUX)){
                    habilitaDosis = 1;
                    luzFallaReloj=0;
                    ledParpa4=0;
                }
            } 
            
        }else{
            ultimaDosisAux = Segundos - ultimaDosis; 
            if(ultimaDosisAux > segEntDosis){
                if(acumulado[0]<=(acumuladoAUX)){
                    habilitaDosis = 1;
                    luzFallaReloj=0;
                    ledParpa4=0;
                }
            }
        }
        
        
        
        if(habilitaDosis == 1){
            if(PORTAbits.RA2 == 0){
                habilitaOptico = 1;
            }//else{
               // habilitaOptico = 0;
            //}
        }
        
        
        
        
        
       /* if(PORTAbits.RA2 == 1){
            __delay_ms(5);
            if((PORTAbits.RA2 == 1)&&(cambioAnimalAux==1)){
                sensorOptico = 1;
                cambioAnimalAux = 0;
            }
        }else{
            __delay_ms(5);
            if(PORTAbits.RA2 == 0){
                if(cambioAnimal==1){
                    cambioAnimalAux = 1;
                    cambioAnimal = 0;
                }
            }
        }*/
        
        if((habilitaOptico==1)&&(habilitaDosis==1)&&(PORTAbits.RA2==1)){
            controlMotor();
            habilitaOptico = 0;
            habilitaDosis = 0;
        }
    }else{
           // SegundosRST = ((horaRST * 3600)+(minutoRST*60));
          //if(Segundos>SegundosRST){
          // diaTerminadoAux=1;
         // }
            
            if(manual==1){
            led1=0;
            led4=0;
            ledParpa1=1;
            ledParpa4=1;
            }
            if(manual==0){
            led1=0;
            led4=0;
            ledParpa1=0;
            ledParpa4=0;    
            }
    
      }
}
    return;
    
}