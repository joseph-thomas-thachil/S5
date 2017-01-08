#include<graphics.h>
#include<stdio.h>
#include<math.h>
void boundary(int x , int y , int fill , int b)
{	
        int cur = getpixel(x , y) ;
        if(cur != b && cur != fill)
	    {	
                putpixel(x , y , fill) ;
                boundary(x + 1 , y , fill , b) ;
                boundary(x - 1 , y , fill , b) ;		
                boundary(x , y - 1 , fill ,b) ;
                boundary(x , y + 1 , fill , b) ;		
	}
}
void main()
{	
        int gd = DETECT , gm ;
        initgraph(&gd , &gm , "") ;
        setcolor(BLUE) ;
        rectangle(100 , 150 , 300 , 250) ;
        boundary(150 , 200 , RED , BLUE) ;
        getch() ;
        closegraph() ;
}
