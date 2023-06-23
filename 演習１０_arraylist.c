// 下記表を構造体と配列を使って、名前順と成績順に出力せよ（データは最初から入力済みとする、同じ点数の場合は名前順）
// 名前:点数
// sara:88
// gintonic:12
// aida:44
// yankoro:35
// kumazaki:44
// onizuka:93

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    char name[SIZE];
    int score;
} Studtype;

typedef struct {
    Studtype Stud[SIZE];
    int count;
} StudList;

void InitializeList(StudList *List);
void InsertLast(StudList *List, char name[SIZE], int score);
void Swap(Studtype *a, Studtype *b);
void PrintSortedByName(StudList List);
void PrintSortedByScore(StudList List);
int CompareByName(const void *a, const void *b);
void PrintSortedByNameWithQsort(StudList List);
void PrintList(StudList List);

int main() {
    StudList List;

    InitializeList(&List);

    InsertLast(&List, "sara", 88);
    InsertLast(&List, "gintonic", 12);
    InsertLast(&List, "aida", 44);
    InsertLast(&List, "yankoro", 35);
    InsertLast(&List, "kumazaki", 44);
    InsertLast(&List, "onizuka", 93);

    puts("Sorted by name:");
    PrintSortedByName(List);

    puts("\nSorted by score:");
    PrintSortedByScore(List);

    puts("\nSorted by name with qsort:");
    PrintSortedByNameWithQsort(List);

    return 0;
}

void InitializeList(StudList *List) {
    List->count = 0;
}

void InsertLast(StudList *List, char name[SIZE], int score) {
    if (List->count < SIZE - 1) {
        List->Stud[List->count].score = score;
        strcpy(List->Stud[List->count].name, name);
        List->count++;
    }
}

void Swap(Studtype *a, Studtype *b) {
    Studtype temp = *a;
    *a = *b;
    *b = temp;
}

void PrintSortedByName(StudList List) {
    int i, j;

    for (i = 0; i < List.count - 1; i++) {
        for (j = 0; j < List.count - 1 - i; j++) {
            if (strcmp(List.Stud[j].name, List.Stud[j + 1].name) > 0) {
                Swap(&List.Stud[j], &List.Stud[j + 1]);
            }
        }
    }

    PrintList(List);
}

void PrintSortedByScore(StudList List) {
    int i, j;

    for (i = 0; i < List.count - 1; i++) {
        for (j = 0; j < List.count - 1 - i; j++) {
            if (List.Stud[j].score == List.Stud[j + 1].score) {
                if (strcmp(List.Stud[j].name, List.Stud[j + 1].name) > 0) {
                    Swap(&List.Stud[j], &List.Stud[j + 1]);
                }
            } else if (List.Stud[j].score > List.Stud[j + 1].score) {
                Swap(&List.Stud[j], &List.Stud[j + 1]);
            }
        }
    }

    PrintList(List);
}

int CompareByName(const void *a, const void *b) {
    Studtype *studA = (Studtype *)a;
    Studtype *studB = (Studtype *)b;
    return strcmp(studA->name, studB->name);
}

void PrintSortedByNameWithQsort(StudList List) {
    qsort(List.Stud, List.count, sizeof(Studtype), CompareByName);
    PrintList(List);
}

void PrintList(StudList List) {
    int i;

    for (i = 0; i < List.count; i++) {
        printf("%s:%d\n", List.Stud[i].name, List.Stud[i].score);
    }
}
