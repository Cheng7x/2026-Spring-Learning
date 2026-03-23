#include <iostream>
using namespace std;

int main(void){
	int k;
	cin >> k;
	double n = 1, s = 0;
	while (s < k){
		s += 1.0 / n;
		n++;
	}
	cout << n;
	return 0;
}
