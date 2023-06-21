// 演習２をジャンプテーブルにして実装する。
// 関数の中は printf の出力。

// 目的  

// 関数のアドレスとそのアドレスを使った関数の呼び出し、条件文をテーブル化することを理解する。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printPos();
void printNeg();
void printOdd();
void printOEven();
void isPrime(int num);

int main() {
    int num;
    num = -5;

    void (*jumpTablePosNeg[])() = {&printNeg, &printPos};
    void (*jumpTableOddEven[])() = {&printOdd, &printOEven};

    if(num == 0){
        puts("ZERO");
        puts("----------");
    }else{
        (*jumpTablePosNeg[(num / abs(num)) == 1])();
        (*jumpTableOddEven[(num % 2) == 0])();
        isPrime(num);
    }
    

    return 0;
}

void printPos(){
    puts("正の整数");
}


void printNeg(){
    puts("負の整数");
}


void printOdd(){
    puts("奇数");
}

void printOEven(){
    puts("偶数");
}



void isPrime(int num) {
    int i, flag = 0;
    
    for(i = 2; i < abs(num); i++){
        
        if(num%i == 0){
            flag = 1;
        }
    }
    
    
    flag == 0 ? puts("素数"):puts("素数じゃない");


}