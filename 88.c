#include <stdio.h>

int main(){
	int n;
	printf("n: ");
	scanf("%d", &n);
	
	int A[2*n], B[n], C[n];

	for(int i=0;i<2*n;i++) scanf("%d", &A[i]);

	//сортируем массив
	for(int i=0;i<2*n-1;i++){
		for(int k=0;k<2*n-i-1;k++){
			if(A[k]>A[k+1]){
				A[k]+=A[k+1];
				A[k+1]= A[k]-A[k+1];
				A[k]-=A[k+1];
			}
		}
	}

	for(int i=0;i<2*n;i++) printf("%d ", A[i]);

	int count;
	for(int i=0; i<2*n; i++){
		count = i/2;
		if(i%2)
			B[count]=A[i];
		else
			C[count]=A[i];
	}

	puts("\n");
	for(int i=0;i<n;i++) printf("%d ", B[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ", C[i]);
	puts("\n");	
}
