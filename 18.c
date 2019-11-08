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
int isMathSign(const char sign){
    char signs[4] = {'+','-','*','/'};
    char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};

		printf("%c ", sign);

    for (int i=0;i<4;i++) {
        if(sign==signs[i]){
            return TRUE;
        }
    }

    for (int i=0;i<10;i++) {
        if(sign==nums[i]){
            return FALSE;
        }
    }

    //попадем сюда в случае, если не мат. символ и не число
    printf("Incorrect character inside the equation: [%c] -> ASCII[%d]", sign, sign);
    exit(0);
}


/**
 * Рекурсивная функция для определения числа слева от математического знака 
 *
 * @return int размер полученного числа
 * @change char* leftNumCharArray - динамически изменяет его размер и содержимое 
*/
void getLeftNum(char* leftNumCharArray, char* str, int count){
	if(isMathSign(str[count])){ //условие выхода - символ является математическим знаком
		leftNumCharArray = malloc(count*sizeof(str[0])); //создаем число в формате char[Count-1] размером в количество найденных рекурсий
		printf("\n%d %d ", count*sizeof(str[0]), count);
		return;
	}

	//leftNumCharArray = (char*) realloc(leftNumCharArray, count*sizeof(str[0]));
	getLeftNum(leftNumCharArray, str, count+1); //рекурсия
	printf("\nggwp %s %d\n", leftNumCharArray, count);
	leftNumCharArray[count] = str[count]; //присваиваем значения
}


int main(){
    char str[256], left[10], right[10];;
    scanf("%s",str);

    int i=0;
    int lenLeft=0, lenRight=0; //длина строки, нужна в качества индекса для

    char sign;
   
	  char *leftNumCharArray;	
		getLeftNum(leftNumCharArray, str, 0);//получаем первое число
		
		printf("done");

  //  for(int i=0;i<len;i++) printf("%d ", leftNumCharArray[i]);
		
		

		/*
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
		*/

    //printf("%d\n", result);
		//
		return 0;
}
