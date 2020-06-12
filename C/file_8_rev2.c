/**
 * Создать файл, содержащий сведения об ассортименте обуви в магазине фирмы.
 * Структура записи:
 * 1. артикул,
 *      Д - дамская
 *      М - мужская
 *      П - детская
 * 2. наименование,
 * 3. количество,
 * 4. стоимость одной пары.
 *
 * Написать программу, выдающую следующую информацию: -
 * 1. Наличие и стоимость обуви артикула Х;
 *  - ассортиментный список дамской обуви с указанием наименования и наличии числа пар каждой модели
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long max_id = 0;

FILE * f;

enum Articles {
  ALL = 0,
    KID = 'K',
    MAN = 'M',
    WOMAN = 'W'
};

struct Assortiment {
  int id;
  char article;
  char name[256];
  int count;
  int price;
} item;

void init_table();
void update_item();
void insert_new_item();
void select_all_items();
void select_items(char);
void delete_item();

void print_items(FILE*, FILE*, char);
int validate_article(char*);

FILE* open_file(char*,char*);

int main() {
  int class;
  int choice;
  while (1) {
    init_table();
    system("clear");
    printf("1. Добавить новый товар\n");
    printf("2. Удалить товар\n");
    printf("3. Отредактировать товар\n");
    printf("4. Вывести все товары\n");
    printf("5. Вывести товары для детей\n");
    printf("6. Вывести товары для мужчин\n");
    printf("7. Вывести товары для женщин\n");
    printf("0. Выход\n");
    scanf("%i", & choice);

    switch (choice) {
    case 1:
      insert_new_item();
      break;
    case 2:
      delete_item();
      break;
    case 3:
      update_item();
      break;
    case 4:
      select_all_items();
      break;
    case 5:
      select_items(KID);
      break;
    case 6:
      select_items(MAN);
      break;
    case 7:
      select_items(WOMAN);
      break;
    case 0:
      exit(0);
      break;

    }

    choice = -1;
  }
  return 1;
}

void update_item() {
  FILE * f = open_file("items.dat", "rb");
  FILE * tmp = open_file("_items.dat", "wb");
  system("clear");

  int _id = 0;
  printf("Введите идентификационный номер редактируемого товара:\n");
  scanf("%i", & _id);
  system("clear");

  while (1) {
    fread( & item, sizeof(item), 1, f);
    if (feof(f))break;

    if (item.id != _id){
      fwrite( & item, sizeof(item), 1, tmp);
    }
    else {
      char _name[256];
      printf("Введите новое название (или !, если хотите оставить %s )\n", item.name);
      scanf("%s", _name);
      if (strcmp(_name, "!"))
        strcpy(item.name, _name);


      char _article;
      printf("Введите новый артикль (или же !, если хотите оставить %c)\n", item.article);
      scanf("%s%*c", & _article);
      item.article = (_article != '!') ? _article : item.article;

      int _count;
      printf("Введите новое количество (или же -1, если хотите оставить %i)\n", item.count);
      scanf("%i", & _count);
      item.count = (_count != -1) ? _count : item.count;

      int _price;
      printf("Введите новую ценку (или же -1, если хотите оставить %i)\n", item.price);
      scanf("%i", & _price);
      item.price = (_price != -1) ? _price : item.price;

      fwrite( & item, sizeof(item), 1, tmp);
    }
  }
  fclose(f);
  fclose(tmp);
  remove("items.dat");
  rename("_items.dat", "items.dat");
}

void init_table() {
  FILE* f = open_file("items.dat", "rb");

  int k = 0;
  while (1) {
    k++;
    fread( & item, sizeof(item), 1, f);
    if (feof(f)) break;
  }
  max_id = (k != 0) ? ++item.id : 0;
}

void delete_item() {
  FILE * f = open_file("items.dat", "rb");
  FILE * tmp = open_file("_items.dat", "w");
  system("clear");

  int _id = 0;
  printf("Введите ID товара, который нужно удалить:\n");
  scanf("%i", & _id);

  while (1) {
    fread( & item, sizeof(item), 1, f);
    if (feof(f)) break;
    if (item.id != _id) fwrite( &item, sizeof(item), 1, tmp);
  }

  fclose(f);
  fclose(tmp);
  remove("items.dat");
  rename("_items.dat", "items.dat");
}

void select_items(char article) {
  FILE * db_file = open_file("items.dat", "rb");
  FILE * table_file = open_file("dump.txt", "w+");
  system("clear");

  print_items(db_file, table_file, article);

  fclose(db_file);
  fclose(table_file);
  system("cat dump.txt");
  sleep(3);

}

void select_all_items() {
  FILE* table_file = open_file("dump.txt", "w+");
  FILE* db_file = open_file("items.dat", "rb+");
  system("clear");

  print_items(db_file, table_file, ALL);

  fclose(table_file);
  fclose(db_file);
  system("cat dump.txt");
  sleep(3);
};

void insert_new_item() {
  system("clear");
  item.id = max_id;

  printf("Введите название товара: ");
  scanf("%s", &item.name);

  printf("Введите количество товара: ");
  scanf("%i", &item.count);

  printf("Введите цену: ");
  scanf("%i", &item.price);

  char _article;
  printf("Введите артикул товара: ");
  validate_article(&item.article);

  FILE* f = open_file("items.dat", "a");
  fwrite(&item, sizeof(item), 1, f);
  fclose(f);

  max_id++;
}

void print_items(FILE* db_file, FILE* table_file, char article){
  fprintf(table_file, "___________________________________________\n");
  fprintf(table_file, "|____|_____|__________|________|__________|\n");
  fprintf(table_file, "| ID | АРТ | НАЗВАНИЕ | КОЛ-ВО |   ЦЕНА   |\n");

  while (1) {
    fread(&item, sizeof(item), 1, db_file);
    if (feof(db_file)) break;

    if(item.article == article || article == ALL){
      fprintf(
            table_file, 
            "| %-2i | %-3c | %-8s | %-6i | %7i $|\n", 
            item.id, item.article, item.name, item.count, item.price
        );
    }
  }

  fprintf(table_file, "|____|_____|__________|________|__________|\n");

}

FILE* open_file(char* fileName, char* control){
  FILE *file = fopen(fileName, control);
  if ( file == NULL ) {
    printf("\nОшибка создания: %s\n", fileName);
    exit(1);
  }
  return file;
}


int validate_article(char *charInputAdress){
  scanf("%*c%c", &item.article);
  char charInputValue = *charInputAdress;

  if(charInputValue==MAN || charInputValue==WOMAN || charInputValue==KID){
      return 1;
  }

  printf("Некорректный ввод, введите одну из букв [%c|%c|%c]: ", MAN, WOMAN, KID);
  validate_article(charInputAdress);
}
