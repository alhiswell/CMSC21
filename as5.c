#include<stdio.h>
int main(){
   int i,days;
   int first;

   printf("Enter number of days in month:\n");
   scanf("%d",&days);
   printf("Enter the starting day of the week (1=Sun, 7=Sat):\n");
   scanf("%d",&first);

   for(i=1;i<first;i++)
      printf("   ");
   
   if(days>31 || days<=0 || days<28){
    printf("Error! The number of days you have entered is invalid. Please put a number from 27-31");}
    else{
         for(i=1;i<=days;i++){
            printf("%3d",i);
            if((first+i-1)%7==0)
            printf("\n");
   }
    }

   return 0;

}