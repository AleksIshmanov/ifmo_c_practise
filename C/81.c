#include <stdio.h>

int main(){
    //Заполним массив, количество строк мы обозначим m, а столбцов - n.
     int m, n;

     scanf("%d%d", &m, &n);

     //С помощью переменной s задаются числа внутри массива начиная с 1.
     int s = 1;

     //Объявляем и инициализируем массив.
     int array[m][n];

     //обнуляем матрицу
     for (int i=0;i<m;i++){
         for (int k=0;k<n;k++){
             array[i][k] = 0;
         }
     }

     //Заполняем периметр массива по часовой стрелке.
     //это нужно, чтобы установить ограничения в дальнейшем
     for (int y = 0; y < n; y++) {
         array[0][y] = s;
         s++;
     }
     for (int x = 1; x < m; x++) {
         array[x][n - 1] = s;
         s++;
     }
     for (int y = n - 2; y >= 0; y--) {
         array[m - 1][y] = s;
         s++;
     }
     for (int x = m - 2; x > 0; x--) {
         array[x][0] = s;
         s++;
     }

     //Все значения кроме периметра нулевые.
     //Читаем пока не ноль и заполняем
     int c = 1;
     int d = 1;

     while (s < m * n) {

         //Движемся вправо.
         while (array[c][d + 1] == 0) {
             array[c][d] = s;
             s++;
             d++;
         }

         //Движемся вниз.
         while (array[c + 1][d] == 0) {
             array[c][d] = s;
             s++;
             c++;
         }

         //Движемся влево.
         while (array[c][d - 1] == 0) {
             array[c][d] = s;
             s++;
             d--;
         }

         //Движемся вверх.
         while (array[c - 1][d] == 0) {
             array[c][d] = s;
             s++;
             c--;
         }
     }

     //Удааляем центральный элемент
     for (int x = 0; x < m; x++) {
         for (int y = 0; y < n; y++) {
             if (array[x][y] == 0) {
                 array[x][y] = s;
             }
         }
     }

     for (int x = 0; x < m; x++) {
         for (int y = 0; y < n; y++) {
             printf("%d\t", array[x][y]);
         }
         puts("\n");
     }
}
