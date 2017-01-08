#include<stdio.h>
#include<graphics.h>
#include<math.h>
void tap()
{
        setcolor(CYAN) ;
        rectangle(400 , 400 , 410 , 200) ;
        rectangle(350 , 200 , 400 , 210) ;
        floodfill(375 , 205 , CYAN) ;
        floodfill(405 , 300 , CYAN) ;
        setcolor(BROWN) ;
        circle(340 , 205 , 10) ;
        floodfill(340 , 205 , BROWN) ;
        rectangle(338 , 195 , 342 , 190) ;
        floodfill(340 , 192 , BROWN) ;
        rectangle(330 , 186 , 350 , 190) ;
        floodfill(340 , 188 , BROWN) ;
        rectangle(320 , 205 , 330 , 200) ;
        floodfill(325 , 203 , BROWN) ;
        rectangle(320 , 205 , 325 , 210) ;
        floodfill(323 , 207 , BROWN) ;

}
void bucket()
{
        int i ;
        setcolor(WHITE) ;
        rectangle(290 , 400 , 355 , 398) ;
        floodfill(300 , 399 , WHITE) ;
        rectangle(290 , 400 , 288 , 320) ;
        floodfill(289 , 360 , WHITE) ;
        rectangle(355 , 400 , 357 , 320) ;
        floodfill(356 , 360 , WHITE) ;
}
void main()
{
        int gd = DETECT , gm  , i , j ;
        initgraph(&gd , &gm , "") ;
        tap() ;
        bucket() ;
        for(i = 399 ; i > 320 ; i--)
        {
                setcolor(BLUE) ;
                for(j = 210 ; j < 400 ; j++)
                {
                        line(320 , j , 325 , j) ;
                        delay(1) ;
                }
                line(290 , i , 355 , i) ;
        }
        getch() ;
        closegraph() ;
}
