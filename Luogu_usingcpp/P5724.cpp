#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int maxn = -1, minn = 1e5, a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > maxn) maxn = a;
		if (a < minn) minn = a;
	}
	cout << maxn - minn;
	return 0;
}
