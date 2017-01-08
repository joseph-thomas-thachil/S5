#include<stdio.h>
#include<graphics.h>
void scal(int l , int t , int r , int b)
{
	    int gd = DETECT , gm ;
	    float dx , dy ;
	    printf("Enter the scaling factors : ") ;
	    scanf("%f%f" , &dx , &dy) ;
	    initgraph(&gd , &gm , "") ;
        setcolor(BLUE) ;
	    rectangle(l , t , r , b) ;
	    l *= dx ;
	    t *= dy ;
	    r *= dx ;
	    b *= dy ;
        setcolor(RED) ;
	    rectangle(l , t , r , b) ;
}
void main()
{
	    int l , t , r , b ;
	    printf("Enter the coordinates of the rectangle : ") ;
	    scanf("%d%d%d%d" , &l , &t , &r , &b) ;
	    scal(l , t , r , b) ;
	    getch() ;
	    closegraph() ;
}
