#include <iostream>
using namespace std;

int main(void){
	int k;
	cin >> k;
	int n = 1, ans = 0, day = 1;
	for (int i = 1; i < k + 1; i++){
		if (day > 0) 
			day--;
		else{
			n++;
			day = n;
		}
		ans += n;
	}
	cout << ans;
	return 0;
}
