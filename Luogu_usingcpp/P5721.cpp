#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int num = 1;
	for (int i = n; i > 0; i--){
		for (int j = i; j > 0; j--){
			printf("%02d", num);
			num++;
		}
		printf("\n");
	}
	return 0;
}
