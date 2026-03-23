#include <iostream>
#include <stack>
#include <string>

void conversion(int N, int base){
	std::stack<char> result;
	do{
		int remainder = N % base;
		char d = remainder < 10 ? '0' + remainder : 'a' + remainder - 10;
		result.push(d);
		N /= base;
	} while(N > 0);
	
	while (!result.empty()){
		std::cout << result.top();
		result.pop();
	}
	std::cout << "\n";
}

int main(void)
{
	conversion(-8, 2);
	return 0; 
}
