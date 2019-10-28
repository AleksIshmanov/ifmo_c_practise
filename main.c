#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // time()
#include <locale.h>


#define LOG(M, ...) fprintf(stderr, "[LOG] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

//LOG("for %d %d %d %d\n", i, k, tmp_sum, matrix[k][i]);

//task 5
void clean_matrix(const int m, const int n, int matrix[m][n]){

    int newRows=m; //кол-во строк на финальный вывод
    int newCols=n; //количество столбцов на финальный вывод

    int rowShiftCount=0; //счетчик количества нулевых строк
    int colShiftCount=0; //счетчик количества нулевых столбцов

    for (int i=0;i<m;i++){
        int countZeroItemRow=0;
        int countZeroItemCol=0;

        for(int k=0; k<n; k++){
            // считаем нулевые строки
            countZeroItemRow += ( matrix[i][k]==0 ) ? 1 : 0;
            countZeroItemCol += ( matrix[k][i]==0 ) ? 1 : 0;
        }

        //смещаем нулевую строку в конец
        if( countZeroItemRow == n){

            puts("b___\n");
            for (int i=0;i<m;i++) {
                for(int k=0;k<n;k++){
                    printf("%d \t",matrix[i][k]);
                }
                puts("_\n");
            }

            for (int k=0;k<m-1;k++) {
                for (int j=0;j<n-1;j++) {
                    matrix[j][k] += matrix[j+1][k];
                    matrix[j+1][k] = matrix[j][k] - matrix[j+1][k];
                    matrix[j][k] = matrix[j][k] - matrix[j+1][k];
                }
            }
            newRows--;


            puts("a__\n");
            for (int i=0;i<m;i++) {
                for(int k=0;k<n;k++){
                    printf("%d \t",matrix[i][k]);
                }
                puts("_\n");
            }
        }


        // смещаем столбец вправо
//        if( countZeroItemCol == m){
//            for (int k=0;k<n-1;k++) {
//                for (int j=k;j<m;j++) {
//                    matrix[k][j]    += matrix[k][j+1];
//                    matrix[k][j+1]  = matrix[k][j] - matrix[k][j+1];
//                    matrix[k][j]    = matrix[k][j] - matrix[k][j+1];
//                }
//            }
//            newCols--;
//        }

    }

    printf("after: %d %d\n", newRows, newCols);
    for (int i=0;i<newRows;i++) {
        for(int k=0;k<newCols;k++){
            printf("%d \t",matrix[i][k]);
        }
        puts("\n");
    }
}


//task 17
int string_sum(){

    int s;
    printf("Введите длину строк: ");
    scanf("%d", &s);

    char str1[s], str2[s];

    printf("Введите строку 1: ");
    scanf("%d");

    printf("Введите строку 1: ");
    scanf("%d");
}


int main(){
    setlocale(LC_ALL, "Rus");

    int m =0;
    int n =0;
    srand(time(NULL));

    scanf("%d %d", &m, &n);
    int matrix[m][n];

    for(int i=0; i<m;i++){
        for(int k=0; k<n; k++){
//            matrix[i][k] = rand()%2;
            matrix[i][k] = i%2==0 ? 0 : rand()%3;

            printf("%d\t", matrix[i][k]);
        }
        puts("\n");
    }

    printf("\n");

    clean_matrix(m, n, matrix);

    //printf("Clean matrix: %d \n", clean_matrix(m,n, matrix));
}


