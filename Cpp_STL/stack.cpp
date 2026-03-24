#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack <int> s;

    s.push(1);
    s.push(5);
    s.push(77);

    cout << s.top() << endl;

    s.pop();

    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}