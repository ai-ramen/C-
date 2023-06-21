#include "func.c"
#include <stdio.h>

int main(){
    int choice;

    printf("select a number \n1. Dog \n2. Cat \n3. Cow \n");
    scanf("%d", &choice);

    func(choice);

    return 0;
}
