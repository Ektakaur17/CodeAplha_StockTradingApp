#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int a,b,c;
    printf("Enter a,b,c\n");
    scanf("%d%d%d,&a,&b,&c");
    if(a>b&& a>c){
        printf("%d is largest no:",a);
    }
    else if (b>a && b>c){
        printf("%d is largest no",b);
    }
else if(c>a && c>b){
    printf("%d is largest no.",c);
}
    else{
        printf("%d%d%d are equal",a,b,c);

    }
    return 0;
}

