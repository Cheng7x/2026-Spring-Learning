#include <iostream>
using namespace std;

int main(void) {
	int s;
	cin >> s;
	double a = 2.0;
	int sum = 0, ans = 0;
	while (sum < s) {
		ans++;
		sum += a;
		a *= 0.98;
	}
	cout << ans;
	return 0;
}
