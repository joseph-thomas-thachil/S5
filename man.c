#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawcircle(int xc,int yc,int x, int y)
{	putpixel(xc+x,yc+y,BLUE);
	putpixel(xc-x,yc+y,BLUE);
	putpixel(xc+x,yc-y,BLUE);
	putpixel(xc-x,yc-y,BLUE);
	putpixel(xc+y,yc+x,BLUE);
	putpixel(xc-y,yc+x,BLUE);
	putpixel(xc+y,yc-x,BLUE);
	putpixel(xc-y,yc-x,BLUE);
}
void brsncircle(int xc,int yc,int r)
{	int x=0,y=r,p=3-2*r;
	putpixel(xc+x,yc+y,BLUE);
	while(x<y)
	{	if(p<0)
		{	p+=4*x+6;
			x++;
		
		}
		else
		{	p+=4*(x-y)+10;
			x++;
			y--;
			
		}
		drawcircle(xc,yc,x,y);
	}
}

void linedda(int xa,int ya,int xb,int yb)
{	
	float step,k,dx,dy,xi,yi,x,y;
	dx=xb-xa;
	dy=yb-ya;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	xi=dx/step;
	yi=dy/step;
	x=xa;
	y=ya;
	putpixel(round(x),round(y),BLUE);
	for(k=0;k<step;k++)
	{	x+=xi;
		y+=yi;
		putpixel(round(x),round(y),BLUE);
	}
}

void main()
{	int gd=DETECT,gm,i;
	initgraph(&gd,&gm," ");
	setbkcolor(YELLOW);
	for(i=0;i<=440;i+=10)
	{	brsncircle(100+i,130,70);
		linedda(100+i,200,100+i,350);
		linedda(100+i,250,0+i,300);
		linedda(100+i,250,200+i,300);
		linedda(100+i,350,0+i,480);
		linedda(100+i,350,200+i,480);
		delay(20);
		cleardevice();
	}
	for(i=440;i>0;i-=10)
	{	brsncircle(100+i,130,70);
		linedda(100+i,200,100+i,350);
		linedda(100+i,250,0+i,300);
		linedda(100+i,250,200+i,300);
		linedda(100+i,350,0+i,480);
		linedda(100+i,350,200+i,480);
		delay(20);
		cleardevice();
	}
	brsncircle(100,130,70);
		linedda(100,200,100,350);
		linedda(100,250,0,300);
		linedda(100,250,200,300);
		linedda(100,350,0,480);
		linedda(100,350,200,480);
	/*brsncircle(300,250,50);
	linedda(300,300,300,400);
	linedda(300,350,200,300);
	linedda(300,350,400,300);
	linedda(300,400,250,480);
	linedda(300,400,350,480);*/
	getch();
}
