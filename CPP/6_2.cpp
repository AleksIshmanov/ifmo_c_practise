#include <iostream>
#include <string>

using namespace std;
/*
Список студентов группы. О каждом студенте хранятся следующие сведения: Ф.И.О., год рождения, номер зачетной книжки, пол, результаты последней сессии по четырем экзаменам (физика, математика, история, химия). Вывести Ф.И.О. студентов заданной группы, не имеющих троек.
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
    int group;
    Date date;
    Sex sex;
    Session sessionResults;
    
    bool isHonour(){
        return (this->sessionResults.math!=3) ? true : false; 
    }
};

struct LinkList{
    LinkList* next = nullptr;
    Student student;

    void add(const Student& student){
        this->next =new LinkList;
        this->next->student = student;
    }
};

void setData(Student& student, LinkList* list){
    int count = 0;
    
    Sex sex = MAN;
    Date date = {10, 10, 10};
    Session session = {2,2,2,2};
    pair<int,int> groups[] = { make_pair(0,0), make_pair(1,0), make_pair(2,0), make_pair(3,0), make_pair(4,0), make_pair(5,0) };  // 
    
    for(int i=0;i<100;i++){
        student.firstName = "Name"+to_string(i);
        student.lastName = "Surname"+to_string(i);;
        student.middleName = "Daddy"+to_string(i);;
        student.bookNum = rand();
        student.sex = MAN;
        student.date = date;
        session.math =  rand() % 6;
        student.sessionResults = session;
        student.group = rand()%6;
        
        // count students for conditions
        for(int k=0;k<5;k++){
            if(groups[k].first == student.group && student.isHonour() ){
                groups[k].second += 1;
            }
        }
        
        list->add(student);
        cout << student.firstName <<" "<< list->next<<" "<< list->student.firstName << endl;
        count += student.isHonour() ? 1 : 0;
        list = list->next;
    }
    
    cout << "result:" << endl;
    for(int i=0; i<5;i++){
        cout << groups[i].first << " | " << groups[i].second << endl;
    }
    cout << "=========================="<<endl;
}

int main(){
    srand(unsigned(time(0)));
    
    Student student;    
    int group;
    
    LinkList* list = new LinkList;
    LinkList* begin = list;
    setData(student, list);
    
    cout << "Enter group number [0,1,2,3,4]" << endl;
    cin >> group;
    
    int count = 1;    
    list = begin;
    while(list->next!=nullptr){
        if(list->student.isHonour() && list->student.group==group){
            student = list->student;
            cout << count << ". "<< student.firstName << " " << student.lastName << " " << student.middleName << endl;
            count++;
        }
        list = list->next;
    }
    
    return 1;
}