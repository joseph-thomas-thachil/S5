#include<graphics.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm," ");
	for(i=380;i>100;i+=10)
	{	setcolor(YELLOW);
		fillellipse(320,i,100,100);
		setcolor(5);
		line(0,350,320,400);
		line(320,400,640,350);
		line(640,350,640,480);
		line(640,480,0,480);
		line(0,480,0,350);
		floodfill(10,160,5);
		delay(20);
		cleardevice();
	}
	getch();
	
}

