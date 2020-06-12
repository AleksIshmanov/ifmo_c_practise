#include <stdio.h>
#include <locale.h>

//быстрая сортировка
void qsort(int* arraySize, int start, int finish){
	int i=start, j=finish, x=arraySize[(start+finish)/2];
	
	do {
		while (arraySize[i]<x) i++;
		while (arraySize[j]<x) j--;

		if(i<=j){
			if(arraySize[i]>arraySize[j]){
				int tmp = arraySize[i];
				arraySize[i] = arraySize[j];
				arraySize[j] = arraySize[tmp];
			}
			
			i++;
			j--;
		}

	} while (i<=j);

	(i<finish) ? qsort(arraySize, i, finish) : 0;
	(start<j) ? qsort(arraySize, start, j) : 0;
}

int main(){
	setlocale(LC_ALL, "Rus");

	int n1, n2;
	puts("Введите размеры массива: ");
	scanf("%d%d", &n1, &n2);

	int mas1[n1], mas2[n2];

	puts("Введите первый массив: ");
	for(int i=0;i<n1;i++) scanf("%d", &mas1[i]);
	
	puts("Введите второй массив: ");
	for(int i=0;i<n2;i++) scanf("%d", &mas2[i]);

	//отсортируем массивы, для быстрого поиска
	//int a = n1;
	//qsort(a, mas1[0],mas1[n1-1]);
	
	/*
	for(int i=1;i<n1;i++){
		for(int k=0;k<n1-i;k++){
			if(mas1[k]<mas1[k+1]){
				mas1[k]+=mas1[k+1];
				mas1[k+1] = mas1[k]-mas1[k+1];
				mas1[k] = mas1[k]-mas1[k+1];
			}
		}
	}

	for(int i=0;i<n2;i++){
		for(int k=0;i<n2;k++){
			if(mas2[k]<mas2[k+1]){
				mas2[k]+=mas2[k+1];
				mas2[k+1] = mas2[k]-mas2[k+1];
				mas2[k] -= mas2[k+1];
			}
		}
	}
	*/

	int max = -99999;

	for(int i=0;i<n1;i++){
		int flag=0;
		for(int k=0;k<n2;k++){
			if(mas1[i]==mas2[k]){
				flag=1;
			}
		}

		if(flag!=1){
			max= max>mas1[i] ? max : mas1[i];
		}

	}

	printf("Ответ: %d", max);

}
