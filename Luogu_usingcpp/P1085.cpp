#include <iostream>

using namespace std;

int main(void){
	int nums[10], n, m, max_time = -1, max_idx = -1;
	for (int i = 1; i < 8; i++){
		cin >> n >> m;
		nums[i] = n + m;
		if (nums[i] > 8 && nums[i] > max_time){
			max_time = nums[i];
			max_idx = i;
		}
	}
	if (max_idx == -1) cout << "0";
	else cout << max_idx;
	return 0;
}
