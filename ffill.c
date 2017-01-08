#include<graphics.h>
#include<stdio.h>
#include<math.h>
void ffill(int x , int y , int fill , int b)
{	
        if(getpixel(x , y) == b)
	    {	
                putpixel(x , y , fill) ;
	    	    ffill(x + 1 , y , fill , b) ;
		        ffill(x - 1 , y , fill , b) ;		
		        ffill(x , y - 1 , fill , b) ;
		        ffill(x , y + 1 , fill , b) ;		
	    }
}
void main()
{	
        int gd = DETECT , gm ;
	    initgraph(&gd , &gm , "") ;
	    setcolor(GREEN) ;
	    rectangle(100 , 150 , 300 , 200) ;
	    ffill(200 , 175 , RED , BLACK) ;
	    getch() ;
        closegraph() ;
}
