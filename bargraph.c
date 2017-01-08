#include<stdio.h>
#include<graphics.h>
void barc(int a[] , int n , int tot)
{
	    int gd = DETECT , gm ;
	    initgraph(&gd , &gm , "") ;
	    float w , x = 100 , y ;
	    int i  , j ;
	    line(100 , 400 , 600 , 400) ;
	    line(100 , 400 , 100 , 50) ;
        int val = round(tot * 10 / 350) ;
        char temp[10] ;
	    w = 400 / n ;
	    setcolor(WHITE) ;
	    for(i = 0 ; i < n ; i++)
	    {
		        y = (float)(300 * a[i]) / tot ;
		        rectangle(x , 400 - y , x + w , 400) ;
                sprintf(temp , "%d" , a[i]) ;
                outtextxy(70 , 395 - y , temp) ;
                line(95 , 400 - y , 105 , 400 - y) ;
		        setcolor(2 + i) ;
		        floodfill(x + 1 , 399 , WHITE) ;
                sprintf(temp , "Value %d" , i + 1) ;
                outtextxy(x , 420 , temp) ;
		        setcolor(WHITE) ;
		        x = x + w ;
	    }
	    getch() ;
	    closegraph() ;
}
void main()
{
  	    int a[10] ;
  	    int n , t = 0 ;
 	    printf("Enter the number of values : ") ;
 	    scanf("%d" , &n) ;
	    printf("Enter the values : ") ;
	    int i ;
	    for(i = 0 ; i < n ; i++)
	    {
	   	        scanf("%d" , &a[i]) ;
	    	    t = t + a[i] ;
	    }
  	    barc(a , n , t) ;
}
