// 円の半径を入力し、円周の長さと面積を計算するプログラムを作れ。

#include <stdio.h>
#include <math.h>


int main() {
    float radius, length, area;
    
    printf("Input 半径: \n");
    scanf("%f", &radius);
    
    printf("半径 : %.2f\n", radius);
    printf("演習 : %.2f\n", 2 * M_PI * radius);
    printf("面積 : %.2f\n", M_PI * pow(radius, 2.0));
    
    return 0;
}
