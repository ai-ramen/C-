// ワーカースレッドでキーボードからの入力を監視し、コールバックでメインスレッドにそのデータを渡し表示しろ

// 目的  

// スレッド間でのデータの渡し方。

#include <stdio.h>
#include <string.h>
#include <pthread.h>

// pthread_cond_t：条件変数は、スレッド間の通信と調整のために使用される同期機構です。
// 条件変数は通常、ミューテックス（mutex）と組み合わせて使用され、
// スレッドが特定の条件が満たされるのを待ってから実行を継続する方法を提供します。
// スレッドは、望ましい条件が他のスレッドからのシグナルを受け取るまでブロックして待機することができます。

// pthread_cond_wait() pthread_cond_signal() : それぞれ条件変数上でのスレッドのブロックとアンブロックを行うために使用されます。
// **pthread_mutex_t：ミューテックスは、複数のスレッドが共有リソースへの排他的なアクセスを制御するための同期機構です。
// **pthread_mutex_init(): ミューテックスを初期化します。
// **pthread_mutex_lock(): ミューテックスをロックします。他のスレッドが既にロックしている場合、現在のスレッドはブロックされます。
// **pthread_mutex_unlock(): ミューテックスのロックを解除します。他のスレッドが待機中の場合、そのうちの1つがロックを獲得します。
// **pthread_mutex_destroy(): ミューテックスを破棄し、関連するリソースを解放します。

// データ構造体
typedef struct {
    char input[100];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int ready;
} InputData;

// 入力コールバック関数
void inputCallback(InputData* data);
// 入力監視スレッド
void* inputThread(void* arg);

int main() {
    InputData data;
    pthread_t thread;
    
    // データ初期化
    data.ready = 0;
    pthread_mutex_init(&data.mutex, NULL);
    pthread_cond_init(&data.cond, NULL);
    
    // 入力スレッド生成
    if (pthread_create(&thread, NULL, inputThread, &data) != 0) {
        printf("スレッドの生成に失敗しました\n");
        return 1;
    }
    
    // メインスレッドでデータの受け取り待ち
    
    pthread_mutex_lock(&data.mutex);
        
    // データが準備されるまで待機
    while (!data.ready) {
            pthread_cond_wait(&data.cond, &data.mutex);
    }

    // データを受け取り
    char input[100];
    strcpy(input, data.input);
        
    pthread_mutex_unlock(&data.mutex);
        
    // データ表示
    printf("メインスレッドでの入力データ: %s\n", input);
    
    pthread_mutex_destroy(&data.mutex);
    pthread_cond_destroy(&data.cond);
    
    return 0;
}

// 入力コールバック関数
void inputCallback(InputData* data) {
    // データ表示
    printf("入力データ: %s\n", data->input);
}

// 入力監視スレッド
void* inputThread(void* arg) {
    InputData* data = (InputData*)arg;
    
    char input[100];
        
    // 入力待ち
    printf("入力を待っています...\n");
    fgets(input, sizeof(input), stdin);
        
    // 入力データを保持 (lock data)
    pthread_mutex_lock(&data->mutex);
    strcpy(data->input, input);
    data->ready = 1;
    pthread_cond_signal(&data->cond);
    pthread_mutex_unlock(&data->mutex);
        
    // コールバック呼び出し
    inputCallback(data);
    
    
    return NULL;
}