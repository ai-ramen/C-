// int のローカル変数のアドレスを渡し、その中身を倍して値を返す関数を作れ。
// 関数は return で返さないこと、型は void(int*);

#include <stdio.h>

void returnDouble(int *num);

int main() {
    int num;
    num = 1;
    
    printf("before : %d\n", num);
    returnDouble(&num);
    printf("after : %d", num);
    
    return 0;
}

void returnDouble(int *num){
    (*num) = (*num)*2;
}