#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawellipse(int xc,int yc,int x, int y)
{	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
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
	setbkcolor(BLACK);
	setcolor(BLACK);
	midellipse(320,200,75,40);
	midellipse(320,200+10,75+22,40+15);
	midellipse(320,200+20,75+44,40+30);
	midellipse(320,200+30,75+66,40+45);
	midellipse(320,200+40,75+88,40+60);
	midellipse(320,200+50,75+110,40+75);
	midellipse(320,200+60,75+132,40+90);
	midellipse(320,200+70,75+154,40+105);
	setcolor(YELLOW);
	fillellipse(320,180,30,30);
	setcolor(RED);
	fillellipse(395,200,5,5);
	setcolor(WHITE);
	fillellipse(225,200,8,8);
	setcolor(BLUE);
	fillellipse(350,288,12,12);
	setcolor(RED);
	fillellipse(270,150,4,4);
	setcolor(LIGHTRED);
	fillellipse(445,300,22,22);
	setcolor(5);
	fillellipse(190,330,18,18);
	setcolor(6);
	fillellipse(320,390,10,10);
	setcolor(LIGHTBLUE);
	fillellipse(105,220,6,6);
	getch();
}
