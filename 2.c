#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//task2
int matrix_min(int Size, int matrix[Size][Size]){
    int min=100000;

    for(int i=0; i<Size-1; i++){
        int t_left = 0; int t_right = 0;//временные суммы left
        for(int k=0; k+i+1<Size; k++){
            int d_index = k+i+1; //дополнительный индекс
            t_right += matrix[k][d_index]; //праввый верхний угол
            t_left += matrix[d_index][k]; //левый нижний угол
        }

        if(min>t_left){
            min = t_left;
        } else if (min>t_right) {
            min = t_right;
        }
    }

    return min;
}


int main(){
    int m;
    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &m);
    int matrix[m][m];
    srand(time(NULL));

    puts("\n");
    int k=0;
    for(int i=0; i<m; i++){
        for (int k=0; k<m;k++) {
            matrix[i][k] = rand()%100-50;
            printf("%d \t", matrix[i][k]);
        }
        puts("\n");
    }

    printf("Сумма наименьше диагонали: %d \n\n", matrix_min(m, matrix));
    return 0;
}
