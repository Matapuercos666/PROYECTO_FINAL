//#include <iostream>
//#include "edit.h"
//#include <stdio.h>

using namespace std;

void unamipn()
{
    textbackground(3); clrscr();
    textcolor(0,0); gotoxy(0,4);    printf("                                                                                                                        ");
    textcolor(3,3); gotoxy(0,1);    printf("                                                                                                                        ");
    textcolor(3,3); gotoxy(0,30);   printf("                                                                                                                        ");
    textcolor(0,0); gotoxy(0,31);   printf("                                                                                                                        ");
    textcolor(0,0); gotoxy(0,29);   printf("                                                                                                                        ");
    textcolor(0,0); gotoxy(0,2);    printf("                                                                                                                        ");

    textcolor(0,3);

    textcolor(6,1); gotoxy(40,8);  printf("UNIVERSIDAD NACIONAL AUT%cNOMA DE M%cXICO",224,144);
    textcolor(0,3); gotoxy(49,10); printf("FACULTAD DE INGENIER%cA",214);
    gotoxy(50,12); printf("INGENIER%cA PETROLERA",214);
    gotoxy(46,16); printf("FUNDAMENTOS DE PROGRAMACI%cN",224);
    textcolor(3,0); gotoxy(53,17); printf("PROYECTO FINAL");
    textcolor(0,3);
    gotoxy(49,20); printf("VALD%cZ S%cNCHEZ SERGIO",144,181);
    gotoxy(20,22); printf("AGUILAR P%cREZ VICTOR        EN COLABORACI%cN CON DUARTE SILVA JULIO DANIEL      ",144,224);
    textcolor(6,1);  gotoxy(41,22); printf("(UNAM)");
    textcolor(15,4); gotoxy(94,22);printf("(IPN)");

    getch();	

    //return 0;
}
