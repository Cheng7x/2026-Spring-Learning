#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int h, r;
	const double pi = 3.14;
	cin >> h >> r;
	cout << ceil((20 * 1000) / (pi * r * r * h));
	
	return 0;
}
