#include<graphics.h>
#include<stdio.h>
#include<math.h>

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
{	int gd=DETECT,gm,xa,xb,ya,yb,xc,yc;
	printf("enter point 1:");
	scanf("%d%d",&xa,&ya);
	printf("enter point 2:");
	scanf("%d%d",&xb,&yb);
	printf("enter point 3:");
	scanf("%d%d",&xc,&yc);
	initgraph(&gd,&gm," ");
	setbkcolor(WHITE);
	setfontcolor(BLUE);
	linedda(xa,ya,xb,yb);
	linedda(xa,ya,xc,yc);
	linedda(xc,yc,xb,yb);
	getch();
	
}
