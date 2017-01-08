#include<graphics.h>
#include<stdio.h>
#include<math.h>

void translate(int *x,int *y,int tx,int ty)
{	*x+=tx;
	*y+=ty;	
}
void scale(int *x,int *y,int sx,int sy)
{	*x*=sx;
	*y*=sy;	
}
void rotate(int *x,int *y,float t)
{	*x=((*x)*cos(t))-((*y)*sin(t));
	*y=((*x)*sin(t))+((*y)*cos(t));	
}
void shearx(int *x,int *y,int shx)
{	*x+=shx*(*y);	
}
void sheary(int *x,int *y,int shy)
{	*y+=shy*(*x);	
}

void linedda(int xa,int ya,int xb,int yb,int c)
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
	putpixel(round(x),round(y),c);
	for(k=0;k<step;k++)
	{	x+=xi;
		y+=yi;
		putpixel(round(x),round(y),c);
	}
}
void main()
{	int gd=DETECT,gm,xa,xb,ya,yb,xc,yc,xd,yd,tx,ty,sx,sy;
	float t,shx,shy;
	printf("enter point 1:");
	scanf("%d%d",&xa,&ya);
	printf("enter point 2:");
	scanf("%d%d",&xb,&yb);
	printf("enter point 3:");
	scanf("%d%d",&xc,&yc);
	printf("enter point 4:");
	scanf("%d%d",&xd,&yd);
	printf("enter tx:");
	scanf("%d",&tx);
	printf("enter ty:");
	scanf("%d",&ty);
	printf("enter theta:");
	scanf("%f",&t);
	t*=3.14/180;
	printf("enter sx:");
	scanf("%d",&sx);
	printf("enter sy:");
	scanf("%d",&sy);
	printf("enter shx:");
	scanf("%f",&shx);
	printf("enter shy:");
	scanf("%f",&shy);
	initgraph(&gd,&gm," ");
	setbkcolor(WHITE);
	linedda(xa,ya,xb,yb,BLUE);
	linedda(xa,ya,xc,yc,BLUE);
	linedda(xc,yc,xd,yd,BLUE);
	linedda(xb,yb,xd,yd,BLUE);
	translate(&xa,&ya,tx,ty);
	translate(&xb,&yb,tx,ty);
	translate(&xc,&yc,tx,ty);
	translate(&xd,&yd,tx,ty);
	rotate(&xa,&ya,t);
	rotate(&xb,&yb,t);
	rotate(&xc,&yc,t);
	rotate(&xd,&yd,t);
	scale(&xa,&ya,sx,sy);
	scale(&xb,&yb,sx,sy);
	scale(&xc,&yc,sx,sy);
	scale(&xd,&yd,sx,sy);
	shearx(&xa,&ya,shx);
	shearx(&xb,&yb,shx);
	shearx(&xc,&yc,shx);
	shearx(&xd,&yd,shx);
	sheary(&xa,&ya,shy);
	sheary(&xb,&yb,shy);
	sheary(&xc,&yc,shy);
	sheary(&xd,&yd,shy);
	linedda(xa,ya,xb,yb,RED);
	linedda(xa,ya,xc,yc,RED);
	linedda(xc,yc,xd,yd,RED);
	linedda(xb,yb,xd,yd,RED);
	getch();
	
}
