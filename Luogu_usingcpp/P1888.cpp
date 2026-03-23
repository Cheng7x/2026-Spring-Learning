#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	int nums[3] = {a, b, c};
	sort(nums, nums + 3);
	cout << nums[0] << "/" << nums[2];
	return 0;
}
