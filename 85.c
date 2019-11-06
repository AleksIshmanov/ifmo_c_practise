#include <stdio.h>

int main(){
	int m, n;
	scanf("%d%d", &m, &n);

	int matrix[m][n];

	int num=1;
	int exIndex=0; //индекс крайнего столбца/строки
	
	int len= m>n ? m : n;
	for(int i=0; i<len;i++){
		for(int k=i;k<n-i;k++) matrix[i][k]=num; // верхняя строка
		for(int k=i;k<n-i;k++) matrix[m-i-1][k]=num; // нижняя строка

		for(int k=i;k<m-i;k++) matrix[k][i] = num; //левый столбец
		for(int k=i;k<m-i;k++) matrix[k][n-i-1] = num; //правый столбец
		
		//puts("gg");

		/*
			matrix[k][i] = num; //верхняя строка
	 		matrix[n-k-1][i] = num;	//нижняя строка
			matrix[i][k] = num; //левый столбец
			matrix[m-k-1][i] = num; //правый столбе
		*/

		//exIndex++;
		num++;
	}

	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			printf("%d \t", matrix[i][k]);
		}
		printf("\n");
	}

}
