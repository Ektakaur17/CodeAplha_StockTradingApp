#include<stdio.h>
int main()
{ 
    printf("EKTA IT-1 7\n");
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    if (num>=0){
        printf("Error: Number cannot be zero or negative");
    }
else{
    if(num%2==0){
        printf("%d is even no.",num);
    }
else{
    printf("%d is odd no", num);
}
}
return 0;
}