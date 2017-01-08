#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
	    int gd = DETECT , gm ;
	    int i ;
	    int x2 , y2 , x1 , y1 , x , y ;
	    printf("Enter the coordinates of the line : ") ;
	    scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2) ;
	    printf("Enter translation co-ordinates ") ;
	    scanf("%d%d" , &x , &y) ;
	    initgraph(&gm , &gm , "") ;
        setcolor(BLUE) ;
	    rectangle(x1 , y1 , x2 , y2) ;
	    x1 = x1 + x ;
	    y1 = y1 + y ; 
	    x2 = x2 + x ;
	    y2 = y2 + y ;
        setcolor(RED) ;
	    rectangle(x1 , y1 , x2 , y2) ;
	    getch() ;
	    closegraph() ;
}
