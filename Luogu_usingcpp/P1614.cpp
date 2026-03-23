#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	
	int sum = 0;
	int nmin = 3e5;
	for (int i = 0; i < n; i++) {
		if (i < m) sum += num[i];
		else {
			sum = sum + num[i] - num[i - m];
			if (sum < nmin) nmin = sum;
		}
	}
	cout << nmin;
	return 0;
}
