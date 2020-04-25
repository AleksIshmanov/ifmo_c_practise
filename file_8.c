/**
 * Создать файл, содержащий сведения об ассортименте обуви в магазине фирмы. 
 * Структура записи: 
 * 1. артикул, 
 * 	Д - дамская 
 * 	М - мужская
 * 	П - детская
 * 2. наименование, 
 * 3. количество, 
 * 4. стоимость одной пары. 
 *
 * Написать программу, выдающую следующую информацию: -
 * 1. Наличие и стоимость обуви артикула Х; 
 *  - ассортиментный список дамской обуви с указанием наименования и наличии числа пар каждой модели 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILENAME "mytest.txt"

struct Assortiment {
	char article;
	char name[10];
	int count;
	int price;
};

// Russian encoding didn't work. I tested it with 'П', 'М', 'Д'
enum Articles {
    ALL = 0,
    KID = 'K',
    MAN = 'M',
    WOMAN = 'W'
};

void writeStringToFile(char* fileName, char* string){
	FILE *file;
	file = fopen(fileName, "a");
	fprintf(file, "%s", string);
	fclose(file);
}

int readStringFromFile(FILE *file, struct Assortiment* products, int i){
    return fscanf(
        file, 
        "%s%*c %i %s %f",
        &products[i].article,
        &products[i].count, 
        &products[i].name,  
        &products[i].price
    );
}

void printTableRow(struct Assortiment* products, int i) {
    printf(
        "%c %i %s %f\n", 
        products[i].article,
        products[i].count,  
        products[i].name, 
        products[i].price 
    );
}


void printProducts(char* fileName, enum Articles article){
	FILE *file;
	file = fopen(fileName, "r");

	struct Assortiment products[256]; //множество со всем ассортиментом товаров
	char row[256]; //строка сохраняет результат чтения
	int i = 0;

	if(file != NULL){
		while( readStringFromFile(file, products, i) != EOF){
            if(article==ALL){
                printTableRow(products, i);
                continue;
            }

            if(article==products[i].article){
                printTableRow(products, i);
            }			
            i++;
		}
	}
	else {
		printf("Невозможно открыть файл '%s' ", fileName);
	} 
}

int clearFile(char *filename) {
	FILE *file = fopen(filename, "w");
	if (!file)
		return 1;
	fclose(file);
	return 0;
}

int inputCorrectArticle(char *charInputAdress){
	scanf(" %c", charInputAdress);
    char charInputValue = *charInputAdress;

    if(charInputValue==MAN || charInputValue==WOMAN || charInputValue==KID){
        return 1;
    }

    printf("Некорректный ввод, введите одну из букв [%c|%c|%c]: ", MAN, WOMAN, KID);
    inputCorrectArticle(charInputAdress);
}

int getUserInput(char* filename){
	int isUserWantAddNew = 0;
	char finalString[256];
    memset(finalString, '\0', sizeof finalString);

	char article;
	char count[10];
	char name[51];
	char price[5];	
	char space = ' ';

    puts("------------------------------------");
	printf("Хотите добавить новый товар? [1/0]: ");
	scanf("%i", &isUserWantAddNew);

	if(isUserWantAddNew>0){
        printf("Выберите один артикл товара [%c|%c|%c]: ", MAN, WOMAN, KID);
        inputCorrectArticle(&article);

		printf("Какое количество товара находится в наличии? ");
		scanf(" %s", &count);

		printf("Введите наименование товара (!ПРОБЕЛЫ ЗАПРЕЩЕНЫ): ");
		scanf(" %50s", &name);

		printf("Введите цену товара: ");
		scanf(" %s", &price);
	
		//format a string to write a row into the file
        finalString[0]=article;
        finalString[1]=space;

		
		strcat(&finalString, count);
		strncat(&finalString, &space, 1);
		
		strcat(&finalString, name);
		strncat(&finalString, &space, 1);
		
		strcat(&finalString, price);
		strncat(&finalString, "\n", 1);
		
        printf("final String: %s\n", finalString);
		//save a file and ask again
		writeStringToFile(FILENAME, finalString);
		getUserInput(FILENAME);
	}
	return 0;
}

int main() {
    setlocale(LC_ALL, "Rus");
//	clearFile(FILENAME);

	getUserInput(FILENAME);
	puts("--------------ALL-----------");
	printProducts(FILENAME, ALL);
	puts("--------------MAN-----------");
	printProducts(FILENAME, MAN);
	puts("-------------WOMAN----------");
	printProducts(FILENAME, WOMAN);
	puts("--------------KID-----------");
	printProducts(FILENAME, KID);

	puts("Work ended");	
	return 0;
}
