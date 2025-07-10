#include<stdio.h>
int main()
{
    printf("EKTA IT-1 47\n");
    int num;
    printf("Enter a three digit number");
scanf("%d",&num);
int digit1 = num%10;
int digit2= (num%100)/10;
int digit3 = num/100;
int reverse = digit1*100+digit2*10+digit3;
printf("Reverse no is %d", reverse);
return 0;
}