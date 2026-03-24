#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a = stoi("123");
    
    cout << a - 1 << endl;

    double b = stod("12.34");

    cout << b - 2 << endl;

    return 0;
}