#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawellipse(int xc , int yc , int x , int y)
{
        putpixel(xc + x , yc + y , BLUE) ;
	    putpixel(xc - x , yc + y , BLUE) ;
	    putpixel(xc + x , yc - y , BLUE) ;
	    putpixel(xc - x , yc - y , BLUE) ;
}
void main()
{
        int xc , yc , rx , ry , gd = DETECT , gm ;
	    float x , y , rad = 3.1417 / 180 , t = 0 , tend = 90 , angle ;
	    printf("Enter the centre : ") ;
	    scanf("%d%d" , &xc , &yc) ;
	    printf("Enter X radius : ") ;
	    scanf("%d" , &rx) ;
	    printf("Enter Y radius : ") ;
	    scanf("%d" , &ry) ;
	    initgraph(&gd , &gm , "") ;
	    while(t <= tend)
	    {	
                angle = rad * t ;
		        x = rx * cos(angle);
		        y = ry * sin(angle) ;
		        drawellipse(xc , yc , x , y) ;
		        t += 0.25 ;
	    }
	    getch() ;
        closegraph() ;
}
