#include <iostream>

int main()
{
	std::cout << "Enter an integer: " << std::endl;
	int num{};
	std::cin >> num;

	std::cout << "Double that number is: " << num * 2 << std::endl;

	return 0;
}