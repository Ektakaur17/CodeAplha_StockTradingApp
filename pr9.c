#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int year;
    printf("Enter year:");
    scanf("%d",&year);
    if (year<=0) {
        printf("Error : year cannot be zero or negative");
    }
    else{
        if(year%4==0&& year%100!=0 || year%400==0){
            printf("%d is a leap year", year);
                    }
    else{
        printf("%d is not a leap year");
    }
    }
    return 0;

}