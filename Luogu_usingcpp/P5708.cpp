#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main(void){
	double a, b, c, p, s;
	cin >> a >> b >> c;
	p =  (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("%.1lf", s);
	
	return 0;       
}
