#include "func.h"
#include <stdio.h>
#include <string.h>

//global varieble                       
char sound[3][10] = {"woof", "meow", "moo"};

void func(int choice){
    
    char sound[3][10] = {"わんわん", "にゃー", "もー"};
    printf("func.cのsound : %s\n", sound[(choice - 1)]);
}