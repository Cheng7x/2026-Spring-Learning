#include <iostream>
#include "List.h"
using namespace std;

// 读取一个多项式
void readPoly(SeqList &poly, int n)
{
    for (int i = 0; i < n; i++)
    {
        Term t;
        cin >> t.coef >> t.exp;
        poly.push_back(t);
    }
}

// 多项式加法
SeqList addPoly(const SeqList &A, const SeqList &B)
{
    SeqList C;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size())
    {
        Term a = A.get(i);
        Term b = B.get(j);

        if (a.exp == b.exp)
        {
            int sum = a.coef + b.coef;
            if (sum != 0)
            {
                Term t;
                t.coef = sum;
                t.exp = a.exp;
                C.push_back(t);
            }
            i++;
            j++;
        }
        else if (a.exp > b.exp)
        {
            C.push_back(a);
            i++;
        }
        else
        {
            C.push_back(b);
            j++;
        }
    }

    // 把剩余项加入结果
    while (i < A.size())
    {
        C.push_back(A.get(i));
        i++;
    }

    while (j < B.size())
    {
        C.push_back(B.get(j));
        j++;
    }

    return C;
}

int main()
{
    SeqList A, B, C;
    int n, m;

    cin >> n;
    readPoly(A, n);

    cin >> m;
    readPoly(B, m);

    C = addPoly(A, B);

    C.print();

    return 0;
}