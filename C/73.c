#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Rus");

	int m, n;
	puts("Введите размер матрицы (m,n): ");
	scanf("%d%d", &m, &n);

	int matrix[m][n];
	int nums[4]={1,2,3,4};

	int j=0;

	for(int i=0; i<m;i++){
		for(int k=0;k<n;k++){
			if(j==4){
				j=0;
			}
			matrix[i][k]=nums[j];
			j++;
		}
		j = i%2==0 ? 2 : 0;
	}

	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			printf("%d\t",matrix[i][k]);
		}
		puts("\n");
	}
}
