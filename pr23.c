#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int num,count= 0;
    int sum= 0;
    while(count<10)
    {
        printf("Enter number %d:",count+1);
        scanf("%d",&num);
        sum+= num;
        count++;

    }
    int average= sum/10;
    printf("Sum is : %d\n",sum);
    printf("Average is: %d\n", average);
    return 0;
}