// 整数入力後その整数を判別するプログラムを作成しなさい。

// 判別対象：
// 判別1、ZERO/正の整数/負の整数
// 判別2、奇数/偶数　【0の時は、「----------」を表示】
// 判別3、素数


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void isZeroPlusMinus(int num);
void isOdd(int num);
void isPrime(int num);

int main() {
    int num;
    
    printf("Type a number: \n");
    scanf("%d", &num);

    isZeroPlusMinus(num);
    isOdd(num);
    isPrime(num);
    return 0;
}

void isZeroPlusMinus(int num) {
    char result[10];

    if (num < 0) {
        strcpy(result, "Negative");
    } else if (num > 0) {
        strcpy(result, "Positive");
    } else {
        strcpy(result, "Zero");
    }

    puts(result);
}

void isOdd(int num) {
    char result[10];

    if (num == 0) {
        strcpy(result, "----------");
    } else if (num %2 == 0) {
        strcpy(result, "Even");
    } else {
        strcpy(result, "Odd");
    }

    puts(result);
}

void isPrime(int num) {
    char result[10];
    strcpy(result, "Prime");
    int i;
    
    if(num == 0 || num == 1){
        strcpy(result, "Not Prime");
    }else{
        for(i = 2; i < num; i++){
        
        if(num%i == 0){
            strcpy(result, "Not Prime");
            i = num;
        }
    }
    }
    
    

    puts(result);
}