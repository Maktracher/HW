#include <stdio.h>
#include <stdlib.h>

// str

typedef struct {
	int* arr;
	int size;

}Mnoz;

void constract(Mnoz* mnoz, int size) {

	mnoz->size = size;
	mnoz->arr = (int*)malloc(mnoz->size * sizeof(int));

}

void add(Mnoz* mnoz, int num) {
	Mnoz mn;
	constract(&mn, mnoz->size + 1);
	for (size_t i = 0; i < mnoz->size; i++)
	{
		mn.arr[i] = mnoz->arr[i];

	}
	mn.arr[mn.size - 1] = num;
	free(mnoz->arr);
	mnoz->arr = mn.arr;
	mnoz->size = mn.size;
}


Mnoz per(Mnoz mn1, Mnoz mn2) {
	Mnoz result;
	constract(&result,0);
	for (size_t i = 0; i < mn1.size; i++)
	{
		for (size_t j = 0; j < mn2.size; j++)
		{
			if (mn1.arr[i] == mn2.arr[j]) {
				int find = 0;
				for (size_t l = 0; l < result.size; l++)
				{
					if (mn1.arr[i] == result.arr[l]) {
						find = 1;
					}
				}
				if (!find)
				{
					add(&result, mn1.arr[i]);
				}
			}
		}
	}

	return result;

}
 
void print(Mnoz mn) {

	for (size_t i = 0; i < mn.size; i++)
	{
		printf("%d ", mn.arr[i]);

	}
	printf("\n");
}


int main(){
	srand(time(0));
	Mnoz m1, m2;
	constract(&m1, 0);
	constract(&m2, 0);
	for (size_t i = 0; i < 10; i++)
	{
		add(&m1,rand() % 100);
	}
	for (size_t i = 0; i < 10; i++)
	{
		add(&m2, rand() % 100);
	}
	print(m1);
	print(m2);
	Mnoz n1 = per(m1, m2);
	print(n1);
}