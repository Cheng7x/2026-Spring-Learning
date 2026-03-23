#include <iostream>
using namespace std;

bool reverse(int& n) {
	int rev = 0, x = n;
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev == n;
}

bool isPrime(int& n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


int main(void){
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (reverse(i) && isPrime(i)) cout << i << endl;
	}
	return 0;
}
