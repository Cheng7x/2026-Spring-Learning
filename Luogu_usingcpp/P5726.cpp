#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	
	int sum = 0, maxn = -1, minn = 11;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > maxn) maxn = a;
		if (a < minn) minn = a;
		sum += a;
	}
	double ans = (1.0 * sum - maxn - minn) / (n - 2);
	cout << fixed << setprecision(2) << ans;
	return 0;
}
