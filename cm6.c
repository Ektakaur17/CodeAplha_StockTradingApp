// TRAPEZOIDAL FORMULA 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x*x*x - 4*x -9
int main(){
    float a, b, integration, h, k, sum=0;
    int i,n;
    printf("Enter lower limit of integration : \n");
    scanf ("%f",&a);
    printf("Enter upper limit of integration : \n");
    scanf ("%f",&b);
    printf("Enter number of sub-intervals:\n");
    scanf("%f",&n);
    h= (b-a)/n;
    for (int i=1; i<=n; i++){
        k= a+(i*h);
        sum += f(k);
    }
    integration = (h/2)* (f(a)+ f(b) + (2*sum));
    printf("Required value of integration is : %f\n",integration);
    printf ("Created by EKTA IT-1\n");
    getch();
    return 0;

}