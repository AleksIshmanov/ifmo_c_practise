#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // time()

//task3
int longest_col(const int m, const int n, const int matrix[m][n]){
    int col = 0;
    int count = 0; //счетчик повторений элемента
    int index; //индекс столбца в ответ

    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){//проходимся по столбцу
            int tmp_item = matrix[k][i];
            int tmp_count = 0;

            //считаем количество вхождений данного элемента в строку
            for (int f=0;f<m;f++) {
                tmp_count += tmp_item==matrix[f][i] ? 1: 0;
//                LOG("tmp %d %d %d [%d][%d] %d \n", tmp_count, tmp_item, matrix[f][i], f, i, i);
            }

            //сохраняем результаты
            if(tmp_count>count){
                count = tmp_count;
                index = i;
            }
//            LOG("for %d %d %d__ \n", count, index, tmp_count);

        }

    }

    return index;
}


int main(){
    int m =0;
    int n =0;
    srand(time(NULL));

    scanf("%d %d", &m, &n);
    int matrix[m][n];

    for(int i=0; i<m;i++){
        for(int k=0; k<n; k++){
            matrix[i][k] = rand()%5;
            printf("%d\t", matrix[i][k]);
        }
        puts("\n");
    }

    printf("\n");

    printf("Ответ: %d \n", longest_col(m, n, matrix));
}
