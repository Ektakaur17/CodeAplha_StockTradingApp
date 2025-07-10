#include<stdio.h>
int main()
{
    int length, breadth;
    printf("EKTA IT-1 47\n");

    printf("Enter length of rectangle:");
    scanf("%d", &length);

    printf("Enter breadth of rectangle:");
    scanf("%d",&breadth);

    if(length<=0 || breadth<=0)
    {
        printf("Error: length or breadth cannot be negative or zero.\n");
        return 1;
    }
    int area= length*breadth;
    printf("Area of rectangle is :%d\n", area);

    int perimeter= 2*(length+breadth);
    printf("Perimeter of rectangle is %d\n",perimeter);
    return 0;
}