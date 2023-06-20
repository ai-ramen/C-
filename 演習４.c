// 数値を繰り返して入力し、0が入力されたら入力を止め、平均値を表示するプログラムを作成しなさい。

#include <stdio.h>

int main() {
    int num, sum, count;
    sum = count = 0;
    
    do{
        printf("Input a number: \n");
        scanf("%d", &num);
        sum += num; 
        count ++;
    }while(num != 0);
    
    printf("average is %d", sum/(count-1));
    
    return 0;
}
