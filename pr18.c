#include<stdio.h>
int fact(int n);
int main(){
    printf("EKTA IT-1 47\n");
    int n;
    printf("Enter the value of n");
    scanf("%d",&n);
    printf("Factorial of %d is %d,n fact(n)");
    return 0;
}
int fact(int n){
    if (n==0){
        return 1;
    }
    int factN1= fact(n-1);
    int factN= factN1*n;
    return factN;
    
}