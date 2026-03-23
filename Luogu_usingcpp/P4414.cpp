#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	char i, j, k;
	cin >> i >> j >> k;
	
	int nums[3] = {a, b, c};
	sort(nums, nums + 3);
	cout << nums[i - 65] << " " << nums[j - 65] << " " << nums[k - 65];
	return 0;
}
