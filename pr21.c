#include<stdio.h>
int fib(int n);
int main(){
    printf("EKTA IT-1 47\n");
    int n;
    do{
        printf("Enter number:");
        scanf("%d",&n);
        if(n<=0){
            printf("Error: Number cannot be zero or negative.\n");

        }
    } while(n<=0);
    for(int i=0; i<=n; i++){
        printf("%d\t",fib(i));

    }
    return 0;
    }
    int fib(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int fibN1= fib(n-1);
        int fibN2= fib(n-2);
        int fibN= fibN1+fibN2;
        return fibN;
    }
