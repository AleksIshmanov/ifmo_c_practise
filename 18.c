#include<stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int mathAction(int left, int right, char sign){
	switch(sign){
		case '+' : return left+right;break; 
		case '-' : return left-right;break; 
		case '*' : return left*right;break; 
		case '/' : return left/right;break;
		default: 
			printf("\nSign [%c] incorrect", sign);
			exit(1); 
	}
}

int isMathSign(const char sign){
	char signs[4]= "+-*/";
	
	for(int i=0;i<4;i++)
		if(sign==signs[i])
			return TRUE;

	return FALSE;
}

int isNum(const char sign){
	return (sign>=48 && sign<=57) ? TRUE : FALSE;
}

int getNum(char* str, int *index)
{
	int buffer = 0;

	int c = *index;
	while(isNum(str[c])){
		buffer = buffer * 10 + (str[c]-48);
		c++;
		*index = c;
	}

	//Проверка на некорректные символы
	if(!isMathSign){
		printf("\nSign [%c] incorrect", str[c]);
		exit(1);
	}

	return buffer;	
}

int main()
{
  char str[254];
  scanf("%s", str);
	
	int index=0;

	//заполняем первое число, 
	int result = getNum(str, &index);
	char sign = str[index];
	index++;

	while(str[index-1]!=0){
		int rightNum = getNum(str, &index);
		result = mathAction(result, rightNum, sign);
		sign = str[index];
		index++;
	}

	printf("Result: %d", result);
	return 0;
}
