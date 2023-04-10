#include <stdio.h>
int main(void)
{
    int i;

    i = 1;
/*
    while (i < 10) {
        printf("%d ", i);
        i *= 2;
    
    } 
   
     for (; i < 10;) {
        printf("%d ", i);
        i *= 2;
    }
    
*/  do {
        printf("%d ", i);
        i *= 2;
    }
    while (i < 10);


 return 0;
}