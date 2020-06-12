#include <stdio.h>

void move(int n, int from, int to){

	printf("Перемещаем диск %d с %d на %d\n", n, from, to);

}

void moveTower( int count, int start, int finish, int towerTmp){
	if(count ==0) 
		return;

	moveTower(count-1, start, towerTmp, finish); //перемещаем N-1 дисков с 1 
	move(count, start, finish);
	moveTower(count-1, towerTmp, start, finish);
}

int main(){
	int n;
	printf("N: ");
	scanf("%d", &n);

	moveTower(n,1,3,2);

	return 0;
}
