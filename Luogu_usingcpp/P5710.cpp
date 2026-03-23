#include <iostream>

using namespace std;

int main(void){
	int x;
	cin >> x;
	
	bool f = (x % 2 == 0);
	bool g = (x > 4 && x <= 12);
	
	cout << (f && g) << " " << (f || g) << " " << (f != g) << " " << (!f && !g);
	
	return 0;
	
}
