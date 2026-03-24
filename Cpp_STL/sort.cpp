#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector <int> m(10);
    for (int i = 10; i > 0; i--)
        m[10 - i] = i;
    
    for (int i = 0; i < m.size(); i ++)
        cout << m[i] << " ";
    cout << endl;
    
    m.push_back(-1);
    sort(m.begin(), m.end());

    for (int i = 0; i < m.size(); i ++)
        cout << m[i] << " ";
    cout << endl;

    return 0;
}