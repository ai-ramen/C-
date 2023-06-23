#include "../Downloads/googletest/googletest/include/gtest/gtest.h"


#include <stdio.h>

int AddNumbers(int a, int b);

// テスト用の関数として定義
int Test_AddNumbers() {
    // テストケース1
    if (AddNumbers(2, 3) == 5) {
        printf("Test case 1 passed.\n");
    } else {
        printf("Test case 1 failed.\n");
    }
    
    // テストケース2
    if (AddNumbers(-1, 5) == 4) {
        printf("Test case 2 passed.\n");
    } else {
        printf("Test case 2 failed.\n");
    }
    
    // テストケース3
    if (AddNumbers(0, 0) == 0) {
        printf("Test case 3 passed.\n");
    } else {
        printf("Test case 3 failed.\n");
    }
}

int main() {
    // テスト実行
    Test_AddNumbers();
    
    return 0;
}

int AddNumbers(int a, int b) {
    return a + b;
}
