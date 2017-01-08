#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void main()
{
        int gd = DETECT , gm  , i = 0 , x , y ;
        initgraph(&gd , &gm , "") ;
        while(i < 2000)
        {
                while(i < 2000)
                {
                        x = rand() % 640 ;
                        y = rand() % 480 ;
                        putpixel(x , y , CYAN) ;
                        i++ ;
                }
                cleardevice() ;
                i=0 ;
                pieslice(320 , 240 , 0 , 120 , 50) ;
        }
        getch() ;
        closegraph() ;
}
