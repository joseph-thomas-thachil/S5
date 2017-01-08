#include<stdio.h>
#include<graphics.h>
#include<math.h>
void tree()
{
        setcolor(GREEN) ;
        rectangle(1 , 380 , 639 , 479) ;
        floodfill(320 , 400 , GREEN) ;
        setcolor(BROWN) ;
        rectangle(320 , 380 , 340 , 210) ;
        floodfill(330 , 350 , BROWN) ;
        line(320 , 210 , 300 , 180) ;
        line(300 , 180 , 330 , 210) ;
        floodfill(325 , 208 , BROWN) ;
        line(340 , 210 , 360 , 180) ;
        line(360 , 180 , 330 , 210) ;
        floodfill(335 , 208 , BROWN) ;
        setcolor(GREEN) ;
        circle(270 , 160 , 40) ;
        floodfill(270 , 160 , GREEN) ;
        circle(390 , 160 , 40) ;
        floodfill(390 , 160 , GREEN) ;
        circle(330 , 100 , 70) ;
        floodfill(330 , 100 , GREEN) ;
}
void man(int y , int n)
{
        setcolor(WHITE) ;
        circle(300 , y , 10) ;
        floodfill(300 , y , WHITE) ;
        line(320 , y + 20 , 305 , y + 10) ;
        line(305 , y + 10 , 340 , y - n) ;
        line(320 , y + 20 , 340 , y + 10 - n) ;
        line(340 , y + 10 , 340 , y + 30 - n) ;
}
void main()
{
        int gd = DETECT , gm , i ;
        initgraph(&gd , &gm , "") ;
        for(i = 345 ; i >= 210 ; i--)
        {
                tree() ;
                man(i , i % 5) ;
                delay(30) ;
                if(i != 210)
                        cleardevice() ;
        }
        getch() ;
        closegraph() ;
}
