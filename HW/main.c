#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} Mnoz;

void initMnoz(Mnoz* mnoz, int capacity) {
    mnoz->size = 0;
    mnoz->capacity = capacity;
    mnoz->arr = (int*)malloc(capacity * sizeof(int));
}

void freeMnoz(Mnoz* mnoz) {
    free(mnoz->arr);
    mnoz->arr = NULL;
    mnoz->size = 0;
    mnoz->capacity = 0;
}

void add(Mnoz* mnoz, int num) {
    if (mnoz->size >= mnoz->capacity) {
        mnoz->capacity = mnoz->capacity == 0 ? 1 : mnoz->capacity * 2;
        mnoz->arr = (int*)realloc(mnoz->arr, mnoz->capacity * sizeof(int));
    }
    mnoz->arr[mnoz->size++] = num;
}

bool contains(int* arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) return true;
    }
    return false;
}

Mnoz intersection(Mnoz mn1, Mnoz mn2) {
    Mnoz result;
    initMnoz(&result, mn1.size < mn2.size ? mn1.size : mn2.size);
    for (int i = 0; i < mn1.size; i++) {
        if (contains(mn2.arr, mn2.size, mn1.arr[i]) && !contains(result.arr, result.size, mn1.arr[i])) {
            add(&result, mn1.arr[i]);
        }
    }
    return result;
}

Mnoz unionMnoz(Mnoz mn1, Mnoz mn2) {
    Mnoz result;
    initMnoz(&result, mn1.size + mn2.size);
    for (int i = 0; i < mn1.size; i++) {
        if (!contains(result.arr, result.size, mn1.arr[i])) {
            add(&result, mn1.arr[i]);
        }
    }
    for (int i = 0; i < mn2.size; i++) {
        if (!contains(result.arr, result.size, mn2.arr[i])) {
            add(&result, mn2.arr[i]);
        }
    }
    return result;
}

void printMnoz(Mnoz mn) {
    for (int i = 0; i < mn.size; i++) {
        printf("%d ", mn.arr[i]);
    }
    printf("\n");
}

void suma(Mnoz sm1, Mnoz sm2) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < sm1.size; i++) {
        sum1 += sm1.arr[i];
    }
    for (int i = 0; i < sm2.size; i++) {
        sum2 += sm2.arr[i];
    }
    printf("Sum of both sets: %d\n", sum1 + sum2);
}

void sumElements(Mnoz sm1, Mnoz sm2) {
    if (sm1.size == sm2.size) {
        for (int i = 0; i < sm1.size; i++) {
            printf("%d ", sm1.arr[i] + sm2.arr[i]);
        }
        printf("\n");
    }
    else {
        printf("Sets are of different sizes\n");
    }
}

int main() {
    Mnoz m1, m2;
    initMnoz(&m1, 10);
    initMnoz(&m2, 10);

    for (int i = 0; i < 10; i++) {
        add(&m1, rand() % 100);
        add(&m2, rand() % 100);
    }

    printMnoz(m1);
    printMnoz(m2);

    Mnoz inter = intersection(m1, m2);
    printMnoz(inter);

    Mnoz uni = unionMnoz(m1, m2);
    printMnoz(uni);

    suma(m1, m2);
    sumElements(m1, m2);

    freeMnoz(&m1);
    freeMnoz(&m2);
    freeMnoz(&inter);
    freeMnoz(&uni);

    return 0;
}
