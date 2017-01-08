#include<graphics.h>
#include<stdio.h>
#include<math.h>
struct tbrl
{	
        int t , b , r , l ;
} ;
void main()
{
        int gd = DETECT , gm ;	
        float xa , xb , ya , yb , xmin = 100 , ymin = 100 , xmax = 300 , ymax = 300 ;
        struct tbrl l1 , l2 ;
        printf("Enter first coordinate : ") ;
        scanf("%f%f" , &xa , &ya) ;
        printf("Enter second coordinate : ") ;
        scanf("%f%f" , &xb , &yb) ;
        if(xa < xmin)
                l1.l = 1 ;
        else
                l1.l = 0 ;
        if(xa > xmax)
		
                l1.r = 1 ;
        else
                l1.r = 0 ;
        if(ya < ymin)
                l1.b = 1 ;
        else
                l1.b = 0 ;
        if(ya > ymax)
                l1.t = 1 ;
	    else
		        l1.t = 0 ;
        if(xb < xmin)
		        l1.l = 1 ;
        else
		        l1.l = 0 ;
	    if(xb > xmax)
		        l1.r = 1 ;
	    else
		        l1.r = 0 ;
	    if(yb < ymin)
		        l1.b = 1 ;
	    else
		        l1.b = 0 ;
	    if(yb > ymax)
		        l1.t = 1 ;
	    else
		        l1.t = 0 ;
	    struct tbrl l4 ;
	    l4.t = l1.t + l2.t ;
	    l4.b = l1.b + l2.b ;
	    l4.r = l1.r + l2.r ;
	    l4.l = l1.l + l2.l ;
        float m = (yb - ya) / (xb - xa) ;
	    initgraph(&gd , &gm , "") ;
	    setbkcolor(BLACK) ;
	    rectangle(xmin , ymax , xmax , ymin) ;
	    while(!(l4.t == 0 && l4.b == 0 && l4.r == 0 && l4.l == 0))
	    {	
            l4.t = l1.t * l2.t ;
            l4.b = l1.b * l2.b ;
            l4.r = l1.r * l2.r ;
            l4.l = l1.l * l2.l ;
            if(l4.t == 0 && l4.b == 0 && l4.r == 0 && l4.l == 0)   
            {	
                if(l1.t != 0)
	    		{	
                        xa += (ymax - ya) / m ;
                        ya = ymax ;
                }
			    else if(l1.b != 0)
                {	
                        xa += (ymin - ya) / m ; 
				        ya = ymin ;
			    }
			    else if(l1.l != 0)
	    		{	
                        ya += (xmin - xa) * m ;
				        xa = xmin ;
			    }
			    else if(l1.r != 0)
			    {	
                        ya += (xmax - xa) * m ;
				        xa = xmax ;
			    }
			    if(l2.t != 0)
			    {	
                        xb += (ymax - yb) / m ;
				        yb = ymax ;
			    }
			    else if(l2.b != 0)
	    		{	
                        xb += (ymin - yb) / m ; 
				        yb = ymin ;
			    }
			    else if(l2.l != 0)
		        {	
                        yb += (xmin - xb) * m ;
				        xb = xmin ;
			    }
			    else if(l2.r != 0)
			    {	
                        yb += (xmax - xb) * m ;
				        xb = xmax ;
			    }
            }
            if(xa < xmin)
                    l1.l = 1 ;
            else
                    l1.l = 0 ;
            if(xa > xmax)
                    l1.r = 1 ;
            else
                    l1.r = 0 ;
            if(ya < ymin)
                    l1.b = 1 ;
            else
                    l1.b = 0 ;
            if(ya > ymax)
                    l1.t = 1 ;
            else
                    l1.t = 0 ;
            if(xb < xmin)
                    l1.l = 1 ;
            else
                    l1.l = 0 ;
            if(xb > xmax)
                    l1.r = 1 ;
            else
                    l1.r = 0 ;
            if(yb < ymin)
                    l1.b = 1 ;
            else
                    l1.b = 0 ;
            if(yb > ymax)
                    l1.t = 1 ;
            else
                    l1.t = 0 ;
            l4.t = l1.t + l2.t ;
            l4.b = l1.b + l2.b ;
            l4.r = l1.r + l2.r ;
            l4.l = l1.l + l2.l ;
        }
        line(xa , ya , xb , yb) ;
        getch() ;
        closegraph() ;
}
