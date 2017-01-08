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
void brsncircle(int xc , int yc , int r)
{	
        int x = 0 , y = r , p = 3 - 2 * r ;
	    putpixel(xc + x , yc + y , BLUE) ;
	    while(x < y)
	    {	
                if(p < 0)
		        {	       
                        p += 4 * x + 6 ;
			            x++ ;
		        }
		        else
		        {	
                        p += 4 * (x - y) + 10 ;
			            x++ ;
			            y-- ;
		        }
		        drawcircle(xc , yc , x , y) ;
	    }
}
void main()
{	
        int xc , yc , r , gd = DETECT , gm ;
	    printf("Enter the centre : ") ;
	    scanf("%d%d" , &xc , &yc) ;
	    printf("Enter the radius : ") ;
	    scanf("%d" , &r) ;
	    initgraph(&gd ,&gm , "") ;
	    setfontcolor(BLUE) ;
	    brsncircle(xc , yc , r) ;
	    getch() ;
        closegraph() ;
}
