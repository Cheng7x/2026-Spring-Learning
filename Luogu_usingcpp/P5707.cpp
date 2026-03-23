#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	double s, v;
	cin >> s >> v;
	int time = (ceil(s / v) + 10);
	time = (32 * 60 - time) % (24 * 60);
	int hour = time / 60;
	int minute = time % 60;
	printf("%02d:%02d", hour, minute);
	/* 需要使用 iomanip 库
	cout << setfill('0') << setw(2) << hour << ":" 
		<< setfill('0') << setw(2) << minute;
	*/
	return 0;
}
