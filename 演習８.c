// 演習２をジャンプテーブルにして実装する。
// 関数の中は printf の出力。

// 目的  

// 関数のアドレスとそのアドレスを使った関数の呼び出し、条件文をテーブル化することを理解する。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintPos();
void PrintNeg();
void PrintOdd();
void PrintOEven();
void IsPrime(int num);

int main() {
    int num = 6;

    void (*jumpTablePosNeg[])() = {&PrintNeg, &PrintPos};
    void (*jumpTableOddEven[])() = {&PrintOdd, &PrintOEven};

    if(num == 0){
        puts("ZERO");
        puts("----------");
    }else{
        (*jumpTablePosNeg[(num / abs(num)) == 1])();
        (*jumpTableOddEven[(num % 2) == 0])();
        IsPrime(num);
    }
    
    return 0;
}

void PrintPos(){
    puts("正の整数");
}


void PrintNeg(){
    puts("負の整数");
}


void PrintOdd(){
    puts("奇数");
}

void PrintOEven(){
    puts("偶数");
}

void IsPrime(int num){
    int i, flag = 0;
    
    for(i = 2; i < abs(num); i++){
        if(num%i == 0){
            flag = 1;
        }
    }

    flag == 0 ? puts("素数"):puts("素数じゃない");
}