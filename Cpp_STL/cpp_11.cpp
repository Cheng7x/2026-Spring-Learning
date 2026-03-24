#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> a(10, 1);

    for (auto p = a.begin(); p != a.end(); p++)
        cout << *p << " ";

    cout << endl;

    int b[5] = {1}; // 1 0 0 0 0
    
    for (int i:b) // 等价于 py 中的 for i in b
    {
        i++;
        cout << i << " "; // 值传递
    }

    cout << endl;

    vector<int> c(10, 5);
    for(auto i:c)
        cout << i << " ";

    cout << endl;

    int d[5] = {1,2,3,4,5};
    for (int &i:d)
        cout << i * 2 << " ";

    cout << endl;

    
    return 0;

}