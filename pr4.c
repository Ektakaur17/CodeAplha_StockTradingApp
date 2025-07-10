//4. Write a program to accept the marks of five subjects and find the total and percentage.//
#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
     int subject1, subject2, subject3, subject4, subject5;

    printf("Enter marks for five subjects:");
    scanf("%d%d%d%d%d",&subject1, &subject2, &subject3, &subject4, &subject5);
    
    if(subject1<=0 || subject2<=0 || subject3<=0 || subject4<=0 || subject5<=0 ||
    subject1> 100 || subject2> 100 || subject3 > 100 || subject4> 100 || subject5> 100)

    {
        printf("Error: Marks cannot be negative, zero or greater than 100.\n");
        return 1;
    }
    int total = subject1+subject2+subject3+subject4+subject5;
    printf("Total marks:%d\n",total);
    float percentage = (total/500.0)*100;
    printf("Percentage:% .2f%%\n", percentage);
    return 0;
}