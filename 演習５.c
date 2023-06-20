// スタリスク三角形を作成するプログラムを作成しなさい。
// 条件：
// 最初に「何段？」と質問し、段数を指定すること。質問欄と三角形生成ゾーンの間に
// 「--------------------」と仕切りを入れること。

#include <stdio.h>

int main() {
    int layer, i, j, k;
    
    printf("何段？: \n");
    scanf("%d", &layer);
    
    printf("--------------------\n");
    
    for(i = 0; i < layer; i++){
        for(j = 0; j < layer - i - 1; j++){
            printf(" ");
        }
        for(k = 0; k < 2*(i+1)-1; k++){
            printf("*");    
        }
        
        printf("\n");
        }
        
    
    
    
    return 0;
}
