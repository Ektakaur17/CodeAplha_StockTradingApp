#include <stdio.h>
int main() 
     {
        printf("EKTA IT-1 47\n");
        float principal,rate,time;
        printf("enter the principal amount :");
        scanf("%f",&principal);

        printf("Enter the interest rate");
        scanf("%f",&rate);

        printf("Enter the time period(in years)");
        scanf("%f",&time);
        if (principal<=0 || rate<=0 || time<=0)
{
    printf("Error: Principal,rate or time cannot be zero\n");
    return 1;

}
float interest = (principal*rate*time)/100;

printf("simple interest is : %f",interest);
        return 0;
    }