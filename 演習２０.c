// 上の式が成り立つように□に１から９までの数字を１個づつ入れなさい

#include <stdio.h>

void RearrangeArray(int arr[], int start, int end) {
    //check if loop is done. 
    if (start == end) {
        // 計算結果が1になるかをチェック
        float result = (float)arr[0] / (10 * arr[1] + arr[2]) +
                       (float)arr[3] / (10 * arr[4] + arr[5]) +
                       (float)arr[6] / (10 * arr[7] + arr[8]);
        if (result == 1) {
            printf("Numbers that satisfy the equation:\n");
            for (int i = 0; i <= end; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    } else {
        for (int i = start; i <= end; i++) {
            // 要素を交換. swap value. 
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            // 再帰的に全ての順列を生成. recursion
            RearrangeArray(arr, start + 1, end);

            // 要素を戻す. swap value
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    permute(arr, 0, n - 1);

    return 0;
}