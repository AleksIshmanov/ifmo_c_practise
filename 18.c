#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


void mathAction(const char sign, char *left, char *right) {
    int leftInt = atoi(left);
    int rightInt = atoi(right);

    switch (sign) {
        case '+': leftInt+=rightInt; break;
        case '-': leftInt-=rightInt; break;
        case '*': leftInt*=rightInt; break;
        case '/': leftInt/=rightInt; break;
    }

    sprintf(left,"%d",leftInt);
    printf("_%s ", left);
}

//проверяет является ли математическим знаком
//в случае ошибки завершает приложение
int isSign(const char sign){
    char signs[4] = {'+','-','*','/'};
    char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};

    for (int i=0;i<4;i++) {
        if(sign==signs[i]){
            return 1;
        }
    }

    for (int i=0;i<10;i++) {
        if(sign==nums[i]){
            return 0;
        }
    }

    if(sign=='\0')
        return 1;

    //попадем сюда в случае, если не мат. символ и не число
    printf("Incorrect character inside the equation: [%c] -> ASCII[%d]", sign, sign);
    exit(0);
}

int main(){
    char str[256], left[10], right[10];;
    scanf("%s",str);

    int i=0;
    int lenLeft=0, lenRight=0; //длина строки, нужна в качества индекса для

    char sign;
    //сохраняем первое число в буфер
    while(isSign(str[i]) == 0 ){
        left[lenLeft] = str[i];
        lenLeft++;
        i++;
    }
    sign = str[i];
    i++;

    //выполняем действия из буфер+след. число
    while(str[i]!='\0'){
        while(!isSign(str[i]) ){
            right[lenRight]=str[i];
            i++;
            lenRight++;
        }

        mathAction(sign, left, right);
        sign = str[i];
        i++;
    }


    int result = atoi(left);

    printf("%d\n", result);
}
