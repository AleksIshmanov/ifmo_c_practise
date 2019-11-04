#include <stdio.h>
#include <locale.h>

typedef enum {false, true} bool;

bool isBlocked(const int* nums, const int el, int arraySize){
	for(int i=0;i<arraySize;i++){
		if(el==nums[i]){
			//puts("blocked");
			return true;
		}
	}
	return false;
}

int main(){
	setlocale(LC_ALL, "Rus");
	int n, count=0;

	printf("Введите размер массива: ");
	scanf("%d", &n);
	printf("Сколько элементов удалить?: ");
	scanf("%d", &count);

	int mas[n];
	int minNum=999999;
	for(int i=0;i<n;i++){
	 	scanf("%d", &mas[i]);
		minNum = mas[i]<minNum ? mas[i] : minNum; 
	}

	//заполним первый элемент минимального массива
	//наименьшим числом, от него далее будем сравнивать
	int minArray[count];
	minArray[0]=minNum;

	// 5 -4 4 4 -5 0 34 9 2

	//ищем N наименьших элементов
	for(int c=1; c<count;c++){
		int tmpMin=99999;
		for(int i=0; i<n;i++){
			if(mas[i]<tmpMin && mas[i]>minArray[c-1]){
				tmpMin = mas[i];
			}
		}
		minArray[c]=tmpMin;
	}

	//for(int i=0;i<count;i++) printf("%d", minArray[i]);

	printf("\nОтвет: ");
	for(int i=0;i<n;i++){
		//выводим, если число не попало в блокировку
		if (isBlocked(minArray,mas[i],count)==false) 
			printf("%d ", mas[i]);
	}
}
