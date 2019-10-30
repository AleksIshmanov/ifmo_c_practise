#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int n=0;
    printf("Введите размер масссива: ");
    scanf("%d", &n);

    int a[n];
    int countMax=0;

    srand(time(NULL));
    for (int i=0;i<n;i++) a[i]=rand()%2;

    for (int i=0;i<n;i++) printf("%d ", a[i]);

    int countLoopZero=0; //считаем количество встречанных нулей при подсчете

    for (int i=0;i<n;i++)
    {
        int tmpCount=0;
        while(a[i]==0)
        {
           tmpCount++;
           i++;
        }

        if(tmpCount>countMax)
        {
            countMax = tmpCount;
        }
    }

    printf("\n%d\n", countMax);
}
