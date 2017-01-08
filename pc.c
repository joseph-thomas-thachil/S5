#include<graphics.h> 
#include<math.h> 
#include<stdio.h> 

int i,j=0,n; 
int rx1=200,rx2=500,ry1=200,ry2=400; 
float x11[8],y11[8]; 

void clip(float e,float f,float m) 
{ 
	while(e<rx1||e>rx2||f<ry1||f>ry2) 
	{ 
		if(e<rx1) 
		{ 
			f+=m*(rx1-e); 
			e=rx1; 
		} 
		else if(e>rx2) 
		{ 
			f+=m*(rx2-e); 
			e=rx2; 
		} 
		if(f<ry1) 
		{ 
			e+=(ry1-f)/m; 
			f=ry1; 
		} 
		else if(f>ry2) 
		{ 
			e+=(ry2-f)/m; 
			f=ry2; 
		} 
	} 
	x11[j]=e; 
	y11[j]=f; 
	j++; 
} 


int main() 
{ 
	int gd=DETECT,gm; 
	int i,n; 
	float x[8],y[8],m; 
	printf("NUMBER OF SIDES : "); 
	scanf("%d",&n); 
	printf("COODINATES "); 
	for(i=0;i<n;i++) 
	{ 
		scanf("%f%f",&x[i],&y[i]); 
	} 
	initgraph(&gd,&gm,""); 
	setcolor(WHITE); 
	rectangle(rx1,ry1,rx2,ry2); 
	for(i=0;i<n-1;i++) 
   		line(x[i],y[i],x[i+1],y[i+1]); 
	line(x[i],y[i],x[0],y[0]); 
	getch() ;
	cleardevice(); 
	for(i=0;i<n-1;i++) 
	{ 
		m=(y[i+1]-y[i])/(x[i+1]-x[i]); 
		clip(x[i],y[i],m); 
		clip(x[i+1],y[i+1],m); 
	} 
	m=(y[i]-y[0])/(x[i]-x[0]); 
	clip(x[i],y[i],m); 
	clip(x[0],y[0],m); 
	rectangle(rx1,ry1,rx2,ry2); 
	for(i=0;i<j-1;i++) 
		line(x11[i],y11[i],x11[i+1],y11[i+1]); 
	getch(); 
	return 0; 
} 








