#include <iostream>
#include <cctype>

int main(void){
	char c;
	std::cin >> c;
	
	std::cout << static_cast<char>(std::toupper(c));
	
	return 0;
}