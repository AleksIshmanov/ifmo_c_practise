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
    
    Session(){
        math =  rand() % 6;
        physics =  rand() % 6;
        history =  rand() % 6;
        chemistry =  rand() % 6;
    }
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
    
    Student(){
        this->firstName = "Name";
        this->lastName = "Surname";
        this->middleName = "Daddy";
        this->bookNum = rand();
        this->sex = MAN;
        this->date = date;
        this->group = rand()%6;
    }
    
    Student(const int& i, const Date& date){
        this->firstName = "Name"+to_string(i);
        this->lastName = "Surname"+to_string(i);
        this->middleName = "Daddy"+to_string(i);
        this->bookNum = rand();
        this->sex = MAN;
        this->date = date;
        this->group = rand()%6;
    }
    
    bool isHonour(){
        bool math = (this->sessionResults.math != 3) ? true : false;
        bool physics = (this->sessionResults.physics != 3) ? true : false;
        bool history = (this->sessionResults.history != 3) ? true : false;
        bool chemistry = (this->sessionResults.chemistry != 3) ? true : false;
        
        return math&physics&history&chemistry ? true : false;
        
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

void setData(LinkList* list){
    int count = 0;
    Date date = {10, 10, 10};
    
    pair<int,int> groups[] = { make_pair(0,0), make_pair(1,0), make_pair(2,0), make_pair(3,0), make_pair(4,0), make_pair(5,0) }; 
    for(int i=1;i<=100;i++){
        Student student(i, date);    
        Session session();
        
        // count students for conditions
        for(int k=0;k<5;k++){
            if(groups[k].first == student.group && student.isHonour() ){
                cout << 
                    student.group << " " << student.firstName << " " << 
                    student.sessionResults.math << " " << student.sessionResults.physics << " " <<
                    student.sessionResults.chemistry << " " << student.sessionResults.history << " " <<
                endl;
                
                groups[k].second += 1;
            }
        }
        
        list->add(student);
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
    
    int group;
    
    LinkList* list = new LinkList;
    LinkList* begin = list;
    setData(list);
    
    cout << "Enter group number [0,1,2,3,4]" << endl;
    cin >> group;
    
    int count = 1;    
    list = begin;
    while(list->next!=nullptr){
        if(list->student.isHonour() && list->student.group==group){
            Student student = list->student;
            cout << count << ". "<< student.firstName << " " << student.lastName << " " << student.middleName << endl;
            count++;
        }
        list = list->next;
    }
    
    return 1;
}