#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num){
	for (int i = 2; i < num / 2 + 2; i++){
		if (num == 2) return true;
		if (num % i == 0) return false;
	}
	return true;
}

int main(void){
	int l;
	cin >> l;
	int weight = 0, count = 0;
	for (int i = 2; i < 100000; i++){
		if (isPrime(i)){
			if (i <= l - weight){
				weight += i;
				count++;
				cout << i << endl;
			}
			else break;
		}
		
	}
	cout << count << endl;
	return 0;
}
