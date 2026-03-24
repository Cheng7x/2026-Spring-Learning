#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    map<string, int> m;

    m["hello"] = 2;
    m["world"] = 3;

    // cout << m["hello"] << endl;
    for (auto p = m.begin(); p != m.end(); p++)
        cout << p->first << ": " << p->second << endl;

    cout << "the length of map: " << m.size() << endl;

    return 0;
    // map 按 key 的 ASCII 排序
}