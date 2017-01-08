#include<graphics.h>
#include<stdio.h>
#include<math.h>
struct tbrl
{	int t , b , r , l ;
};
void main()
{	int gd = DETECT , gm ;
	float xa , xb , ya , yb , xmin = 100 , ymin = 100 , xmax = 300 , ymax = 300 ;
	struct tbrl l1 , l2 ;
	printf("Enter first coordinate : ") ;
	scanf("%d%d" , &xa , &ya) ;
	printf("Enter second coordinate : ") ;
	scanf("%d%d" , &xb , &yb) ;
	if(xa < xmin)
	{	l1.l = 1 ;
		l1.r = 0 ;
	}
	else if(xa > xmax)
	{	l1.l = 0 ;
		l1.r = 1 ;
	}
	else
	{	l1.l = 0 ;
		l1.r = 0 ;
	}
	if(ya < ymin)
	{	l1.b = 1 ;
		l1.t = 0 ;
	}
	else if(ya > ymax)
	{	l1.b = 0 ;
		l1.t = 1 ;
	}
	else
	{	l1.b = 0 ;
		l1.t = 0 ;
	}
	if(xb < xmin)
	{	l2.l = 1 ;
		l2.r = 0 ;
	}
	else if(xb > xmax)
	{	l2.l = 0 ;
		l2.r = 1 ;
	}
	else
	{	l2.l = 0 ;
		l2.r = 0 ;
	}
	if(yb < ymin)
	{	l2.b = 1 ;
		l2.t = 0 ;
	}
	else if(yb > ymax)
	{	l2.b = 0 ;
		l2.t = 1 ;
	}
	else
	{	l2.b = 0 ;
		l2.t = 0 ;
	}
	struct tbrl l3 , l4 ;
	l4.t = l1.t + l2.t ;
	l4.b = l1.b + l2.b ;
	l4.r = l1.r + l2.r ;
	l4.l = l1.l + l2.l ;
	l3.t = l1.t * l2.t ;
	l3.b = l1.b * l2.b ;
	l3.r = l1.r * l2.r ;
	l3.l = l1.l * l2.l ;
	initgraph(&gd , &gm ,"") ;
	setbkcolor(BLACK) ;
	rectangle(xmin , ymax , xmax , ymin) ;
	getch() ;
    closegraph() ;
}
