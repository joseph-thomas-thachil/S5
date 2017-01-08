#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void bezier(int x[],int y[] , int n)
{	
        int gd = DETECT , gm ;
	    int i ;
	    double t , xt , yt ;
	    initgraph(&gd , &gm , "") ;
	    for(t = 0 ; t < 1 ; t += 0.0005)
	    {	
                 xt = pow(1 - t , 3) * x[0] + 3 * t * pow(1 - t , 2) * x[1] + 3 * pow(t , 2) * (1 - t) * x[2] + pow(t , 3) * x[3] ;
	    	    yt = pow(1 - t , 3) * y[0] + 3 * t * pow(1 - t , 2) * y[1] + 3 * pow(t , 2) * (1 - t) * y[2] + pow(t , 3) * y[3] ;
	    	    putpixel(xt , yt , RED) ;
	    }
	    for(i = 0 ; i<= n ; i++)
	     	    putpixel(x[i] , y[i] , WHITE) ;
	    getch() ;
        closegraph() ;	  
}
void main()
{	
        int x[10] , y[10] ;
  	    int i , n ;
        printf("\nEnter the degree : ") ;
        scanf("%d" , &n) ;
  	    printf("Enter the %d coordinates : " , n + 1) ;
  	    for(i = 0 ; i <= n ; i++)
    		    scanf("%d%d" , &x[i] , &y[i]) ;
  	    bezier(x , y , n) ; 
}
