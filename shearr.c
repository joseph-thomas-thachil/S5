#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
int xa , ya , xb , yb , midx , midy ;
void shearing(float sh)
{
        float xn1 , yn1 , xn2 , yn2 , x1n1 , y1n1 , x2n2 , y2n2 ;
        xn1 = xa + sh * ya ;
        yn1 = ya ;
        xn2 = xb + sh * yb ;
        yn2 = yb ;
        x1n1 = xb + sh * ya ;
        y1n1 = ya ;
        x2n2 = xa + sh * yb ;
        y2n2 = yb ;
        setcolor(RED) ;
        line(0 , 240 , 640,240) ;
        line(320,0,320,480) ;
        setcolor(GREEN) ;
        line(xn1 + 240 , yn1 , x1n1 + 240 , y1n1 ) ;
        line(x1n1 + 240 , y1n1 , xn2 + 240 , yn2) ;
        line(xn2 +240, yn2 , x2n2+240 , y2n2) ;
        line(x2n2 + 240 , y2n2 , xn1+240 , yn1) ;
        getch() ;
}
void main()
{
        float sh ;
        int ch , gd = DETECT , gm ;
        printf("\n Enter the coordinates of rectangle : ") ;
        scanf("%d%d%d%d" , &xa , &ya , &xb , &yb) ;
        printf("\n Enter the value for shearing : ") ;
        scanf("%f" , &sh) ;
        initgraph(&gd , &gm , "") ;
        setcolor(BLUE) ;
        rectangle(320 +xa , ya , xb+320 , yb) ;
        shearing(sh) ;
        closegraph() ;
}
