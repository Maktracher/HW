#include <stdio.h>
#include <stdio.h>

// str

typedef struct {
	int* arr;
	int size;

}Mnoz;

void add(Mnoz* mnoz, int num) {
	Mnoz mn;
	mn.size = mnoz->size + 1;
	mn.arr = (int*)malloc(mn.size * sizeof(int));
	for (size_t i = 0; i < mnoz->size; i++)
	{
		mn.arr[i] = mnoz->arr[i];

	}
	mn.arr[mn.size - 1] = num;

	free(mnoz->arr);

	mnoz->arr = mn.arr;
	
	mnoz->size = mn.size;
}

int main(){

	
	
}