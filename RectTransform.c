#include<stdio.h>
#include<graphics.h>
#include<math.h>
int xa , ya , xb , yb ;
void linerect(int x1 , int y1 , int x2 , int y2)
{
        setcolor(BLUE) ;
        line(x1 , y1 , x1 , y2) ;
        line(x2 , y1 , x2 , y2) ;
        line(x1 , y1 , x2 , y1) ;
        line(x1 , y2 , x2 , y2) ;
}
void translate(int tx , int ty)
{
        int x1 , y1 , x2 , y2 ;
        x1 = xa + tx ;
        y1 = ya + ty ;
        x2 = xb + tx ;
        y2 = yb + ty ; 
        linerect(x1 , y1 , x2 , y2) ;
}
void rotate(float ang , int xr , int yr)
{
        float x1 , y1 , x2 , y2 ;
        x1 = xr + (xa - xr) * cos(-ang) - (ya - yr) * sin(-ang) ;
        y1 = yr - (ya - yr) * cos(-ang) + (xa - xr) * sin(-ang) ;
        x2 = xr + (xb - xr) * cos(-ang) - (yb - yr) * sin(-ang) ;
        y2 = yr - (yb - yr) * cos(-ang) + (xb - xr) * sin(-ang) ;
        linerect(round(x1) , round(y1) , round(x2) , round(y2)) ;
}
void scale(float sx , float sy , int xr , int yr)
{
        float x1 , y1 , x2 , y2 ;
        x1 = xr + sx * (xa - xr) ;
        y1 = yr + sy * (ya - yr) ;
        x2 = xr + sx * (xb - xr) ;
        y2 = yr + sy * (yb - yr) ;
        linerect(round(x1) , round(y1) , round(x2) , round(y2)) ;
}
void shear(float shx , float shy)
{
        float x1 , y1 , x2 , y2 ;
        x1 = xa + ya * shx ;
        y1 = ya + xa * shy ;
        x2 = xb + ya * shx ;
        y2 = yb + xa * shy ;
        setcolor(BLUE) ;
        circle(500 , 10 , 5) ;
        floodfill(500 , 10 , BLUE) ;
        outtextxy(510 , 10 , "X Shear") ;
        line(xa , yb , xb , yb) ;
        line(xa , yb , x1 , ya) ;
        line(xb , yb , x2 , ya) ;
        line(x1 , ya , x2 , ya) ;
        setcolor(RED) ;
        circle(500 , 30 , 5) ;
        floodfill(500 , 30 , RED) ;
        outtextxy(510 , 30 , "Y Shear") ;
        line(xa , ya , xa , yb) ;
        line(xa , ya , xb , y1) ;
        line(xa , yb , xb , y2) ;
        line(xb , y1 , xb , y2) ;
}
void main()
{
        int ch , tx , ty , gd = DETECT , gm , x1 , y1 , x2 , y2 , xr , yr ;
        float ang , sx , sy , shx , shy ;
        printf("\nEnter the coordinates of the rectangle : ") ;
        scanf("%d%d%d%d" , &xa , &ya , &xb , &yb) ;
        x1 = xa ;
        y1 = ya ;
        x2 = xb ;
        y2 = yb ;
        do
        {
                printf("\n MENU\n1. Translation\n2. Rotation\n3. Scaling\n4. Shear\n5. Exit\nEnter your choice : ") ;
                scanf("%d" , &ch) ;
                if(ch == 1)
                {
                        printf("\nEnter tx and ty : ") ;
                        scanf("%d%d" , &tx , &ty) ;
                        initgraph(&gd , &gm , "") ;
                        setcolor(GREEN) ;
                        line(x1 , y1 , x1 , y2) ;
                        line(x2 , y1 , x2 , y2) ;
                        line(x1 , y1 , x2 , y1) ;
                        line(x1 , y2 , x2 , y2) ;
                        translate(tx , ty) ;
                }
                else if(ch == 2)
                {
                        printf("\nEnter the angle : ") ;
                        scanf("%f" , &ang) ;
                        printf("\nEnter the rotating point : ") ;
                        scanf("%d%d" , &xr , &yr) ;
                        float theta ;
                        theta = ang * 3.14 / 180 ;
                        initgraph(&gd , &gm , "") ;
                        setcolor(GREEN) ;
                        line(x1 , y1 , x1 , y2) ;
                        line(x2 , y1 , x2 , y2) ;
                        line(x1 , y1 , x2 , y1) ;
                        line(x1 , y2 , x2 , y2) ;
                        rotate(theta , xr , yr) ;
                }
                else if(ch == 3)
                {
                        printf("\nEnter sx and sy : ") ;
                        scanf("%f%f" , &sx , &sy) ;
                        printf("\nEnter the fixed point : ") ;
                        scanf("%d%d" , &xr , &yr) ;
                        initgraph(&gd , &gm , "") ;
                        setcolor(GREEN) ;
                        line(x1 , y1 , x1 , y2) ;
                        line(x2 , y1 , x2 , y2) ;
                        line(x1 , y1 , x2 , y1) ;
                        line(x1 , y2 , x2 , y2) ;
                        scale(sx , sy , xr , yr) ;
                }
                else if(ch == 4)
                {
                        printf("\nEnter shx and shy : ") ;
                        scanf("%f%f" , &shx , &shy) ;
                        initgraph(&gd , &gm , "") ;
                        setcolor(GREEN) ;
                        line(x1 , y1 , x1 , y2) ;
                        line(x2 , y1 , x2 , y2) ;
                        line(x1 , y1 , x2 , y1) ;
                        line(x1 , y2 , x2 , y2) ;
                        shear(shx , shy) ;
                }
                if((ch >= 1) && (ch <= 4))
                {
                        getch() ;
                        closegraph() ;
                }
        }while(ch != 5) ;
}
