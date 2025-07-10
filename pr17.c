#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    unsigned int decimalnum;
    printf("Enter a positive decimal number:");
    scanf("%u",&decimalnum);
    if(decimalnum==0){
        printf("Binary:0\n");
        printf("Octal:0\n");
return 0;}
    
    unsigned int binary=0;
    unsigned int binaryPlaceValue=1;
    unsigned int temp= decimalnum;
    while(temp>0){
        binary+=(temp%2)* binaryPlaceValue;
        temp/=2;
        binaryPlaceValue *=10;}
        printf("Binary:%u\n",binary);
        unsigned int octal=0;
        unsigned int octalplacevalue=1;
        temp= decimalnum;
        while(temp>0){
            octal+=(temp%8)*octalplacevalue;
            temp=8;
            octalplacevalue=10;}
            printf("Octal:%4\n",octal);
            return 0;
        }
    


