#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
	int n, a1, a2, b1, b2, c1, c2;
	cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	
	int p1 = ceil(1.0 * n / a1) * a2;
	int p2 = ceil(1.0 * n / b1) * b2;
	int p3 = ceil(1.0 * n / c1) * c2;
	
	cout << min({p1, p2, p3});
	return 0;
}
