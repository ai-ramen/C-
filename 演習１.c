#include <stdio.h>
int main() {
   int num1, num2, num3, sum;
      
   printf("Input a number1: \n");
   scanf("%d", &num1);

   printf("Input a number2: \n");
   scanf("%d", &num2);

   printf("Input a number3: \n");
   scanf("%d", &num3);

   printf("You numbers are %d, %d, %d\n", num1, num2, num3);
   
   sum = num1 + num2 + num3;

   printf("Sum : %d", sum);
   return 0;
}