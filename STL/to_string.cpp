#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s = to_string(123.1);

    cout << s << endl;

    printf("%s\n", s.c_str());

    return 0;
}