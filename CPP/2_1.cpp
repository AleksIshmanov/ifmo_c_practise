#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Написать программу, создающую массив из 10 случайных целых чисел из отрезка [-50;50]. Вывести на экран весь массив и на отдельной строке — значение минимального элемента массива.

Для обхода массива использовать указатели (запрещено обращаться к элементам массива по индексам).
*/
int main(){
    srand(unsigned(time(0)));
    
    int arr[10];
    int min = -50;
    int max = 50;
    int minToPrint;
    
    for(int i=0;i<10;i++){
        *(arr+i) = abs(rand()%max)-(rand()%min);
        if( *(arr+i) < *(arr) ){
            minToPrint = *(arr+i);
        }
        cout << *(arr+i) << " ";
    }
    cout << endl;
    
    cout << "Minimal value: " << minToPrint << endl;
    
    return 1;
}