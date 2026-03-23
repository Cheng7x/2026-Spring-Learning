#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    set <int> s;

    s.insert(1);
    s.insert(5);
    s.insert(6);

    for (auto p = s.begin(); p != s.end(); p++)
        cout << *p << " ";

    cout << endl;
    cout << (s.find(2) != s.end()) << endl;
    cout << (s.find(5) != s.end()) << endl;

    s.erase(1);

    cout << (s.find(1) != s.end()) << endl;

    return 0;
}