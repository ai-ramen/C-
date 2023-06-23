// int のローカル変数のアドレスを渡し、その中身を倍して値を返す関数を作れ。
// 関数は return で返さないこと、型は void(int*);

#include <stdio.h>

void ReturnDouble(int *num);

int main() {
    int num = 4;
    
    printf("before : %d\n", num);
    ReturnDouble(&num);
    printf("after : %d", num);
    
    return 0;
}

void ReturnDouble(int *num){
    (*num) = (*num) * 2;
}