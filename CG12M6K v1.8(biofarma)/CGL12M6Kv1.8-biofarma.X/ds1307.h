#include <xc.h>
#define _XTAL_FREQ  4000000
#define BAUDRATE 100000UL
#define VALOR ((_XTAL_FREQ/(4UL*BAUDRATE))-1)

void ds1307 (char R_W);

char anioS;
int unsigned anioR;
char mesS;
int unsigned mesR;
char diaS;
int unsigned diaR;
char horaS;
char horaR;
char minS;
char minR;
char secS;
char secR;
extern int long hora;
extern int long segundo;
extern int long minuto;
extern char R_W;
extern int long unsigned Segundos;
extern char unsigned fecha[3];
extern int unsigned diaActual;
extern int unsigned dia;
extern char unsigned mes;
extern char unsigned anio;
extern char unsigned WRdia0;
char ampm;
extern char bat_baja;
int unsigned diaAUX;
int unsigned mesAUX;
int unsigned anioAUX;
unsigned int watchDogI2C;
unsigned int auxRTC;