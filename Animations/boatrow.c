#include<stdio.h>
#include<graphics.h>
#include<math.h>
void boat(int x)
{
        setcolor(BROWN) ;
        line(x - 35 , 380 , x + 35 , 380) ;
        line(x - 55 , 350 , x + 55 , 350) ;
        line(x - 55 , 350 , x - 35 , 380) ;
        line(x + 55 , 350 , x + 35 , 380) ;
        floodfill(x - 15 , 360 , BROWN) ;
}
void man(int x , int n)
{
        setcolor(WHITE) ;
        circle(x , 320 , 10) ;
        floodfill(x , 320 , WHITE) ;
        line(x , 330 , x , 350) ;
        line(x , 330 , x + 10 + n , 350 - n) ;
        setcolor(RED) ;
        line(x + 10 + n , 350 - n , x + 35 + n , 325 - n) ;
        line(x + 10 + n , 350 - n , x - 35 + n , 400 - n) ;
}
void river()
{
        setcolor(CYAN) ;
        rectangle(1 , 379 , 639 , 479) ;
        floodfill(320 , 400 , CYAN) ;
}
void main()
{
        int gd = DETECT , gm  , i ;
        initgraph(&gd , &gm , "") ;
        for(i = 65 ; i <= 575 ; i++)
        {
                river() ;
                boat(i) ;
                man(i , i % 5) ;
                delay(10) ;
                if(i != 575)
                        cleardevice() ;
        }
        getch() ;
        closegraph() ;
}
