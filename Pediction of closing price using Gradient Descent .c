#include<stdio.h>
#include<math.h>

void main()
{
    double a[][] = new double[22][2];
    double res[22][2]={};
    double m=0,b=0;
    double mx=0,bx=0;
    double alpha=0.001;
    int i,j;
    for (i=0;i<100000;i++)
    {
        mx=0;bx=0;
        for(j=0;j<22;j++)
        {
            res[j][1]=(m*a[j][0])+b;
            res[j][0]=i+1;
        }
        for(j=0;j<22;j++)
        {
            mx+=-2*(a[j][1]-res[j][1])*(j+1);
            bx+=-2*(a[j][1]-res[j][1]);
        }
        mx=mx/22;
        bx=bx/22;
        m-=alpha*mx;
        b-=alpha*bx;
    }
    printf("%lf %lf\n",m,b);
    for(i=0;i<22;i++)
        printf("%lf %lf\n",a[i][1],((m*(i+1))+b));
    printf(“The value of m is %lf”, m);
    printf(“The value of b is %lf”, b);
}