#include<stdio.h>
int main(){
   int a[20],size,pos;
   printf("Enter the size of array:");
   scanf("%d",&size);
   printf("Enter the elments in array");
   for (int i=0; i<size; i++){
    scanf("%d",&a[i]);
   }
   printf("Enter position you want to delete:");
   scanf("%d",&pos);
   if(pos<0 || pos>size){
    printf("Invalid Position");
   }
   else{
    for(int i=pos-1;i<size-1;i++){
        a[i]=a[i+1];
    }
    size--;
    printf("Elements after selecting the array:\n");
    for(int i=0; i<size; i++){
        printf("%d\n",a[i]);
    }
   }
   printf("Created by EKTA IT-1");
   return 0;
}