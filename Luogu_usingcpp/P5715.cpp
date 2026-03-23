#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	
//	if (a > b) swap(a, b);
//	if (a > c) swap(a, c);
//	if (b > c) swap(b, c);
//	
//	cout << a << " " << b << " " << c;
	
	int num[3] = {a, b, c};
	sort(num, num + 3);
	cout << num[0] << " " << num[1] << " " << num[2];
	
	return 0;
} 
