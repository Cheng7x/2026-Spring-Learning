#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{
    bitset <8> b("10101010");
    cout << b << endl;

    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";

    cout << endl;
    
    // 是否有 1
    cout << "does 1 exist: " << b.any() << endl;
    // 是否不存在 1
    cout << "does 1 not exist: " << b.none() << endl;
    // 1 的个数
    cout << "count of 1: " << b.count() << endl;
    // 元素个数
    cout << "element of b: " << b.size() << endl;
    // 下标为 i 的元素是不是 1
    cout << b.test(0) << endl;

    unsigned long a = b.to_ulong();
    unsigned long long c = b.to_ullong();

    cout << a << endl;
    cout << c << endl;

    // 字符串切片
    string m = "0110101";
    bitset <5> b0(m, 0, 5);

    cout << b0 << endl;

    return 0;
}