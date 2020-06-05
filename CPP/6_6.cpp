#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
/*
 Список результатов метеорологических наблюдений по месяцам. Элемент списка хранит следующие данные: период наблюдения (месяц и год), количество дней месяца, минимальная зафиксированная температура воздуха, максимальная зафиксированная температура воздуха. Определить год с наиболее высокой минимальной температурой, зафиксированной в течение зимних месяцев.
*/

int rand_int(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

enum MonthDateNames {
  Jan = 1,
  Feb,
  Mar,
  Apr,
  May,
  Jun,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec,
};

struct Date{
    int month=rand_int(1,12);
    int year=rand_int(2018,2020);
    int day=rand_int(1,31);
};

struct Experiment {
  Date date {};
  int minAirTemperature;
  int maxAirTemperature;

  void set_rand(){
    minAirTemperature = rand_int(-50, 0);
    maxAirTemperature = rand_int(0,50);
  };

  friend std::ostream& operator<< (std::ostream &out, const Experiment& experiment);
};

/* singly linked list for struct Experiment */
struct Node{
    Node* next = nullptr;
    Experiment experiment;

    /* Given a reference (point to pointer)  
      to the head of a list and an Experiment,  
      inserts a new node on the front of the list. */
    void add(Experiment experiment){

      next = new Node;
      next->experiment = experiment;

    }

    /* Given a reference (pointer to pointer) 
    to the head of a list and an Experiment, inserts 
    a new node on the front of the list. */
    void push(Node** head_ref, Experiment experiment)  
    {  
        /* 1. allocate node */
        Node* new_node = new Node(); 
      
        /* 2. put in the data */
        new_node->experiment = experiment;  
      
        /* 3. Make next of new node as head */
        new_node->next = (*head_ref);  
      
        /* 4. move the head to point to the new node */
        (*head_ref) = new_node; 
    }
};

std::ostream& operator<< (std::ostream &out, const Experiment& experiment){
  out << experiment.date.year << "-";
  out << setw(2) << setfill('0') << experiment.date.month  << "-";
  out << setw(2) << setfill('0') << experiment.date.day << " ";

  out << " | " << setw(2) << setfill('0') << experiment.maxAirTemperature;
  out << " | " << setw(3) << setfill(' ') << experiment.minAirTemperature;
  out << " | ";

  return out;
}

void set_experiments(Node** experiments, int& count){
  if(count<1) {
    return;
  }

  Experiment experiment;
  experiment.set_rand();
  (*experiments)->push(experiments, experiment);

  cout << (*experiments)->experiment << *experiments << endl;
  set_experiments(experiments, --count);
}

int find_warm_year(Node* experiments, int min=numeric_limits<int>::max()){

  if(experiments==nullptr){
    cout << "end" << endl;
    return min;
  }

  Experiment experiment = experiments->experiment;
  int month = experiment.date.month;
  bool isWinterMonth = (month==Jan) || (month==Feb) || (month=Dec);
  if(isWinterMonth) {
    if(experiment.minAirTemperature<min) min=experiment.minAirTemperature;
  }

  find_warm_year(experiments->next, min);
};

int main(){
    srand(unsigned(time(0)));

    struct Node* experiments = nullptr;
    Node* begin = experiments;

    int count = 1000;

    Experiment experiment;
    set_experiments(&experiments, count);

    while(experiments->next!=nullptr){
      cout << experiments->experiment << endl;
      experiments = experiments->next;
    }

    cout << endl;
    experiments = begin;

    // cout << endl << find_warm_year(experiments) << endl;

    return 1;
}