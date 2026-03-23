#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	
	int Local = 5 * n;
	int Luogu = 3 * n + 11;
	
	cout << (Local > Luogu ? "Luogu": "Local");
	return 0;
}
