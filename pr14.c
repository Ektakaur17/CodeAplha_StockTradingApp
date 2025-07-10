#include<stdio.h>
int main(){
    printf("EKTA IT-1 47\n");
    char ch;
    printf("Enter a character:");
    scanf("%c", &ch);
    if(ch>='A'&& ch<='Z'){
        printf("%c is uppercase",ch);

    }
    else if(ch>='a'&& ch<='z'){
        printf("%c is lowercase",ch);

    }
    else if (ch>='0'& ch<='9'){
        printf("%c is digit",ch);

    }
    else{
        printf("%0 is special symbol", ch);

    }
    return 0;
} 