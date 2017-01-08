#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawcircle(int xc , int yc , int x , int y)
{
        putpixel(xc + x , yc + y , BLUE) ;
	    putpixel(xc - x , yc + y , BLUE) ;
	    putpixel(xc + x , yc - y , BLUE) ;
	    putpixel(xc - x , yc - y , BLUE) ;
	    putpixel(xc + y , yc + x , BLUE) ;
	    putpixel(xc - y , yc + x , BLUE) ;
	    putpixel(xc + y , yc - x , BLUE) ;
	    putpixel(xc - y , yc - x , BLUE) ;
}
void midcircle(int xc , int yc , int r)
{	
        int x = 0 , y = r , p = 1 - r ;
	    drawcircle(xc , yc , x , y) ;
	    while(x < y)
	    {
                x++ ;
		        if(p < 0)
			            p += 2 * x + 1 ;	
		        else
		        {
                        y-- ;
			            p += 2 * (x - y) + 1 ;
		        }
		        drawcircle(xc , yc , x , y) ;
	    }
}
void main()
{	
        int xc , yc , r , gd = DETECT , gm ;
	    printf("Enter the center : ") ;
	    scanf("%d%d" , &xc , &yc) ;
	    printf("Enter the radius : ") ;
	    scanf("%d" , &r) ;
	    initgraph(&gd , &gm , "") ;
	    setfontcolor(BLUE) ;
	    midcircle(xc , yc , r) ;
	    getch() ;
        closegraph() ;
}
