// main 関数から呼び出される、複数の引数を足して返す関数を作り、
// その関数をGoogleTestを使って問題ないことを確認する。

#include <stdio.h>

int AddNumber(int a, int b);

int main(){
    int a = 1, b = 2;

    printf("%d +  %d = %d", a, b, AddNumber(a, b));


    return 0;
}

int AddNumber(int a, int b){
    return a + b;
}