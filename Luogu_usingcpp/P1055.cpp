#include <iostream>

using namespace std;

int main(void){
	char s[20];
	cin >> s;
	
	int sum = 0, k = 1;
	for (int i = 0; i < 12; i++){
		if (s[i] != '-'){
			sum += (s[i] - '0') * k;
			k++;
		}
	}
	
	int t = sum % 11;
	char check;
	if (t == 10) check = 'X';
	else check = t + '0';
	
	if (check == s[12]){
		cout << "Right";
	}
	else {
		s[12] = check;
		cout << s;
	}
	
	return 0;
}
