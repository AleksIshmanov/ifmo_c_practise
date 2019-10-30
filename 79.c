#include <stdio.h>

int main(){
    int n,m;
    printf("Введите размер массива и сдвиг: ");
    scanf("%d %d", &n, &m);

    int a[n];
    for (int i=0;i<n;i++) scanf("%d", &a[i]);

    while(m>0){
        for(int k=0; k<n-1; k++){
            a[k] += a[k+1];
            a[k+1]= a[k]-a[k+1];
            a[k] = a[k]-a[k+1];
        }
        m--;
    }

    for (int i=0;i<n;i++) printf("%d ", a[i]);
    puts("\n");

}
