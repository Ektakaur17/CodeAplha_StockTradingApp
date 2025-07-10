#include<stdio.h>
#include<math.h>
int main(){
    printf("EKTA IT-1 47\n");
    double base, result=1.0;
    int exponent;
    printf("Enter the base:");
    scanf("%lf",&base);
    printf("Enter the exponent:");
    scanf("%d",&exponent);
    if (exponent==0){
        printf("Result :%.2 lf\n",result);

    }
    else if(exponent<0)
    {
        printf("Error: exponent must be a non negative integer.\n");

    }
    else{
        for(int i=1; i<= exponent; ++i)
        {
            result*= base;
        
        }
        printf("Result:%.2lf\n",result);
    }
    return 0;
}