#include <stdio.h>
#include <stdlib.h>

task_70(){
    int n,i;
    puts("enter length of massive: ");
    scanf("%d",&n);
    int A[n];
    srand(time(NULL));
    
    puts("\n");
    for(int i=1; i-1<n; i++){
        A[i] = rand()%100-50;
        
        if(i%5!=0){
            printf("%d\t\t", A[i]);
        }
        else {
            printf("%d\n", A[i]);
        }
        
    }

    int count=0;
    puts("\n\n");
    for(int i=1;i<n+1;i++){
        count += (A[i]>0 && A[i-1]<0) ? 1 :0;
        count += (A[i]<0 && A[i-1]>0) ? 1 :0;
    }

    printf("\n\n%d\n", count);
}

int main() {
   task_70();
}
