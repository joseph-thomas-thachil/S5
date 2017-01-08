#include<graphics.h>
#include<stdio.h>
#include<math.h>
void linedda(int xa , int ya , int xb , int yb)
{	
	    float step , k , dx , dy , xi , yi , x , y ;
	    dx = xb - xa ;
	    dy = yb - ya ;
	    if(abs(dx) > abs(dy))
		        step = abs(dx) ;
	    else
		        step = abs(dy) ;
	    xi = dx / step ;
	    yi = dy / step ;
	    x = xa ;
	    y = ya ;
	    putpixel(round(x) , round(y) , BLUE) ;
	    for(k = 0 ; k < step ; k++)
	    {	
                x += xi ;
		        y += yi ;
		        putpixel(round(x) , round(y) , BLUE) ;
	    }
}
void main()
{	
        int gd = DETECT , gm , xa , xb , ya , yb ;
	    printf("Enter first coordinate : ") ;
	    scanf("%d%d" , &xa , &ya) ;
	    printf("\nEnter second coordinate : ") ;
	    scanf("%d%d" , &xb , &yb) ;
	    initgraph(&gd , &gm , "") ;
	    setfontcolor(BLUE) ;
	    linedda(xa , ya , xb , yb) ;
	    getch() ;
	    closegraph() ;
}
