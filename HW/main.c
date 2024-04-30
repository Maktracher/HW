#include <stdio.h>
#include <stdlib.h>

int k = 0;
int l = 0;
// struct

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
		l++;
		for (size_t j = 0; j < mn2.size; j++)
		{
			l++;
			if (mn1.arr[i] == mn2.arr[j]) {
				int find = 0;
				l ++;

				for (size_t l = 0; l < result.size; l++)
				{
					if (mn1.arr[i] == result.arr[l]) {
						l++;
						find = 1;
					}
				}
				if (!find)
				{
					l++;
					add(&result, mn1.arr[i]);
				}
			}
		}
	}

	return result;

}

Mnoz ob(Mnoz mn1, Mnoz mn2) {
	Mnoz result;
	constract(&result, 0);
	for (size_t i = 0; i < mn1.size; i++)
	{
		k++;
		int find = 0;
		for (size_t l = 0; l < result.size; l++)
		{
			k++;
			if (mn1.arr[i] == result.arr[l]) {
				k++;
				find = 1;
				break;
			}
		}
		if (!find) {
			k++;
			add(&result, mn1.arr[i]);
		}
	}
	for (size_t j = 0; j < mn2.size; j++)
	{
		k++;
		int find = 0;
		for (size_t l = 0; l < result.size; l++)
		{
			if (mn2.arr[j] == result.arr[l]) {
				k++;
				find = 1;
				break;
			}
		}
		if (!find) {
			k++;
			add(&result, mn2.arr[j]);
		}
	}
	return result;
}



 
void print(Mnoz mn) {

	for (size_t i = 0; i < mn.size; i++)
	{
		k++;
		printf("%d ", mn.arr[i]);

	}
	printf("\n");
}

void sum(Mnoz sm1, Mnoz sm2) {
	if (sm1.size == sm2.size) {
		
		int sum=0;
			for (size_t j = 0; j < sm2.size; j++) {
				sum = sm2.arr[j] + sm1.arr[j];
				printf("%d ", sum);
				
			}
	}
	else
	{
		printf("ne");
		return;
	}
}


void suma(Mnoz sm1, Mnoz sm2) {
	
int sum1 = 0;
int sum2 = 0;
int sum = 0;

	for (size_t i = 0; i < sm1.size; i++)
	{
		
		sum1 += sm1.arr[i];
		
	}
	for (size_t j = 0; j < sm2.size; j++){
			
			sum2 += sm2.arr[j];
			
			
			k++;

		}

	sum = sum1 + sum2;
	
	printf("%d \n", sum);
	

}



void pocetToFile(int times) {
	Mnoz M1, M2, M3;
	FILE* fptr;
	errno_t err;

	err = fopen_s(&fptr, "pocty2.txt", "w");
	if (err != 0) {
		printf("Помилка відкриття файлу\n");
		return;
	}

	for (int i = 0; i < times; i++) {
		constract(&M1, i);
		constract(&M2, i);
		M3 = per(M1, M2);
		M3 = ob(M1, M2);
		printf("\n %d", k);
		fprintf(fptr, "%d\n", l);
		k = 0;
	}
	fclose(fptr);
	free(M1.arr);
	free(M2.arr);
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
	

	Mnoz n2 = ob(m1, m2);
	printf("\n");
	print(n2);
	printf("\n");
	suma(m1, m2);
	sum(m1, m2);
	printf("\n");
	printf("\n %d", k);

	pocetToFile(50);
	printf("\n");
	return 0;

}