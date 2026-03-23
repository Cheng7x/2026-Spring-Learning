#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int curr, prev = -1, cnt = 1, mcnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		if (curr == prev + 1) {
			cnt++;
			if (cnt > mcnt) mcnt = cnt;
		}
		else cnt = 1;
		prev = curr;
	}
	cout << mcnt;
	return 0;
}
