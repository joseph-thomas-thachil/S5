#include<stdio.h>
#include<graphics.h>
#include<math.h>
void ground()
{
        setcolor(BROWN) ;
        rectangle(1 , 380 , 639 , 479) ;
        floodfill(320 , 400 , BROWN) ;
}
void baloon(int x , int n)
{
        setcolor(RED) ;
        circle(x + n , 260 , 20) ;
        floodfill(x + n , 260 , RED) ;
        setcolor(BLUE) ;
        circle(x + 50 + n , 260 , 20) ;
        floodfill(x + 50 + n , 260 , BLUE) ;
        setcolor(GREEN) ;
        circle(x + 25 + n , 240 , 20) ;
        floodfill(x + 25 + n , 240 , GREEN) ;
}
void man(int x , int n)
{
        setcolor(WHITE) ;
        circle(x , 300 , 10) ;
        floodfill(x , 300 , WHITE) ;
        line(x , 310 , x , 350) ;
        line(x , 350 , x - 10 + n , 380) ;
        line(x , 350 , x + 10 - n , 380) ;
        line(x , 310 , x - 10 + n , 340) ;
        line(x , 310 , x + 10 - n , 320) ;
        line(x + 10 - n , 320 , x + 30 - n , 320) ;
        setcolor(YELLOW) ;
        line(x + 30 - n , 320 , x + 20 + n , 280) ;
        line(x + 30 - n , 320 , x + 40 + n , 260) ;
        line(x + 30 - n , 320 , x + 60 + n , 280) ;
}
void main()
{
        int gd = DETECT , gm  , i ;
        initgraph(&gd , &gm , "") ;
        for(i = 40 ; i <= 550 ; i++)
        {
                ground() ;
                baloon(i , i % 5) ;
                man(i - 20 , i % 10) ;
                delay(30) ;
                if(i != 550)
                        cleardevice() ;
        }
        getch() ;
        closegraph() ;
}
