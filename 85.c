#include <stdio.h>

void printfMatrix(int m, int n, int matrix[m][n]){
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			printf("%d \t", matrix[i][k]);
		}
		printf("\n");
	}
	
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	int matrix[m][n];

	
	int num=1;
	int len= m<n ? m : n;
	len = (len/2)+(len%2); //кол-во проходов

	for(int i=0; i<len;i++){
		for(int k=i;k<n-i;k++) matrix[i][k]=num; // верхняя строка
		for(int k=i;k<n-i;k++) matrix[m-i-1][k]=num; // нижняя строка

		for(int k=i;k<m-i;k++) matrix[k][i] = num; //левый столбец
		for(int k=i;k<m-i;k++) matrix[k][n-i-1] = num; //правый столбец
		
		printf("\n_%d_\n", i);
		printfMatrix(m,n, matrix);

		num++;
	}

	puts("\n");
	printfMatrix(m,n, matrix);

}
