#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int n, sum=0;
    do
    {
        printf("Enter a number with 3 digit or more:");
        scanf("%d",&n);
        if(n<100)
        {
            printf("Error : Number must be three digits or more./n");

        }
    } while (n<100);
    int originalnum= n;
    while(n>0)
    {
        int digit= n%10;
        sum+= digit;
        n/= 10;
    }
    printf("Sum of digits %d is : %d", originalnum, sum);
    return 0;
}