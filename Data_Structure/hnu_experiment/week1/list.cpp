#include <iostream>
#include "List.h"
using namespace std;

SeqList::SeqList()
{
    length = 0;
}

void SeqList::clear()
{
    length = 0;
}

int SeqList::size() const
{
    return length;
}

bool SeqList::empty() const
{
    return length == 0;
}

bool SeqList::push_back(const Term &t)
{
    if (length >= MAXSIZE)
        return false;
    data[length++] = t;
    return true;
}

Term SeqList::get(int index) const
{
    return data[index];
}

void SeqList::print() const
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i].coef << " " << data[i].exp << endl;
    }
}