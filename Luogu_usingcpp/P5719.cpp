#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;
	int nsum = 0, ksum = 0, ncount = 0, kcount = 0;
	for (int i = 1; i < n + 1; i++){
		if (i % k == 0) ksum += i, kcount++;
		else nsum += i, ncount++;
	}
	// cout << fixed << setprecision(1) << ksum * 1.0 / kcount << " " << fixed << setprecision(1) << nsum * 1.0 / ncount;
	printf("%.1f %.1f", ksum * 1.0 / kcount, nsum * 1.0 / ncount);
	return 0;
}
