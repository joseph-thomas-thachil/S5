#include<stdio.h>
#include<math.h>
#include<graphics.h>
void rotate(int l , int t , int r , int bm)
{
	    int gd = DETECT , gm ;
	    float theta ; 
	    int xa , ya , ra , i ;
	    int a[20] , b[20] , a1[20] , b1[20] , da , db ;
	    printf("Enter the fixed point and angle of rotation : ") ;
	    scanf("%d%d%d" , &xa , &ya , &ra) ;
	    initgraph(&gd , &gm , "") ;
        setcolor(BLUE) ;
	    rectangle(l , t , r , bm) ;
	    theta = (float)(ra * (3.14 / 180)) ;
	    a[0] = l ;
	    b[0] = t ;
	    a[1] = r ;
	    b[1] = t ;
	    a[2] = r ;
	    b[2] = bm ;
	    a[3] = l ;
	    b[3] = bm ;
	    for(i = 0 ; i < 4 ; i++)
	    {
		        a1[i] = (xa + ((a[i] - xa) * cos(-theta) - (b[i] - ya) * sin(-theta))) ;
		        b1[i] = (ya + ((a[i] - xa) * sin(-theta) + (b[i] - ya) * cos(-theta))) ;
	    }
        setcolor(RED) ;
	    for(i = 0 ; i < 4 ; i++)
	    {
		        if(i != 3)
			            line(a1[i] , b1[i] , a1[i + 1] , b1[i + 1]) ;
		        else
			            line(a1[i] , b1[i] , a1[0] , b1[0]) ;
	    }
}
void main()
{
	    int l , t , r , b ;
	    printf("Enter the coordinates of the rectangle : ") ;
	    scanf("%d%d%d%d" , &l , &t , &r , &b) ;
	    rotate(l , t , r , b) ;
	    getch() ;
	    closegraph() ;
}
