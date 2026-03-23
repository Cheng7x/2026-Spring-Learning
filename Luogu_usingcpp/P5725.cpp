#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int m = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%02d", m++);
		}
		printf("\n");
	}
	
	printf("\n");
	
	m = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 2 * (i + 1); j++) printf(" ");
		for (int k = 0; k < i + 1; k++) {
			printf("%02d", m++);	
		}
		printf("\n");
	}
	
	return 0;
}
