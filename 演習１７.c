// スレッドを生成し、渡した変数を+1して、それを確認してから(メインスレッド側で確認してから)プログラムを終了させろ。

// 目的  

// スレッド、排他制御の理解。

#include <stdio.h>
#include "pthread.h"

void *AddOne(void *num);

int main(void) {
    pthread_t thread;
    int num = 1;

    printf("before : %d\n", num);
    // // Create the thread, check if it's successful and pass the address of the counter variable
    if (pthread_create(&thread, NULL, AddOne, (void*)&num) != 0) {
        printf("スレッド生成失敗\n");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL) != 0) {
        printf("スレッド終了失敗\n");
        return 1;
    }

    printf("after : %d\n", num);
    return 0;
}

void *AddOne(void *num){
    int* newNum = (int*)num;  // Convert the void* back to int*
    (*newNum)++;

    return NULL;

}