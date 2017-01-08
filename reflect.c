#include<graphics.h>
#include<stdio.h>
#include<math.h>
void reflectyx(int xa , int ya , int xb , int yb)
{	
        int c = xa ;
	    xa = ya ;
	    ya = c ;
	    c = xb ;
	    xb = yb ;
	    yb = c ;
        setcolor(BLUE) ;
	    line(xa + 320 , ya + 240 , xb + 320 , yb + 240) ;	
}
void reflectymx(int xa , int ya , int xb , int yb)
{	
        int c = -xa ;
	    xa = -ya ;
	    ya = c ;
	    c = -xb ;
	    xb = -yb ;
	    yb = c ;
        setcolor(WHITE) ;
	    line(xa + 320 , ya + 240 , xb + 320 , yb + 240) ;	
}
void reflecty(int xa , int ya , int xb , int yb)
{	
        setcolor(GREEN) ;
        line(-xa + 320 , ya + 240 , -xb + 320 , yb + 240) ;	
}
void reflectx(int xa , int ya , int xb , int yb)
{	
        setcolor(YELLOW) ;
        line(xa + 320 , -ya + 240 , xb + 320 , -yb + 240) ;
}
void main()
{	
        int gd = DETECT , gm , xa , ya , xb , yb , xc , yc , ch ;
	    printf("Enter first coordinate : ") ;
	    scanf("%d%d" , &xa , &ya) ;
	    printf("Enter second coordinate : ") ;
	    scanf("%d%d" , &xb , &yb) ;
	    printf("Enter third coordinate : ") ;
	    scanf("%d%d" , &xc , &yc) ;
        do
        {
                printf("\nMENU\n1.About X axis\n2.About Y axis\n3.About line Y = -X") ;
                printf("\n4.About line Y = X\n5.Exit\nEnter choice : ") ;
                scanf("%d" , &ch) ;
	            initgraph(&gd , &gm , "") ;
                setcolor(RED) ;
	            line(0 , 240 , 640 , 240) ;
	            line(320 , 0 , 320 , 480) ;
                setcolor(CYAN) ;
	            line(xa + 320 , ya + 240 , xb + 320 , yb + 240) ;
	            line(xa + 320 , ya + 240 , xc + 320 , yc + 240) ;
	            line(xb + 320 , yb + 240 , xc + 320 , yc + 240) ;
                if(ch == 1)
                {
	                    reflectx(xa , ya , xb , yb) ;
	                    reflectx(xc , yc , xb , yb) ;
	                    reflectx(xc , yc , xa , ya) ;
                }
                else if(ch == 2)
                {
	                    reflecty(xa , ya , xb , yb) ;
	                    reflecty(xc , yc , xb , yb) ;
	                    reflecty(xc , yc , xa , ya) ;
                }
                else if(ch == 3)
                {
	                    reflectyx(xa , ya , xb , yb) ;
	                    reflectyx(xc , yc , xb , yb) ;
	                    reflectyx(xc , yc , xa , ya) ;
                }
                else if(ch == 4)
                {
	                    reflectymx(xa , ya , xb , yb) ;
	                    reflectymx(xc , yc , xb , yb) ;
	                    reflectymx(xc , yc , xa , ya) ;
                }
                if(ch !=5)
                {
	                    getch() ;
                        closegraph() ;
                }
        }while(ch != 5) ;
}
