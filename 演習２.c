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
    
    printf("Input a number: \n");
    scanf("%d", &num);

    isZeroPlusMinus(num);
    isOdd(num);
    isPrime(num);
    return 0;
}

void isZeroPlusMinus(int num) {
    char result[10];

    if (num == 0) {
        printf("ZERO\n");
    } else if (num > 0) {
        printf("正の整数\n");
    } else {
        printf("負の整数\n");
    }
}

void isOdd(int num) {
    if (num == 0) {
        printf("----------\n");
    } else if (num % 2 == 0) {
        printf("偶数\n");
    } else {
        printf("奇数\n");
    }

}

void isPrime(int num) {
    int i;
    char result[20];
    strcpy(result, "素数");

    if(num == 0 || num == 1){
        strcpy(result, "素数じゃない");
    }else{
        for(i = 2; i < abs(num); i++){
        
            if(num%i == 0){
                strcpy(result, "素数じゃない");
                i = abs(num);
            }
        }
    }
    
    
    puts(result);
}