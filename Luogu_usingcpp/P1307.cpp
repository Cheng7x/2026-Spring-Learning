#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	bool negative;
	if (n < 0) {
		negative = true;
		n = -n;
	}
	
	int rev = 0;
	while (n > 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	
	if (negative) cout << -rev;
	else cout << rev;
	return 0;
}
