#include <stdio.h>
int main() {
   int num1, num2, num3, sum;
      
   printf("Type a number1: \n");
   scanf("%d", &num1);

   printf("Type a number2: \n");
   scanf("%d", &num2);

   printf("Type a number3: \n");
   scanf("%d", &num3);

   printf("You numbers are %d, %d, %d\n", num1, num2, num3);
   
   sum = num1 + num2 + num3;

   printf("Sum of the numbers is %d", sum);
   return 0;
}