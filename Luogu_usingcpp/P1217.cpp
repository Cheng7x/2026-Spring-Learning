#include <iostream>

using namespace std;

const int MAXN = 1e8 + 5;
int prime[MAXN];
bool is_composite[MAXN];

int eular_sieve(int n) {
	int p = 0;
	for (int i = 2; i <= n; i++) {
		if (!is_composite[i]) 
			prime[p++] = i;
		
		for (int j = 0; j < p && i * prime[j] <= n; j++) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	return p;
}

bool reverse(int n) {
	int x = n, rev = 0;
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev == n;
}

int main(void) {
	int a, b;
	cin >> a >> b;
	eular_sieve(b + 1);
	for (int i = a; i <= b; i++)
		if (reverse(i) && !is_composite[i]) cout << i << endl;
	return 0;
}
