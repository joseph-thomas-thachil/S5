#include<stdio.h>
#include<graphics.h>
void pie(int a[] , int n , int tot)
{
	    int gd = DETECT , gm ;
	    initgraph(&gd , &gm , "") ;
	    float st = 0 , en = 0;
	    int i ;
        char temp[20] ;
	    for(i = 0 ; i < n ; i++)
	    {
	  	        en = st + (float)(360 * a[i]) / tot ;
	  	        setcolor(2 + i) ;
	  	        pieslice(200 , 200 , st , en , 100) ;
	  	        st = en ;
                circle(450 , 20 + 20 * i , 5) ;
                floodfill(450 , 20 + 20 * i , 2 + i) ;
                sprintf(temp , "Value %d = %d" , i + 1 , a[i]) ;
                outtextxy(460 , 20 + 20 * i , temp) ;
	    }
        sprintf(temp , "Total : %d" , tot) ;
        outtextxy(460 , 30 + 30 * i , temp) ;
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
  	    pie(a , n , t) ;
}
    
  

