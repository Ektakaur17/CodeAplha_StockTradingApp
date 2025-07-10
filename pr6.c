//. Write a program to accept a three digit number and 
// find the sum of digits of the number without using loop.
#include<stdio.h>
int main()
{
    printf("EKTA IT-1 47\n");
    int number, digit1, digit2, digit3;

    printf("Enter a three digit number:");
    scanf("%d",&number);

    digit1= number/100;
    digit2= (number/10) % 10;
    digit3= number% 10;
    
    int sum= digit1+ digit2+ digit3;

    printf("Sum of digits: %d\n",sum);

    return 0;


}