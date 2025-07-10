#include<stdio.h>
#include<conio.h>
void main()
{

    int n;
    float sum =0, avg, num;
    printf("Enter no. of terms:\n");
    scanf("%d", &n);
    printf("Enter numbers: ");
    for (int i= 1; i<=n; i++){
        printf("\n%d input value :", i);
        scanf("%f",&num);
        sum=sum+num;
    }
    printf("Sum of given numbers is :%f\n",sum);
    avg= sum/n;
    printf("Avg of numbers is: %f\n", sum);
    avg = sum/n;
    printf("Avg of numbers is :%f\n", avg);
    printf("\n Created by EKTA IT-1");
    getch();
}