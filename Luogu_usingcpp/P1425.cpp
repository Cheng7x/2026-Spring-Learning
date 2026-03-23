#include <iostream>

using namespace std;

int main(void){
	int a, b, c ,d;
	cin >> a >> b >> c >> d;
	int minutes = c * 60 + d - a * 60 - b;
	cout << minutes / 60 << " " << minutes % 60;
	
	return 0;
}
