#include <iostream>
#include "edit.h"// este documento se agreg� a la carpeta del programa desde fuera para tener acceso a la funcion gotoxy
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //libreria de funciones matematicas.
#include <windows.h>
#include "UNAMIPN.cpp"//este es una portada que hicimos en otro programa y solo agregamos por medio de un archivo

#define p printf
#define s scanf
using namespace std;

void unamipn();

void Menu();
    bool Pmenu();//prototipo de función

void meteorologico(void);
    void centro(void);
    void sur(void);
    void norte(void);
    void mayor(void);
        float mayor1(void);

void cine(void);

    void cinecito  (void);

        void salaconvencional(void);
            void leerboleto(void);
            void imprimirconv(void);
        void salatres(void);
            void leerboleto3(void);
            void imprimir3d(void);

void calificaciones (void);


int main()
{
    unamipn();//portada hecha aparte
    system("COLOR 30"); //Se aplica a todo el Preograma dentro de la función main

    do
    {
        Menu();
    } while (Pmenu()); // Ejecuta el menú tantas veces sea necesario
    
    getch();
    return 0;
}



void Menu()
{
    
    int opcion;
    system("cls");//limpiar pantalla :)
    do
    {
        system("cls");
        p("\n\t elige que programa deseas ejecutar: ");
        p("\n\n\t 1: centro meteorologico \n\t 2: sala de cine \n\t 3: calificaciones \n\t 4: salir ");
        p("\t\t");
        s("%d",&opcion);
    }while(opcion<1 || opcion>4);
    switch(opcion)
    {
        case 1: meteorologico(); break;
        case 2: cine(); break;
        case 3: calificaciones(); break;
        case 4: gotoxy(34,12); p("Gracias por elegir CRACK'S COMPANY, hasta la proxima "); exit(0);
    }


    getch();
}



bool Pmenu()
{
    int Pregunta;
    do
    {
        system("cls");
        p("¿desea ejecutar otro programa? \n");
        s("%d",&Pregunta);
        
    } while (Pregunta < 1 || Pregunta > 2);
    

    return(Pregunta == 1); 
    
    
}



//AQUI EMPIEZA EL CENTRO METEOROLOGICO


void meteorologico(void)
{
    int opcion;
    do
    {
        system("cls");
        do
        {
            p("\n\n\t ¿Quieres calcular?\n");
            p("\t 1: Promedio mensual de la región centro\n");
            p("\t 2: La semana con menor lluvia en el sur\n");
            p("\t 3: Semana con mayor lluvia en el norte\n");
            p("\t 4: La región con más lluvia mensual\n\t ");
            s("%d",&opcion);
            system("cls");
        } while(opcion<1 || opcion>4);
        
        switch(opcion)
        {
            case 1: centro(); break;
            case 2: sur();    break;
            case 3: norte();  break;
            case 4: mayor();  break;
        }

        system("cls");

        do
        {
            p("\n\n\t deseas calcular algo mas dentro de este programa? \n\t 1: si\n\t 2: salir ");
            s("%d",&opcion);
        } while(opcion<1 || opcion>2);

        if (opcion==2)
        {
            system("cls");
            p("\n\n\n\n\n\n\n\t\t\t\t\t\t");
            p("Gracias por usar mi programa.");
        }
        
        getch();
    } while (opcion==1);
    
}

void centro()
{
    int i,x,z=0;
    float promsem[48],prommens[12],suma=0,mayor;
    system("cls");
    p("\n\n\t introduce el promedio de la semana: ");
    for(i=0;i<12;i++)
    {
        for(x=1;x<=4;x++)
            {
                p("\n\t %d: ",z+1);
                s("%f",&promsem[z]);
                suma=suma+promsem[z];
                z++;
                system("cls");
            }
        prommens[i]=suma/4;
        suma=0;
    }
    system("cls");
    for(i=0;i<12;i++)
           p("\n\n\t el promedio del mes %d es: %.2f ",i+1,prommens[i]);
    mayor=prommens[0];
    for(i=1;i<12;i++)
    {
        if(prommens[i]>mayor)
            mayor=prommens[i];
    }
    p("\n\n\n\t y el promedio mas grande alcanzando hasta: %.2f",mayor);
    getch();
    system("cls");

}


void sur()
{
    system("cls");
    int i,imenor;
    float menor,sem[48];
    p("\n\n\t ingresa los datos de la semana ");
    for(i=0;i<48;i++)
    {
        p("\n\t %d: ",i+1);
        s("%f",&sem[i]);
    }
    menor=sem[0];
    for(i=1;i<48;i++)
    {
        if(sem[i]<menor)
            {
                menor=sem[i];
                imenor=i;
            }
    }
    if(menor==sem[0])
        imenor=0;
    system("cls");
    p("\n\n\t\t la semana con menos lluvia fue la semana %d con promedio de %.2f ",imenor+1,menor);
    getch();

}


void norte()
{
    system("cls");
    int i,imayor;
    float mayor,sem[48];
    p("\n\n\t ingresa los datos de la semana ");
    for(i=0;i<48;i++)
    {
        p("\n\t %d: ",i+1);
        s("%f",&sem[i]);
    }
    mayor=sem[0];
    for(i=1;i<48;i++)
    {
        if(sem[i]>mayor)
            {
                mayor=sem[i];
                imayor=i;
            }
    }
    if(mayor==sem[0])
        imayor=0;
    system("cls");
    p("\n\n\t\t la semana con mas lluvia fue la semana %d con promedio de %.2f ",imayor+1,mayor);
    getch();
}


void mayor()
{
    float centro1,norte1,sur1;
    p("\n\n\t empecemos con la regi�n centro: ");
    getch();
    centro1=mayor1();
    p("\n\n\t sigamos con el norte: ");
    getch();
    norte1=mayor1();
    p("\n\n\t por ultimo la regi�n sur: ");
    getch();
    sur1=mayor1()
    ;
    if(centro1==sur1 && sur1==norte1)
        p("\n\n\t\t todas las regiones mantuvieron el promedio mensual mas alto ");
    else
    {
        if(centro1>=norte1 && centro1>=sur1)
                    p("\n\n\t\t la region CENTRO tuvo el promedio mas alto de %.2f ",centro1);
        else
        {
            if(norte1>=centro1 && norte1>=sur1)
                p("\n\n\t\t la region NORTE tuvo el promedio mas alto de %.2f ",norte1);
            else
                p("\n\n\t\t la region SUR tuvo el promedio mas alto de %.2f ",sur1);
        }
    }
    getch();
}

float mayor1()
{
    int i,x,z=0;
    float promsem[48],prommens[12],suma=0,mayor;
    system("cls");
    p("\n\n\t introduce el promedio de la semana: ");
    for(i=0;i<12;i++)
    {
        for(x=1;x<=4;x++)
            {
                p("\n\t %d: ",z+1);
                s("%f",&promsem[z]);
                suma=suma+promsem[z];
                z++;
                system("cls");
            }
        prommens[i]=suma/4;
        suma=0;
    }
    system("cls");
    mayor=prommens[0];
    for(i=1;i<12;i++)
    {
        if(prommens[i]>mayor)
            mayor=prommens[i];
    }
    p("\n\t el promedio mas grande alcanzando hasta: %.2f",mayor);
    getch();
    system("cls");
    return mayor;
}




//    Aquí empieza el cine.


//variables globales...
char salaconv[5][5]={    {'*','A','B','C','D'},
                         {'1','0','0','0','0'},
                         {'2','0','0','0','0'},
                         {'3','0','0','0','0'},
                         {'4','0','0','0','0'}};

    char sala3d[5][5]={  {'*','A','B','C','D'},
                         {'1','0','0','0','0'},
                         {'2','0','0','0','0'},
                         {'3','0','0','0','0'},
                         {'4','0','0','0','0'}};
    int nino=0,adulto=0,contavendidos=0,totalpagar,totalparcial=0,ninoparcial=0,adultoparcial=0,contanino=0,contaadulto=0;
    int nino3=0,adulto3=0,contavendidos3=0,totalpagar3,totalparcial3=0,ninoparcial3=0,adultoparcial3=0,contanino3=0,contaadulto3=0;
    int resp;



void cine(void)
{
    do
    {

        
        system("cls");
        p("\n\n\n\t\t\t BIENVENIDO AL CINE ");
        cinecito();


        do
        {
            system("cls");
            p("¿deseas comprar mas boletos?:\n1: Si.\t2:No.");
            s("%d",&resp);

        } while (resp<1 || resp>2);
    } while (resp==1);

        totalpagar=nino+adulto;
        totalpagar3=nino3+adulto3;
        p("\n\n\n\n\n\n\t ts resultados son...\n\t sala convencional vendidos: %d, adultos: %d, ni�os: %d, subtotal: %d ",contavendidos,contaadulto,contanino,totalpagar);
        p("\n\t sala 3d: vendidos: %d, adultos: %d, ni�os: %d, subtotal: %d ",contavendidos3,contaadulto3,contanino3,totalpagar3);
    

    getch();
    
}

void cinecito(void)

{
    int x, opcion;
    do
    {
       p("\n\n\t\t\t que desea hacer?\n\t\t\t\t 1: sala normal\n\t\t\t\t 2: sala 3D ");
       s("%d",&opcion);
    }
    while(opcion<1 || opcion>2);
    switch(opcion)
    {
        case 1: 
        {
            if(contavendidos<16)
            {
    
                system("cls");
                salaconvencional(); break;

            } 
            else
            {
                system("cls");
                p("\n\n\n\n\t lo siento, la sala est� llena, vuelve pronto ");
                getch();
            }    
        } break;
        case 2: 
        {
            if (contavendidos3 != 16)
            {
                system("cls");
                salatres();    
            }
            else
            {
                system("cls");
                p("\n\n\n\n\t lo siento, la sala est� llena, vuelve pronto ");
                getch();
            }
            
            break;
        }
    }
}


void salaconvencional(void)
{
    int opcion;

    do
    {
        leerboleto();
        do  { 
                system("cls");
                p("\n\n\t deseas comprar otro boleto?\n\t 1: si\n\t 2: no ");
                s("%d",&opcion);
            }while(opcion<1 || opcion>2);
        if(contavendidos==16)
        {
            system("cls");
            p("Esta sala ya está llena.");
        }
    } while(opcion==1 && contavendidos!=16);
    
        totalparcial=ninoparcial+adultoparcial;
        p("\n\n\t total a pagar $ %d",totalparcial);
        ninoparcial=0;
        adultoparcial=0;

    getch();


}

void leerboleto(void)
{
    int fila,columna,opcion;
    do
    {
        system("cls");
        p("\n\n\t elige asiento, los disponibles apareceran en 0 y los ocupados 1 ");
        p("\n");
        imprimirconv();
        p("\n\n\n\tselecciona tu fila ");
        s("%d",&fila);
    } while (fila < 1 || fila > 4);

    do
    {
        system("cls");
        p("\n\n\t elige asiento, los disponibles apareceran en 0 y los ocupados 1 ");
        p("\n");
        imprimirconv();
        p("\n\n\n\tselecciona tu columna(con numero) ");
        s("%d",&columna);
    } while (columna < 1 || columna > 4);
    
    

    if (salaconv[fila][columna]=='0')
    {
        do
        {
            system("cls");
            p("\n\n\n");
            imprimirconv();
            p("\n\n\n\tboleto de \n\t1: ni\244o: %c30.00 pesos\n\t2: adulto: %c50.00 pesos ",36,36);
            p("\n");
            s("%d",&opcion);

        } while (opcion < 1 || opcion > 2);
        

        if(opcion==1)
            {nino+=30;
            ninoparcial+=30;
            contanino++;
            contavendidos++;}
        if(opcion==2)
            {adulto+=50;
            adultoparcial+=50;
            contaadulto++;
            contavendidos++;}
            
        p("\n\n\t adelante ");
        getch();
        salaconv[fila][columna]='1';
    }
    else 
    {
        system("cls");
        p("\n\n\t ocupado ");
    }
    getch();

}

     


void imprimirconv(void)
{
        int i=0,j=0;

    for(i=0;i<5;i++)
       {
         for(j=0;j<5;j++)
            p("%3c",salaconv[i][j]);

        p("\n");
       }
}

void salatres(void)
{
    int opcion;

    system("cls");
    do
    {
        leerboleto3();
        do
        {   system("cls");
            p("\n\n\t deseas comprar otro boleto?\n\t 1: si\n\t 2: no ");
            s("%d",&opcion);
        }while(opcion<1 || opcion>2);
    }while(opcion==1 && contavendidos3!=16);

    if (contavendidos3 == 16)
    {
        system("cls");
        p("La sala ya está llena...");
    }
    
    
    totalparcial3=ninoparcial3+adultoparcial3;
    ninoparcial3=0;
    adultoparcial3=0;
    p("\n\n\t total a pagar $ %d",totalparcial3);
    

    getch();
}

void leerboleto3(void)
{
    int fila,columna,opcion;
    do
    {
        system("cls");
        p("\n\n\t elige asiento, los disponibles apareceran en 0 y los ocupados 1 ");
        p("\n");
        imprimir3d();
        p("\n\n\n\tselecciona tu fila ");
        s("%d",&fila);
    } while (fila < 1 || fila > 4);

    do
    {
        system("cls");
        p("\n\n\t elige asiento, los disponibles apareceran en 0 y los ocupados 1 ");
        p("\n");
        imprimir3d();
        p("\n\n\n\tselecciona tu columna(con numero) ");
        s("%d",&columna);
    } while (columna < 1 || columna > 4);



    if (sala3d[fila][columna]=='0')
    {
        do
        {
            system("cls");
            p("\n\n\n");
            imprimir3d();
            p("\n\n\n\tboleto de \n\t1: ni\244o: %c60.00 pesos\n\t2: adulto: %c100.00 pesos ",36,36);
            p("\n");
            s("%d",&opcion);

        }while(opcion<1 || opcion>2);

        if(opcion==1)
            {
                nino3+=60;
                ninoparcial3+=60;
                contanino3++;
                contavendidos3++;
            }
        if(opcion==2)
            {
                adulto3+=100;
                adultoparcial3+=100;
                contaadulto3++;
                contavendidos3++;
            }

        p("\n\n\t adelante ");
        getch();
        sala3d[fila][columna]='1';

    } else
    {
        p("\n\n\t ocupado ");
    }
    getch();
}

void imprimir3d(void)
{
        int i=0,j=0;

    for(i=0;i<5;i++)
       {
         for(j=0;j<5;j++)
            p("%3c",sala3d[i][j]);

        p("\n");
       }
}


//AQUÍ EMPIEZAN LAS CALIFICACIONES


void calificaciones(void)
{
    system("cls");
    int i, j, calificaciones[20];
    int auxiliar[20],numero,posicion,mayormoda,posicionmayormoda;
    float media, varianza, desviacion, moda, aprovados=0, reprovados=0, porcentajeaprovados, porcentajereprobados, aspirantes=0;
    float numerito,numerote, suma=0,alumnos,alumnitos;
    system("cls");
    p("\n\n\t cuantos alumnos quieres ingresar? minimo 2, maximo 20 ");
    s("%f",&alumnos);
    while (alumnos<2 || alumnos>20)
    {
        system("cls");
        p("\n\n\t solo de 2 a 20 intenta de nuevo ");
        s("%f",&alumnos);
    }
    p("\n\n\t ingresa las calificaciones del ");
    for(i=0;i<alumnos;i++)
    {
        p("\n\n\t alumno %d ",i+1);
        s("%d",&calificaciones[i]);
        system("cls");
    }




    for(i=0;i<alumnos;i++)
    {
        suma+=calificaciones[i];
    }
    media=suma/alumnos;
    suma=0;
    for(i=0;i<alumnos;i++)
    {
        numerito=(media-calificaciones[i]);
        numerote=pow(numerito,2);
        suma=suma+numerote;
    }
    alumnitos=alumnos-1;
    varianza=suma/alumnitos;
    suma=0;
    desviacion=sqrt(varianza);
    for(i=0;i<20;i++)
        auxiliar[i]=0;
    for(i=0;i<alumnos;i++)
    {
        numero=calificaciones[i];
        posicion=i;
        for(j=i;j<alumnos;j++)
        {
            if(calificaciones[j]==numero)
                auxiliar[posicion]++;
        }
    }
    mayormoda=auxiliar[0];
    posicionmayormoda=0;
    for(i=0;i<alumnos;i++)
    {
        if(auxiliar[i]>mayormoda)
        {
            posicionmayormoda=i;
            mayormoda=auxiliar[i];
        }
    }
    moda=calificaciones[posicionmayormoda];
    for(i=0;i<alumnos;i++)
    {
        if(calificaciones[i]>=6)
            aprovados++;
        else reprovados++;
    }
    porcentajeaprovados=aprovados*100.0/alumnos*1.0;
    porcentajereprobados=reprovados*100.0/alumnos*1.0;
    for(i=0;i<alumnos;i++)
    {
        if(calificaciones[i]>8)
            aspirantes++;
    }
    system("cls");
    p("\n\n\n\n\t\t\t\t la media fue de: %.2f ",media);
    p("\n\t\t\t\t la varianza fue de: %.2f ",varianza);
    p("\n\t\t\t\t la desviacion estandar fue de: %.2f ",desviacion);
    p("\n\t\t\t\t la moda fue de: %.2f ",moda);
    p("\n\t\t\t\t los alumnos aprobados fueron: %.0f ",aprovados);
    p("\n\t\t\t\t los alumnos reprobados fueron: %.0f ",reprovados);
    p("\n\t\t\t el porcentaje de alumnos aprobados fue de: %.2f ",porcentajeaprovados);
    p("\n\t\t\t el porcentaje de alumnos reprobados fue de: %.2f ",porcentajereprobados);
    p("\n\t\t\t\t los aspirantes a una beca son: %.0f ",aspirantes);
    getch();
}