#include<stdio.h> 
#include<stdlib.h> 
#include<graphics.h>
#include<math.h>


void dibujarLineas(int left, int top){

    //PLANO CARTESIANO 

    // Lineal vertical
    line(left, top-230, left, top+230);
    //Linea Horizontal 
    line(left-310, top, left+310, top);

    int less = 300;

    for (int i = 15; i >= 0; i--){
      
      line(left-less, top-5, left-less, top+5);
      less = less-30;

      if(less < 30){

        less = 30;
        break;
      }
    }

    for (int i = 15; i >= 0; i--){
      
      line(left+less, top-5, left+less, top+5);
      less = less+30;

      if(less > 300){

        less = 200;
        break;
      }
    }

    for (int i = 15; i >= 0; i--){
      
      line(left-5, top-less, left+5, top-less);
      less = less-20;

      if(less < 20){

        less = 20;
        break;
      }
    }

    for (int i = 15; i >= 0; i--){
      
      line(left-5, top+less, left+5, top+less);
      less = less+20;

      if(less > 200){

        less = 0;
        break;
      }
    }
}



void modoGrafico(int x1, int x2, int y1, int y2,int x1ab, int x2ab, int y1ab, int y2ab, int maxx, int maxy, int mulcoorx, int mulcoory)
{

    int gd = DETECT,gm,left=320,top=240,right=0,bottom=0,x= 300,y=150,radius=50;


    //Inicia el modo grafico

    initgraph(&gd,&gm,NULL);


    // Consola es 640 * 480

    //lineas del plano

    dibujarLineas(left, top);

    //Convierto mis valores finales en enteros para poder graficarlos.

    int x1fin,x2fin,y1fin,y2fin;

    x1fin = floor(x1 * 300 / maxx);
    x2fin = floor(x2 * 300 / maxx);
    y1fin = floor(y1 * 200 / maxy);
    y2fin = floor(y2 * 200 / maxy);


    //Función que grafica los puntos

    setcolor(9);
    line(left + x1fin, top - y1fin, left + x2fin, top - y2fin);

    char str[4];
    int valinix = 20;
    int coortop = 8;

    //Escalción numerica para x+

    for(int i = 0; i < 10; i++){

      sprintf(str, "%d", mulcoorx * (i + 1));
      outtextxy(left+(i * 30 + valinix ),top+coortop,str);
    }

    valinix = 40;
    coortop = 16;

    //Escalación numerica para x-

    int cont = 0;

    for (int i = -1; i > -11; i--)
    {

      sprintf(str, "%d", mulcoorx * i);
      outtextxy(left+(cont * -30 - valinix ),top-coortop,str);

      cont++;
    }


    //Escalción numerica para 'Y'+

    int valiniy = 24;
    int coorleft = 8;

    for (int i = 0; i < 10; i++)
    {
      sprintf(str, "%d", mulcoory * (i + 1));
      outtextxy(left + coorleft, top + (i * -20 - valiniy), str);
    }

    //Escalción numerica para 'Y'

    valiniy = 16;
    coorleft = 36;

    cont = -1;

    for (int i = 0; i < 10; ++i)
    {

      sprintf(str, "%d", mulcoory * cont);
      outtextxy(left - coorleft, top + (i * 20 + valiniy), str);

      cont = cont - 1;
    }

    delay(500000); 
    closegraph();
}



int main(){

  int m,b, y1, y2;

  printf("\n\n FUNCION LINEAL: \n\n F(x)=   mx + b \n\n");

  printf(" Digite el valor de 'M' : ");
  scanf("%i",&m);

  printf(" Digite el valor de 'B' : ");
  scanf("%i",&b);

  printf("-----------------------------\n");
  printf(" \n\n\n F(x) = %ix + %i.\n\n",m, b);

  
  //Digitamos el valor de x1

  int x1;
  printf(" Digite la coordenada X1: ");
  scanf("%i",&x1);

  
  //Reemplazamos x1 en la formula y hallamos y1

  y1 = m * x1 + b;

  
  //Digitamos el valor de x2

  int x2;

  printf("\n\n Digite la coordenada x2: ");
  scanf("%i",&x2);

  
  //Reemplazamos x2 en la formula y hallamos y2

  y2 = m * x2 + b;

  printf("\n\n Punto 1. (%i,%i)", x1,y1);
  printf("\n Punto 2. (%i,%i)", x2,y2);

  printf("\n");


  //Hallar el valor absoluto de los puntos encontrados anteriormente.

  float x1ab,x2ab,y1ab,y2ab;

  x1ab = fabs(x1);
  x2ab = fabs(x2);
  y1ab = fabs(y1);
  y2ab = fabs(y2);


  //Para escalar

  //Identifico cual es el valor mayor en X.

  int maxx,maxy;
  int mulcoorx,mulcoory;

  if (x1ab > x2ab)
  {
    mulcoorx = ceil(x1ab / 10);
    maxx = mulcoorx * 10;
  }

  if (x2ab >= x1ab)
  {
    mulcoorx = ceil(x2ab / 10);
    maxx = mulcoorx * 10;
  }


  //Identifico cual es el valor mayor en y


  if (y1ab > y2ab){
    mulcoory = ceil(y1ab / 10);
    maxy = mulcoory * 10;
  }

  if (y2ab >= y1ab)
  {
    mulcoory = ceil(y2ab / 10);
    maxy = mulcoory * 10;
  }


  //Llave de paso para entrar al modo grafico (cualquier tecla diferente de 0)

  modoGrafico(x1, x2, y1, y2, x1ab, x2ab, y1ab, y2ab, maxx, maxy, mulcoorx, mulcoory);

  return 0;
}