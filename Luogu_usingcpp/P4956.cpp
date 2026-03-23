#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	// x + 3k = a
	int a = n / (52 * 7);
	for (int i = 100; i > 0; i--) {
		for (int j = 1; j < n; j++) {
			if (i + 3 * j == a) {
				cout << i << endl << j;
				return 0;
			}
		}
	}
}
