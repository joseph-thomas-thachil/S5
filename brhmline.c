#include<graphics.h>
#include<stdio.h>
#include<math.h>
void main()
{	
        int xa , xb , x , ya , yb , y , dx , dy , p , k ;	
	    printf("Enter first coordinate : ") ;
	    scanf("%d%d", &xa , &ya) ;
	    printf("\nEnter second coordinate : ") ;
	    scanf("%d%d" , &xb , &yb) ;
	    int gd = DETECT , gm ;
	    initgraph(&gd , &gm ,"") ;
	    setfontcolor(BLUE) ;
        if(xa < xb)
	    {	
                x = xa ;
		        y = ya ;
	    }
	    else
	    {	
                x = xb ;
		        y = yb ;
	    }
	    putpixel(round(x) , round(y) , BLUE) ;
	    dx = abs(xb - xa) ;
	    dy = abs(yb - ya) ;	
	    p = 2 * dy - dx ;
	    for(k = 0 ; k < dx ; k++)
		        if(p < 0)
		        {	
                        putpixel(round(++x) , round(y) , BLUE) ;
			            p += 2 * dy ;
		        }
		        else
		        {	
                        putpixel(round(x++) , round(y++) , BLUE) ;
			            p += 2 * dy - 2 * dx ;
		        }
	    getch() ;
        closegraph() ;
}
