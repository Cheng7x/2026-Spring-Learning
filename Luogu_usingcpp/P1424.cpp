#include <iostream>

using namespace std;

int main(void){
	int x, n;
	int ans = 0;
	cin >> x >> n;
	for (int i = 0; i < n; i++){
		if (x >= 1 && x <= 5) ans += 250;
		x = (x + 1) % 7;
	}
	cout << ans;
	return 0;
}
