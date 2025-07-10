#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    int sub1,sub2,sub3,sub4,sub5;
    printf("Enter marks of 5 subjects:");
    scanf("%d%d%d%d%d,sub1,sub2,sub3,sub4,sub5");
    int total= (sub1+sub2+sub3+sub4+sub5);
    int average= total/5;
    if (average=>90 && average =<100){
        printf("A");}
        else ifn(average >=80 && average <90){
            printf("B");}
            else if (average>=60&& average <80){
                printf("C");
            }
            else if (average>=30 && average<60){
printf("D");}
else if (average >=0 && average <30){
    printf("fail");}
    else{
        printf("Not valid marks");}
return 0;}
