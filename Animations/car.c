#include<stdio.h>
#include<graphics.h>
#include<math.h>
void ground()
{
        setcolor(BROWN) ;
        rectangle(1 , 374 , 639 , 479) ;
        floodfill(320 , 400 , BROWN) ;
}
void car(int x)
{
        setcolor(RED) ;
        rectangle(x , 330 , x + 50 , 350) ;
        floodfill(x + 25 , 340 , RED) ;
        rectangle(x - 20 , 350 , x + 70 , 365) ;
        floodfill(x + 25 , 360 , RED) ;
        setcolor(YELLOW) ;
        circle(x + 66 , 353 , 3) ;
        floodfill(x + 66 , 353 , YELLOW) ;
        setcolor(WHITE) ;
        circle(x , 365 , 10) ;
        circle(x , 365, 5) ;
        floodfill(x , 365 , WHITE) ;
        setcolor(BLACK) ;
        floodfill(x , 356 , WHITE) ;
        setcolor(WHITE) ;
        circle(x + 50 , 365 , 10) ;
        circle(x + 50 , 365 , 5) ;
        floodfill(x + 50 , 365 , WHITE) ;
        setcolor(BLACK) ;
        floodfill(x + 50 , 356 , WHITE) ;
        setcolor(BLUE) ;
        rectangle(x + 5 , 332 , x + 23 , 347) ;
        floodfill(x + 15 , 340 , BLUE) ;
        rectangle(x + 45 , 332 , x + 27 , 347) ;
        floodfill(x + 30 , 340 , BLUE) ;
}
void main()
{
        int gd = DETECT , gm , i ;
        initgraph(&gd , &gm , "") ;
        for(i = 75 ; i <= 550 ; i++)
        {
                ground() ;
                car(i) ;
                delay(20) ;
                if(i != 550)
                        cleardevice() ;
        }
        getch() ;
        closegraph() ;
}
