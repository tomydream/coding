#include "singleton.h"
class TestSingleton
{
    friend class Singleton<TestSingleton>;
    TestSingleton(){};
    TestSingleton(const TestSingleton&);
    TestSingleton& operator=(const TestSingleton&);
public:
    int a{0};
};
