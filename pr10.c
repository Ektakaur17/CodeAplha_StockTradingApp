#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int num;
    printf("Enter number");
    scanf("%d",&num);
    if (num<0){
        printf("%d is negative no.", num);
    }
    if (num>0){
        printf("%d is positive number\n",num);
    }
    if (num==0){
        printf("5d is zero", num);
    }
    return 0;
}