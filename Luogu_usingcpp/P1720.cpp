#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	cout << fixed << setprecision(2) << (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
	
}
