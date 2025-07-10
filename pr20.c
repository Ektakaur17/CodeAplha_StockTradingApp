#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int n;
    do{
        printf("enter number:");
        scanf("%d",&n);
        if(n<=0){
        printf("Error:value of n cannot be negative or zero\n");
        
    }
} while(n<=0);
printf("Prime numbers are :\n");
for (int i=2; i<=n; i++){
    for (int j=2; j<=i; j++){
        if(i==j){
            printf("%d\t",i);

        }
    else if(i%j==0){
        break;
    }
    }
}
return 0;
}
