#include <iostream>
using namespace std;

// ͨ������ ()����� ʵ�����ƺ������õĹ���

struct MyPlust
{
    int operator () (const int& a,const int& b)
    {
        return a+b;
    }
};
