#include <iostream>
using namespace std;

int main(void){
	int a;
	cin >> a;
	int day = 0;
	while (a != 0){
		a = a / 2;
		day++;
	}
	
	cout << day;
	return 0;
}
