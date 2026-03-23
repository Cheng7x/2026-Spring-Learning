#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	int max_num = max({a, b, c});
	int min_num = min({a, b, c});
	int mid_num = a + b + c - max_num - min_num;
	
	if (min_num + mid_num <= max_num){
		cout << "Not triangle" << endl;
		return 0;
	}
	if (min_num * min_num + mid_num * mid_num == max_num * max_num){
		cout << "Right triangle" << endl;
	}
	if (min_num * min_num + mid_num * mid_num < max_num * max_num){
		cout << "Acute triangle" << endl;
	}
	if (min_num * min_num + mid_num * mid_num > max_num * max_num){
		cout << "Obtuse triangle" << endl;
	}
	if (min_num == mid_num){
		cout << "Isosceles triangle" << endl;
	}
	if (a == b && a == c) cout << "Equilateral triangle" << endl;
	return 0;
}
