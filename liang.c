#include<graphics.h>
#include<stdio.h>
#include<math.h>
void linedda(float xa , float ya , float xb , float yb , float c)
{	
        float step , k , dx , dy , xi , yi , x , y ;
	    dx = xb - xa ;
	    dy = yb - ya ;
	    if(abs(dx) > abs(dy))
		        step = abs(dx) ;
	    else
		        step = abs(dy) ;
	    xi = dx / step ;
	    yi = dy / step ;
	    x = xa ;
	    y = ya ;
	    putpixel(round(x) , round(y) , c) ;
	    for(k = 0 ; k < step ; k++)
	    {
                x += xi ;
		        y += yi ;
		        putpixel(round(x) , round(y) , c) ;
	    }
}
int large(float a[] , float b[])
{	
        int c = 0 , i ;	
	    for(i = 0 ; i < 4 ; i++)
		        if(a[i] < 0 && b[i] > c)
			            c = b[i] ;
	    return c ;
}
int small(float a[] , float b[])
{
        int c = 1 , i ;	
	    for(i = 0 ; i < 4 ;i++)
		        if(a[i] > 0 && b[i] < c)
			            c = b[i] ;
	    return c ;
}
void main()
{	
        int xmin = 100 , ymin = 100 , xmax = 200 , ymax = 200 , xa , ya , xb , yb , gd = DETECT , gm , f = 0 , i ;
	    float p[4] , q[4] , r[4] , dx , dy , u1 , u2 ;
	    printf("Enter first coordinate : ") ; 
	    scanf("%d%d", &xa , &ya) ;
	    printf("Enter second coordinate : ") ;
	    scanf("%d%d" , &xb , &yb) ;
	    dx = xb - xa ;
	    dy = yb - ya ;
	    p[0] =- dx ;
	    p[1] = dx ;
	    p[2] =- dy ;
	    p[3] = dy ;
	    q[1] = xmax - xa ;
	    q[0] = xa - xmin ;
	    q[3] = ymax - ya ;
	    q[2] = ya - ymin ;
	    for(i = 0 ; i < 4 ; i++)
		        if(p[i] == 0&& q[i] < 0)
			            f = 1 ;
	    initgraph(&gd , &gm , "") ;
	    setbkcolor(BLACK) ;
	    setcolor(BLUE) ;
	    rectangle(xmin , ymax , xmax , ymin) ;
	    if(f == 0)
	    {
                for(i = 0 ; i < 4 ; i++)
			            r[i] = q[i] / p[i] ;
		        u1 = large(p , r) ;
		        u2 = small(p , r) ;
		        if(u1 != 0 && u2 != 0 || u1 != 0 && u2 != 1)
		        {
                        xa += dx * u1 ;
			            ya += dy * u1 ;
			            xb = xa + dx * u2 ;
			            yb = ya + dy * u2 ;
			            linedda(xa , ya , xb , yb , RED) ;
		        }
		        if(u1 == 0 && u2 == 1)
			            linedda(xa , ya , xb , yb , RED) ;
	    }
	    getch() ;
        closegraph() ;
}
