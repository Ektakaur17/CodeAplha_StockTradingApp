//5. Write amenu driven program to convert fahrenheit temperature to centigrade 
// Or centigrade to fahrenheit temperature.
#include<stdio.h>
int main()
{
    printf("EKTA IT-1 47\n");
    int choice;
    float temp;
    printf("Enter 1- To convert faherenheit to celsius\n");
    printf("Enter 2- To convert celsius to faherenheit\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf(" Enter temperature in faherenheit:");
        scanf("%f",&temp);
        float celsiustemp = (temp-32)* 5/ 9;
        printf("Temperature in celsius is :%f", celsiustemp);

    }
if (choice == 2)
{
    printf("Enter temperature in celsius :");
    scanf("%f",&temp);
    float faherenheittemp = (temp* 1.8) + 32;
    printf("Temperature in celsius is:%f",faherenheittemp);
}
return 0;
}

