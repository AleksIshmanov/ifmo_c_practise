#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // time()
#include <locale.h>


//task 5 indexes
void clean_matrixAlt(const int m, const int n, int matrix[m][n]){

    int zeroIndexesRow[m];
    int zeroIndexesCol[n];
    memset( zeroIndexesRow, -1, m*sizeof(int) );
    memset( zeroIndexesCol, -1, n*sizeof(int) );


    //считаем нулевые строки
    for (int i=0;i<m;i++){
        int countZeroItemRow=0;
        for(int k=0; k<n; k++)
            countZeroItemRow += ( matrix[i][k]==0 ) ? 1 : 0;
       zeroIndexesRow[i] = (countZeroItemRow==n) ? i : -1;
    }

    //считаем нулевые столбцы
    for (int i=0;i<n;i++){
        int countZeroItemCol=0;
        for(int k=0; k<m; k++)
            countZeroItemCol += ( matrix[k][i]==0 ) ? 1 : 0;
       zeroIndexesCol[i] = (countZeroItemCol==m) ? i : -1;
    }


    for (int i=0;i<m;i++) {
        for(int k=0;k<n;k++){
            int flagColHide=0, flagRowHide=0;;

            //проверка нулевых индексов строки
            for (int j=0;j<m;j++)
                flagRowHide += (i==zeroIndexesRow[j]) ? 1: 0;

            //проверка нулевых индексов столбца
            for (int j=0;j<n;j++)
                flagColHide += (k==zeroIndexesCol[j]) ? 1: 0;

            //если элемент не объявлен к скрытию - отображаем его
            if(flagRowHide>0 || flagColHide>0)
                continue;
            else{
                printf( "%d\t",matrix[i][k]);
                (k==n-1) ? puts("\n") : 0;
            }
        }
    }

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
            matrix[i][k] = i%2==0 ? 0 : rand()%3;
            printf("%d\t", matrix[i][k]);
        }
        puts("\n");
    }

    printf("\n");
    clean_matrixAlt(m, n, matrix);
    puts("end");

}
