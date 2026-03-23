#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	cin >> n;
	float pay;
	if (n <= 150) pay += n * 0.4463;
	if (n > 150 && n <= 400) pay += 150 * 0.4463 + (n - 150) * 0.4663;
	if (n > 400) pay += 150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663;
	cout << fixed << setprecision(1) << pay;
	return 0;
}
