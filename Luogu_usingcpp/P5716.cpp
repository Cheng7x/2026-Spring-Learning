#include <iostream>

using namespace std;

bool isLeapyear(int year){
	if (year % 100 == 0){
		if (year % 400 == 0) return true;
		else return false;
	}
	else{
		if (year % 4 == 0) return true;
		else return false;
	}
}

int main(){
	int y, m;
	cin >> y >> m;
	
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m != 2) cout << days[m - 1];
	else{
		if (isLeapyear(y)) cout << 29;
		else cout << 28;
	}
	
	return 0;
}
