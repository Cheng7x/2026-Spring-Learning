#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b(n, 0);
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) cnt++;
		}
		b[i] = cnt;
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
