#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;

    bool operator<(const Point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

// 叉积 (b-a) x (c-a)
long long cross(const Point &a, const Point &b, const Point &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }

    // 按题意，先排序
    sort(p.begin(), p.end());

    // 去重（保险起见）
    p.erase(unique(p.begin(), p.end()), p.end());
    n = (int)p.size();

    // 特殊情况
    if (n == 1)
    {
        cout << p[0].x << " " << p[0].y << "\n";
        return 0;
    }
    if (n == 2)
    {
        cout << p[0].x << " " << p[0].y << "\n";
        if (!(p[0] == p[1]))
        {
            cout << p[1].x << " " << p[1].y << "\n";
        }
        return 0;
    }

    // Andrew 单调链
    vector<Point> hull;

    // 下凸壳
    for (int i = 0; i < n; i++)
    {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2], hull[hull.size() - 1], p[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    // 上凸壳
    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; i--)
    {
        while ((int)hull.size() > lowerSize &&
               cross(hull[hull.size() - 2], hull[hull.size() - 1], p[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    // 去掉重复的起点
    if (!hull.empty())
        hull.pop_back();

    // Andrew 返回的是按凸包环顺序，题目要求按 x、y 排序输出
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());

    for (auto &pt : hull)
    {
        cout << pt.x << " " << pt.y << "\n";
    }

    return 0;
}