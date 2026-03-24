#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue <int> s;

    for (int i = 1; i <= 10; i++)
        s.push(i);
    
        cout << "The first is " << s.front() << endl << "The end is " << s.back() << endl;

    return 0;
}