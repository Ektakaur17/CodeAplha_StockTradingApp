#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    float a,b,x1,fa,fb,fx1,e=0.001;
    int i=0, i2;
    printf("Enter the initial guess:");
    scanf("%f %f", &a, &b);
    fa= cos(a);
    fb= cos(b);
    if (fa*fb>0){
        printf("\n guess again");
    } else{
        do{
            x1= (a+b)/2;
            fx1= cos(x1);
            if(fb*fx1<0){
                a= x1;}
                else{
                    b=x1;
                }           i++;
        }while(i<=12);
        printf("Enter number of iterations:");
        scanf("%d",&i2);
        while(fabs(b-a)>=e);
        
        printf("\n root is %f", x1);
        printf("\n value of function is %f", fx1);
        }
        return 0;
    }
