#include<stdio.h>
int main()
{
    printf("EKTA IT-1 47\n");
    char ch;

    printf("Enter a character");
    scanf("%c", &ch);

    if (( ch>='A'&& ch<='Z')|| (ch>='a'&& ch<='z')) {
        // toogle case by flipping the 6th bit (32 in decimal)
        ch=ch^32;
        printf("Converted character :%c\n",ch);
   } 
   else{
        printf("Invalid input. Please enter an alphabet \n");

    }
    return 0;
}