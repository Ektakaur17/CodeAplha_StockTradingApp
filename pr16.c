#include<stdio.h>
int main() {
    printf("EKTA IT-1 47\n");
    printf("uppercase alphabets:\n");
    for (char ch='A'; ch<='Z'; ch++){
        printf("%c: %d\n",ch,ch);

    }
    printf("\n lowercase alphabets:\n");
    for(char ch='a'; ch<='z'; ch++){
        printf("%c:%d \n",ch,ch);

    }
    printf("\n digits:\n");
    for (char digit='0'; digit<='9'; digit++){
        printf("%c:%d\n",digit,digit);

    }
    return 0;
}