#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int a;
	while (cin >> a && a != 0) {
		v.push_back(a);
	}
	
	for (int i = (int)v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	return 0;
}
