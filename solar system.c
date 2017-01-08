#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawellipse(int xc,int yc,int x, int y)
{	putpixel(xc+x,yc+y,BLUE);
	putpixel(xc-x,yc+y,BLUE);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc-y,BLUE);
}
void midellipse(int xc,int yc,int rx,int ry)
{	float x=0,y=ry,p=ry*ry-rx*x*ry+(1/4)*rx*rx;
	drawellipse(xc,yc,x,y);
	while(2*ry*ry*x<2*rx*rx*y)
	{	x++;
		if(p<0)
			p+=2*ry*ry*x+ry*ry;
			
		else
		{	y--;
			p+=2*ry*ry*x-2*rx*rx*y+ry*ry;
		}
		drawellipse(xc,yc,x,y);
	}
	p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
	while(y>=0)
	{	y--;	
		if(p>0)
			p-=2*rx*rx*y+rx*rx;
			
		else
		{	x++;
			p+=2*ry*ry*x-2*rx*rx*y+rx*rx;
		}
		drawellipse(xc,yc,x,y);
	}
}

void main()
{	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	setbkcolor(WHITE);
	setcolor(BLACK);
	midellipse(320,240,100,100);
	getch();
}
