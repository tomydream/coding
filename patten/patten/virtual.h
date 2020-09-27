
class Base
{
public:
    Base(){};
    ~Base(){};

    void func1(){};
    virtual void func2(){};
};


class Derive: public Base
{
public:
    Derive(){};
    ~Derive(){};

    virtual void func2(){};
    void func3(){};
};
