#include<graphics.h>
#include<stdio.h>
#include<math.h>
int xm=100,ym=100,XM=300,YM=300;
int xint(int x1,int y1,int x2,int y2,int y)
{
	if(x2==x1)
		return x2;
	else
	{
		int m=(y2-y1)/(x2-x1);
		return x1+(y-y1)/m;
	}	
}

int yint(int x1,int y1,int x2,int y2,int x)
{
	if(y2==y1)
		return y2;
	else
	{
		int m=(y2-y1)/(x2-x1);
		return y1+m*(x-x1);
	}	
}

void main()
{			
	int x[10],y[10],n,i,c=0,xa[20],ya[20];
	printf("enter number of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter point %d:",i+1);
		scanf("%d%d",&x[i],&y[i]);
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	setbkcolor(BLACK);
	setcolor(RED);
	rectangle(xm,YM,XM,ym);
	setcolor(BLUE);
	for(i=0;i<n-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[i],y[i]);
	for(i=0;i<n-1;i++)
	{
		if(x[i]<xm&&x[i+1]>xm)
		{	xa[c]=xm;
			ya[c]=yint(x[i],y[i],x[i+1],y[i+1],xm);
			c++;
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;		
		}
		else if(x[i]>xm&&x[i+1]>xm)
		{
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;
		}
		else if(x[i]>xm&&x[i+1]<xm)
		{
			xa[c]=xm;
			ya[c]=yint(x[i],y[i],x[i+1],y[i+1],xm);
		}
	}
	if(x[0]<xm&&x[n-1]>xm)
		{	xa[c]=xm;
			ya[c]=yint(x[0],y[0],x[n-1],y[n-1],xm);
			c++;
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;		
		}
		else if(x[0]>xm&&x[n-1]>xm)
		{
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;
		}
		else if(x[0]>xm&&x[n-1]<xm)
		{
			xa[c]=xm;
			ya[c]=yint(x[0],y[0],x[n-1],y[n-1],xm);
		}
	for(i=0;i<n-1;i++)
	{
		if(x[i]>XM&&x[i+1]<XM)
		{	xa[c]=XM;
			ya[c]=yint(x[i],y[i],x[i+1],y[i+1],XM);
			c++;
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;		
		}
		else if(x[i]<XM&&x[i+1]<XM)
		{
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;
		}
		else if(x[i]<XM&&x[i+1]>XM)
		{
			xa[c]=XM;
			ya[c]=yint(x[i],y[i],x[i+1],y[i+1],XM);
		}
	}
	if(x[0]>XM&&x[n-1]<XM)
		{	xa[c]=XM;
			ya[c]=yint(x[0],y[0],x[n-1],y[n-1],XM);
			c++;
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;		
		}
		else if(x[0]<XM&&x[n-1]<XM)
		{
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;
		}
		else if(x[0]<XM&&x[n-1]>XM)
		{
			xa[c]=XM;
			ya[c]=yint(x[0],y[0],x[n-1],y[n-1],XM);
		}
	for(i=0;i<n-1;i++)
	{
		if(y[i]<ym&&y[i+1]>ym)
		{	ya[c]=ym;
			xa[c]=xint(x[i],y[i],x[i+1],y[i+1],ym);
			c++;
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;		
		}
		else if(y[i]>ym&&y[i+1]>ym)
		{
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;
		}
		else if(y[i]>ym&&y[i+1]<ym)
		{
			ya[c]=ym;
			xa[c]=xint(x[i],y[i],x[i+1],y[i+1],ym);
		}
	}
	if(y[0]<ym&&y[n-1]>ym)
		{	ya[c]=ym;
			xa[c]=xint(x[0],y[0],x[n-1],y[n-1],ym);
			c++;
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;		
		}
		else if(y[0]>ym&&y[n-1]>ym)
		{
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;
		}
		else if(y[0]>ym&&y[n-1]<ym)
		{
			ya[c]=ym;
			xa[c]=xint(x[0],y[0],x[n-1],y[n-1],ym);
		}
	for(i=0;i<n-1;i++)
	{
		if(y[i]>YM&&y[i+1]<YM)
		{	ya[c]=YM;
			xa[c]=xint(x[i],y[i],x[i+1],y[i+1],YM);
			c++;
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;		
		}
		else if(y[i]<YM&&y[i+1]<YM)
		{
			xa[c]=x[i+1];
			ya[c]=y[i+1];
			c++;
		}
		else if(y[i]<YM&&y[i+1]>YM)
		{
			ya[c]=YM;
			xa[c]=xint(x[i],y[i],x[i+1],y[i+1],YM);
		}
	}
	if(y[0]>YM&&y[n-1]<YM)
		{	ya[c]=YM;
			xa[c]=xint(x[0],y[0],x[n-1],y[n-1],YM);
			c++;
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;		
		}
		else if(y[0]<YM&&y[n-1]<YM)
		{
			xa[c]=x[n-1];
			ya[c]=y[n-1];
			c++;
		}
		else if(y[0]<YM&&y[n-1]>YM)
		{
			ya[c]=YM;
			xa[c]=xint(x[0],y[0],x[n-1],y[n-1],YM);
		}
	setcolor(YELLOW);
	for(i=0;i<c-1;i++)
	{	
		line(xa[i],ya[i],xa[i+1],ya[i+1]);				
	} 
	line(xa[0],ya[0],xa[i],ya[i]);
	getch();	
	
}

