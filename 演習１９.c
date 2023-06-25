// ワーカースレッドを２つ作り、キーボード入力により片方だけが動作するプログラムを作れ、この時ビジーループは使用禁止とする。

#include <stdio.h>
#include <string.h>
#include <pthread.h>

// データ構造体
typedef struct {
    char input[100];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int ready;
} InputData;

void* Worker1(void* arg);
void* Worker2(void* arg);

int main() {
    pthread_t thread1, thread2;
    InputData data;

    // データ初期化
    data.ready = 0;
    pthread_mutex_init(&(data.mutex), NULL);
    pthread_cond_init(&(data.cond), NULL);
    
    // 入力スレッド生成
    if (pthread_create(&thread1, NULL, Worker1, &data) != 0) {
        printf("スレッドの生成に失敗しました\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, Worker2, &data) != 0) {
        printf("スレッドの生成に失敗しました\n");
        return 1;
    }

    // キーボード入力待ち
    printf("Enter input: ");
    fgets(data.input, sizeof(data.input), stdin);

    //mutex を使用してクリティカルセクション内でロックとアンロックを
    pthread_mutex_lock(&(data.mutex));
    data.ready = 1;
    pthread_mutex_unlock(&(data.mutex));

    pthread_cond_signal(&(data.cond));

    // Join thread1
    if (pthread_join(thread1, NULL) != 0) {
        printf("Failed to join thread.\n");
        return 1;
    }

    pthread_mutex_destroy(&(data.mutex));
    pthread_cond_destroy(&(data.cond));

    return 0;
}

void* Worker1(void* arg) {
    InputData* data = (InputData*)arg;
    
    pthread_mutex_lock(&(data->mutex));

    while (!(data->ready)) {
        pthread_cond_wait(&(data->cond), &(data->mutex));
    }

    pthread_mutex_unlock(&(data->mutex));

    printf("Worker 1 is running. Input: %s\n", data->input);

    return NULL;
}

void* Worker2(void* arg) {
    InputData* data = (InputData*)arg;
    
    pthread_mutex_lock(&(data->mutex));

    while (!(data->ready)) {
        pthread_cond_wait(&(data->cond), &(data->mutex));
    }

    pthread_mutex_unlock(&(data->mutex));

    printf("Worker 2 is running. Input: %s\n", data->input);

    return NULL;
}