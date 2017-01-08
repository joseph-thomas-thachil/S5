#include<stdio.h>
#include<graphics.h>
#include<math.h>
void leaf(int ang , int d)
{
        int r = 100 ;
        float theta = ang * 3.14 / 180 ;
        float x1 , x2 , y1 , y2 ;
        x1 = 320 + r * cos(theta) ;
        y1 = 240 + r * sin(theta) ;
        setcolor(WHITE) ;
        pieslice(320 , 240 , 0 + ang + d , 10 + ang + d , 100) ;
        pieslice(320 , 240 , 120 + ang + d , 130 + ang + d , 100) ;
        pieslice(320 , 240 , 240 + ang + d , 250 + ang + d , 100) ;
}
void main()
{
        int gd = DETECT , gm ;
        initgraph(&gd , &gm , "") ;
        setcolor(BLUE) ;
        int i = 0 , d = 0 ;
        char ch ;
        while(1)
        {
                circle(320 , 240 , 20) ;
                leaf(i , d) ;
               // delay(d) ;
                if(kbhit())
                {
                        ch = getch() ;
                if(ch == '1')
                        d = 0 ;
                else if(ch == '2')
                        d = 100 + i ;
                else if(ch == '3')
                        d = 200 + i ;
                else if(ch == '0')
                        break ;
                }
                        cleardevice() ;
                i++ ;
        }
        getch() ;
        closegraph() ;
}
