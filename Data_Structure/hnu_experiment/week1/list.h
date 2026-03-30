#ifndef LIST_H
#define LIST_H

const int MAXSIZE = 210; // 最多 100+100 项，留够空间

// 多项式的一项：coef * x^exp
struct Term
{
    int coef; // 系数
    int exp;  // 指数
};

// 顺序线性表
class SeqList
{
private:
    Term data[MAXSIZE];
    int length;

public:
    SeqList();

    void clear();
    int size() const;
    bool empty() const;

    bool push_back(const Term &t);
    Term get(int index) const;

    void print() const;
};

#endif