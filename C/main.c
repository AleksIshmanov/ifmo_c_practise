#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define LOG(M, ...) fprintf(stderr, "[LOG] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define CHARSHIFT 48;

//LOG("for %d %d %d %d\n", i, k, tmp_sum, matrix[k][i]);

int strLength(const char* str){
    int size=0;
    while(*str++) ++size;
    return size;

}

//task 17
void string_sum(){
    setlocale(LC_ALL, "Rus");


    int s;
    printf("Enter the length of strings: ");
    scanf("%d", &s);

    char str1[256], str2[256];

    printf("Input string 1: ");
    scanf("%s", str1);

    printf("Input 2: ");
    scanf("%s", str2);

    long long int sum= 0;
    for (int i=0;i<s;i++) {
        //в ASCII кодировке наши числа принадлежат диапазону
        // от 48 до 57 поэтому просто отнимаем 48
        int num1 = str1[i]-CHARSHIFT;
         num2= str2[i]-CHARSHIFT;
        sum+=  (long long int)num1 + (long long int)num2;
    }
    printf("sum->%lld", sum);


//    int newSize = strLength();
//    char result[newSize];

//    //разбиваем число на множество отдельных символов
//    for (int i=0;i<newSize;i++) {
//        result[i] = (char)(sum % (long long int)pow(10, i) - (long long int)pow(10, i-1));
//    }

//    printf("Sum string: ");
//    for (int i=0;i<s;i++) printf("%d", result[i]);
}


int main(){

    string_sum();
    //printf("Clean matrix: %d \n", clean_matrix(m,n, matrix));
}


