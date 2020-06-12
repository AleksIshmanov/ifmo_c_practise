#include <stdio.h>
#include <stdlib.h>

void task_4(){
    int n,i;
    puts("Enter length of matrix: ");
    scanf("%d",&n);
    int A[n*n];
    int Final[n*n];
    srand(time(NULL));

    puts("\n");
    for(int i=0; i<n*n; i++){
        A[i] = rand()%100-50;
        Final[i] = A[i];

        if((i+1)%5!=0){
            printf("%d\t\t", A[i]);
        }
        else {
            printf("%d\n", A[i]);
        }

    }


    //сортируем массив
    for (int i=0;i<n*n;i++) {
        for (int k=0; k<n*n-1;k++) {
            if(A[k]<A[k+1]){
                A[k+1] = A[k+1]+A[k];
                A[k] = A[k+1]-A[k];
                A[k+1] = A[k+1]-A[k];
            }
        }
    }

    printf("\nОтвет:\n");
    //вставляем в диагональ
    for (int i=0; i<n; i++) {
        Final[i*n+i] = A[i];
    }

    for (int i=0;i<n*n;i++) {
        if((i+1)%5!=0){
            printf("%d\t\t", Final[i]);
        }
        else {
            printf("%d\n", Final[i]);
        }

    }


}

int main() {
   task_4();
}
