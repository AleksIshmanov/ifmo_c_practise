#include <stdio.h>

int main(){
    char str1[256], str2[256];

    scanf("%s", str1);
    scanf("%s", str2);

    int len1=0, len2=0;
    while(str1[len1]!='\0') len1++;
    while(str2[len2]!='\0') len2++;

    if (len1<10 || len2<10 ){
        puts("Error: The string length<10");
        return 0;
    }

    int len = len2>len1 ? len2 : len1;

    //при разных длиннах заполняем строку символом '0' в ASCII->48;
    for (int i=len1; i<=len2;i++) str1[i] = 48;
    for (int i=len2; i<=len1;i++) str2[i] = 48;

    char sum[len];

    for (int i=1;i<=len;i++) {
        sum[i-1] = str1[i-1]+str2[i-1]-48*2;
//        printf("%d %d %d\n", sum[i-1], str1[i-1], str2[i-1]);
    }

    for (int i=0;i<len;i++) printf("%d ", sum[i]);
    puts("\n");

}
