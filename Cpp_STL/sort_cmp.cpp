#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int x, int y)
{
    return x > y; // 按从大到小排序
}

int main(void)
{
    vector<int> v;

    for (int i = 1; i <= 10; i++)
        v.push_back(11 - i);

    sort(v.begin(), v.end(), cmp);

    for (auto p = v.begin(); p != v.end(); p++)
        cout << *p << " ";

    cout << endl;

    return 0;
}