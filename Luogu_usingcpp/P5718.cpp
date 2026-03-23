#include <iostream>

using namespace std;

int main(void){
	int n, ai;
	int minimum = 1001;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ai;
		if (ai < minimum) minimum = ai;
	}
	cout << minimum;
	return 0;
}
