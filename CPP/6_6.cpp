#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILENAME "mytest.txt"

/*
Сформировать массив на диске, содержащий сведения об ассортименте обуви в магазине фирмы. Класс содержит поля: артикул, наименование, количество, стоимость одной пары. Артикул начинается с буквы Д – для дамской обуви, М – для мужской, П – для детской. 
Написать программу, которая выбирает необходимую информацию с диска и выводит на экран: 
- сведения о наличии и стоимости обуви артикула X; 
- ассортиментный список дамской обуви с указанием наименования и имеющегося в наличии числа пар каждой модели. 

*/

class FileController(){
private:
    FILE* file;

public:
    FileController(const string& filename){
        if ((this->file = fopen(filename, "r")) == NULL){
            printf("Couldn't open file");
            exit(0);
        }
        return this->file;
    }
    
    ~FileController(){
        cout << "Close file" << endl;
        fclose(this->file);
    }
    
    read_line(Boot& products, int i){
        return fscanf(
            this->file, 
            "%s%*c %i %s %f",
            products[i].article,
            products[i].count, 
            products[i].name,  
            products[i].price
        );
    }
    
    append_line(const string& line){
        
    }    
}

class Catalog(){
    
private:
    FileController file;
    struct Boot products[256]; //множество со всем ассортиментом товаров
    
public:
    static enum Articles {
        ALL = 0,
        KID = 'K',
        MAN = 'M',
        WOMAN = 'W'
    };
    
    Catalog(const string& filename){
        this->file(filename);
        cout << file << endl;
    }
    
    void create(){
        bool isUserWantAddNew;
        string finalString;
        

        char article;
        char count[10];
        char name[51];
        char price[5];	
        char space = ' ';

        puts("------------------------------------");
        printf("Хотите добавить новый товар? [1/0]: ");
        scanf("%i", &isUserWantAddNew);

        if(isUserWantAddNew){
//            cout << "Введите строку в формате АРТИКЛЬ;КОЛИЧЕСТВО;НАИМЕНОВАНИЕ;ЦЕНА" << endl;
//            cin >> article >> count >> name >> price;
            
            printf("Выберите один артикл товара [%c|%c|%c]: ", MAN, WOMAN, KID);
            cin >> article;

            printf("Какое количество товара находится в наличии? ");
            cin >> count;

            printf("Введите наименование товара (!ПРОБЕЛЫ ЗАПРЕЩЕНЫ): ");
            cin >> name;

            printf("Введите цену товара: ");
            cin >> price;

            // TODO make it by stringStream;
            finalString = article+" "+count+" "+name+" "+price+"\n";
            printf("final String: %s\n", finalString);
            
            //save a file and ask again
            file.append_line(finalString);
            this->create();
        }
        return 0;
    }
    
    
    void print(const enum Articles article){
        for(int i=0; file.read_line(products, i)!= EOF; i++){
            if(article==ALL){
                print_line(i);
                continue;
            }

            if(article==products[i].article){
                print_line(i);
            }
        }
    }
        
    print_line(const int& i){
        return fscanf(
            this->file, 
            "%s%*c %i %s %f",
            this->products[i].article,
            this->products[i].count, 
            this->products[i].name,  
            this->products[i].price
        );
    }
    
    
    
}


int main(){
    Catalog boots('boots.txt');
    
    boots.create();
    boots.print(ALL);
    boots.print(KID);
    boots.print(MAN);
    boots.print(WOMAN);
}
