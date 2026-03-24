#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector <int> v(10, 2);

    v.resize(20);

    for (auto p = v.begin(); p != v.end(); p++)
        cout << *p << " ";
}
