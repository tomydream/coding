#include <iostream>
using namespace std;

// 通过重载 ()运算符 实现类似函数调用的过程

struct MyPlust
{
    int operator () (const int& a,const int& b)
    {
        return a+b;
    }
};
