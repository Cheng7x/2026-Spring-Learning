#include <iostream>
#include <string>

int main()
{
	//std::cout << "Pick 1 or 2" << "\n";
	//int choice{};
	//std::cin >> choice;

	std::cout << "Now enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Hello, " << name << "\n";
	//std::cout << "Your name has " << name.length() << " characters.\n";
	
	int length{ static_cast<int>(name.length()) };

	std::cout << length << " characters.\n";

	std::cout << "Your name has " << std::ssize(name) << " characters.\n";

	return 0;
}