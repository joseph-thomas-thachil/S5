#include <graphics.h>
#include <stdio.h>
#include<math.h>
void main()
{
         int gd = DETECT , gm , n , i ;
         int a[15] , max = 100 , angle = 0 , prangle = 0  , tot = 0 ;
         printf("\nEnter no of values : ") ;
         scanf("%d" , &n) ;
         printf("\nEnter the values : ") ;
         for(i = 0 ; i < n ; i++)
         {
                 scanf("%d" , &a[i]) ;
                 tot += a[i] ;
         }
         initgraph(&gd,&gm,"");
         circle(320,240,200);
         char temp[10] ;
         for(i=0;i<n;i++)
         {
                  setcolor(WHITE);
                  prangle=angle;
                  line(320,240,320+200*cos(angle*6.28/max),240+200*sin(angle*6.28/max));
                  angle+=a[i];
                  setcolor(i+1);
                  floodfill(320+190*cos(angle*6.28/max),240+190*sin(angle*6.28/max),WHITE);
                  sprintf(temp , "value %d" , i + 1) ;
                  outtextxy(330+220*cos((angle+prangle)*3.14/max),250+220*sin((angle+prangle)*3.14/max),temp);
                  sprintf(temp , "%d" , a[i]) ;
                  outtextxy(320+100*cos((angle+prangle)*3.14/max),240+100*sin((angle+prangle)*3.14/max),temp);
                  sprintf(temp , "%d %" , a[i] * 100 / tot) ;
                  outtextxy(320+150*cos((angle+prangle)*3.14/max),240+150*sin((angle+prangle)*3.14/max),temp);

         }
         sprintf(temp , "Total : %d" , tot) ;
         outtextxy(500,50,temp);
         getch();
         closegraph();
}

