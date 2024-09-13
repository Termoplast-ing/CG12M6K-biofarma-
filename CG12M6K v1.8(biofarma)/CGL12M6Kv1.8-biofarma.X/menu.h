/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

#include <xc.h>

void menu(void);
extern char unsigned selMenu;
extern char unsigned diaMostrado;
extern char unsigned manual;
extern char unsigned resetDia;
extern int unsigned senOptDisTime;
int long unsigned minReset;
int long unsigned horaReset;
extern char unsigned accionTecla;
int unsigned dosisPrueba;
char unsigned xDefecto;
char unsigned a1;
char unsigned digito;
char unsigned digito0;
char unsigned digito1;
char unsigned digito2;
char unsigned digito3;
extern char unsigned madres;
extern int long unsigned kilos;
extern unsigned long acumulado[31];
extern char unsigned dosis;
char unsigned horaSAux;
char unsigned minSAux;
int long unsigned horaResetAux;
int long unsigned minResetAux;
extern int unsigned PasosMotor;
char unsigned pass0;
char unsigned pass1;
char unsigned pass2;
char unsigned pass3;
char unsigned pass;
char unsigned auxMenu;
extern char unsigned hora0;
extern char unsigned hora1;
extern char unsigned min2;
extern char unsigned min3;
char unsigned dosisAux;
int unsigned pasosMotorAux;
int unsigned step;
int unsigned cantStep;
int unsigned restoStep;
extern int long unsigned horaRST;
extern int long unsigned minutoRST;
extern char unsigned diaTerminado;
extern char led1;
int long unsigned horaRSTlec;
int long unsigned minRSTlec;
extern int long unsigned timeMotor;
extern char unsigned ReseteoAux;
extern unsigned char auxLect;
extern unsigned long auxLectLong;
extern unsigned int long auxLectIntLong;
extern unsigned int auxLectInt;