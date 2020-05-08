#include <iostream>
#include <string>

using namespace std;
/*
Список студентов группы. О каждом студенте хранятся следующие сведения: Ф.И.О., год рождения, номер зачетной книжки, пол, результаты последней сессии по четырем экзаменам (физика, математика, история, химия). Вывести Ф.И.О. студентов, получивших отличные оценки по математике.
*/

enum Sex {
    MAN = 'M',
    WOMAN = 'W',
};

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct Session {
    int math;
    int physics;
    int history;
    int chemistry;
};

struct Student{
    string firstName;
    string lastName;
    string middleName;
    int bookNum;
    Date date;
    Sex sex;
    Session sessionResults;
    
    bool isHonour(){
        return (this->sessionResults.math==5) ? true : false; 
    }
};

struct LinkList{
    LinkList* next = nullptr;
    Student student;

    void add(const Student& student){
        this->next =new LinkList;
        this->next->student = student;
    }
} *list;

int main(){
    srand(unsigned(time(0)));
    
    Sex sex = MAN;
    Date date = {10, 10, 10};
    Session session = {2,2,2,2};
    Student student;
    
    LinkList* begin;
    list = new LinkList;
    begin = list;
    
    int count = 0;
    for(int i=0;i<100;i++){
        student.firstName = "Name"+to_string(i);
        student.lastName = "Surname"+to_string(i);;
        student.middleName = "Daddy"+to_string(i);;
        student.bookNum = rand();
        student.sex = MAN;
        student.date = date;
        session.math =  rand() % 6;
        student.sessionResults = session;

        list->add(student);
        cout << student.firstName <<" "<< list->next<<" "<< list->student.firstName <<" "<< begin << endl;
        count += student.isHonour() ? 1 : 0;
        list = list->next;
    }
    cout << "Totaly: " << count << endl;
    cout << "=========================="<<endl;
    
    count = 1;    
    list = begin;
    while(list->next!=nullptr){
        if(list->student.isHonour()){
            student = list->student;
            cout << count << ". "<< student.firstName << " " << student.lastName << " " << student.middleName << endl;
            count++;
        }
        list = list->next;
    }
    
    return 1;
}