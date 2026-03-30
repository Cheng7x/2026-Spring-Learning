#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>
using namespace std;

// 返回运算符优先级
int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

// 计算一次
bool calc(stack<double> &num, stack<char> &op)
{
    if (num.size() < 2 || op.empty())
        return false;

    double b = num.top();
    num.pop();
    double a = num.top();
    num.pop();
    char ch = op.top();
    op.pop();

    double res = 0;
    if (ch == '+')
        res = a + b;
    else if (ch == '-')
        res = a - b;
    else if (ch == '*')
        res = a * b;
    else if (ch == '/')
    {
        if (fabs(b) < 1e-12)
            return false; // 防止除0
        res = a / b;
    }
    else
    {
        return false;
    }

    num.push(res);
    return true;
}

int main()
{
    string s, input;

    // 读入整行
    getline(cin, input);

    // 去掉空格
    for (char c : input)
    {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
        {
            s += c;
        }
    }

    // 必须以 # 结束
    if (s.empty() || s.back() != '#')
    {
        cout << "NO";
        return 0;
    }

    // 检查非法字符
    for (char c : s)
    {
        if (!(isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#'))
        {
            cout << "NO";
            return 0;
        }
    }

    stack<double> num;
    stack<char> op;

    int n = s.size();
    for (int i = 0; i < n;)
    {
        char c = s[i];

        if (isdigit(c))
        {
            double val = 0;
            while (i < n && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            num.push(val);
        }
        else if (c == '(')
        {
            op.push(c);
            i++;
        }
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                if (!calc(num, op))
                {
                    cout << "NO";
                    return 0;
                }
            }
            if (op.empty())
            { // 没有匹配的左括号
                cout << "NO";
                return 0;
            }
            op.pop(); // 弹出 '('
            i++;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!op.empty() && op.top() != '(' && priority(op.top()) >= priority(c))
            {
                if (!calc(num, op))
                {
                    cout << "NO";
                    return 0;
                }
            }
            op.push(c);
            i++;
        }
        else if (c == '#')
        {
            while (!op.empty())
            {
                if (op.top() == '(')
                {
                    cout << "NO";
                    return 0;
                }
                if (!calc(num, op))
                {
                    cout << "NO";
                    return 0;
                }
            }

            if (num.size() != 1)
            {
                cout << "NO";
                return 0;
            }

            double ans = num.top();

            // 若结果是整数，则按整数输出
            if (fabs(ans - (long long)ans) < 1e-9)
            {
                cout << (long long)ans;
            }
            else
            {
                cout << fixed << setprecision(6) << ans;
            }
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}