#include <stdio.h>
#include <graphics.h>
int ComputeOutCode(float x, float y, float xmax, float ymax, float xmin, float ymin)
{
         int code;
         code = 0;
         if (x <xmin)
                 code |= 1;
         else if (x >xmax)
                 code |= 2;
         if (y <ymin)
                 code |= 4;
         else if (y >ymax)
                 code |= 8;
         return code;

}
void clip(float x0, float y0, float x1, float y1, float xmax, float ymax, float xmin, float ymin)
{
         int outcode0 = ComputeOutCode(x0, y0, xmax, ymax, xmin, ymin), outcode1 =
                 ComputeOutCode(x1, y1, xmax, ymax, xmin, ymin), accept = 0;
         while (1)
         {
                  if (!(outcode0 | outcode1))
                  {
                           accept = 1;
                           break;

                  }
                  else if (outcode0 & outcode1)
                          break;
                  else
                  {
                           float x, y;
                           int outcodeOut = outcode0 ? outcode0 : outcode1;
                           if (outcodeOut& 8)
                           {
                                    x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                                    y = ymax;

                           }
                           else if (outcodeOut& 4)
                           {
                                    x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                                    y = ymin;

                           }
                           else if (outcodeOut& 2)
                           {
                                    y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                                    x = xmax;

                           }
                           else if (outcodeOut& 1)
                           {
                                    y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                                    x = xmin;

                           }
                           if (outcodeOut == outcode0)
                           {
                                    x0 = x;
                                    y0 = y;
                                    outcode0 = ComputeOutCode(x0, y0, xmax, ymax, xmin, ymin);

                           }
                           else
                           {
                                    x1 = x;
                                    y1 = y;
                                    outcode1 = ComputeOutCode(x1, y1, xmax, ymax, xmin, ymin);

                           }

                  }

         }
         if (accept)
         {
                  setcolor(WHITE);
                  line(x0, y0, x1, y1);

         }

}
void main()
{
         int gd=DETECT, gm=VGAMAX,i,n;
         float xmax,xmin,ymax,ymin,poly[15];
         printf("Enter top left corner coordinates: ");
         scanf("%f%f",&xmin,&ymin);
         printf("Enter bottom right corner coordinates: ");
         scanf("%f%f",&xmax,&ymax);
         printf("Enter the no of sides of the polygon: ");
         scanf("%d",&n);
         printf("Enter the coordinates of polygon: ");
         for(i=0;i<2*n;i++)
                 scanf("%f",&poly[i]);
         poly[2*n]=poly[0];
         poly[2*n+1]=poly[1];
         initgraph(&gd,&gm,NULL);
         for(i=0;i<n;i++)
         {
                  setcolor(RED);
                  line(poly[2*i],poly[2*i+1],poly[2*i+2],poly[2*i+3]);
                  clip(poly[2*i],poly[2*i+1],poly[2*i+2],poly[2*i+3],xmax,ymax,xmin,ymin);

         }
         rectangle(xmin, ymin, xmax, ymax);
         getch();
         closegraph();

}

