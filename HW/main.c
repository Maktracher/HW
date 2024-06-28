#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable:4996)

typedef struct {
    int* arr;
    int size;
    int capacity;
} Mnoz;

void initMnoz(Mnoz* mnoz, int capacity) {
    mnoz->size = 0;
    mnoz->capacity = capacity;
    mnoz->arr = (int*)malloc(capacity * sizeof(int));
    if (mnoz->arr == NULL) {
        
        exit(1);
    }
}

void freeMnoz(Mnoz* mnoz) {
    if (mnoz->arr != NULL) {
        free(mnoz->arr);
    }
    mnoz->arr = NULL;
    mnoz->size = 0;
    mnoz->capacity = 0;
}

void add(Mnoz* mnoz, int num) {
    if (mnoz->size >= mnoz->capacity) {
        mnoz->capacity = mnoz->capacity == 0 ? 1 : mnoz->capacity * 2;
        mnoz->arr = (int*)realloc(mnoz->arr, mnoz->capacity * sizeof(int));
        if (mnoz->arr == NULL) {
            
            exit(1);
        }
    }
    mnoz->arr[mnoz->size++] = num;
}

//Pridáme počítanie porovnaní do funkcií contains 
// a intersection a vykreslíme graf, ktorý porovná počet porovnaní s veľkosťou množín.

bool contains(int* arr, int size, int num, int* comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == num) return true;
    }
    return false;
}

Mnoz* intersection(Mnoz* mn1, Mnoz* mn2, int* comparisons) {
    Mnoz* result = (Mnoz*)malloc(sizeof(Mnoz));
    if (result == NULL) {
        
        exit(1);
    }
    initMnoz(result, mn1->size < mn2->size ? mn1->size : mn2->size);
    for (int i = 0; i < mn1->size; i++) {
        if (contains(mn2->arr, mn2->size, mn1->arr[i], comparisons) && !contains(result->arr, result->size, mn1->arr[i], comparisons)) {
            add(result, mn1->arr[i]);
        }
    }
    return result;
}

Mnoz* unionMnoz(Mnoz* mn1, Mnoz* mn2, int* comparisons) {
    Mnoz* result = (Mnoz*)malloc(sizeof(Mnoz));
    if (result == NULL) {
        
        exit(1);
    }
    initMnoz(result, mn1->size + mn2->size);
    for (int i = 0; i < mn1->size; i++) {
        if (!contains(result->arr, result->size, mn1->arr[i], comparisons)) {
            add(result, mn1->arr[i]);
        }
    }
    for (int i = 0; i < mn2->size; i++) {
        if (!contains(result->arr, result->size, mn2->arr[i], comparisons)) {
            add(result, mn2->arr[i]);
        }
    }
    return result;
}

void printMnoz(Mnoz* mn) {
    for (int i = 0; i < mn->size; i++) {
        printf("%d ", mn->arr[i]);
    }
    printf("\n");
}

void suma(Mnoz* sm1, Mnoz* sm2) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < sm1->size; i++) {
        sum1 += sm1->arr[i];
    }
    for (int i = 0; i < sm2->size; i++) {
        sum2 += sm2->arr[i];
    }
    printf("Sum of both sets: %d\n", sum1 + sum2);
}



int main() {
    Mnoz m1, m2;
    initMnoz(&m1, 10);
    initMnoz(&m2, 10);

    for (int i = 0; i < 10; i++) {
        add(&m1, rand() % 100);
        add(&m2, rand() % 100);
    }
    printMnoz(&m1);
    printMnoz(&m2);

    int comparisons = 0;
    Mnoz* inter = intersection(&m1, &m2, &comparisons);
    printMnoz(inter);
    printf("Comparisons for intersection: %d\n", comparisons);

    comparisons = 0;
    Mnoz* uni = unionMnoz(&m1, &m2, &comparisons);
    printMnoz(uni);
    printf("Comparisons for union: %d\n", comparisons);

    suma(&m1, &m2);

    freeMnoz(&m1);
    freeMnoz(&m2);
    freeMnoz(inter);
    freeMnoz(uni);
    free(inter);
    free(uni);

    return 0;
}
