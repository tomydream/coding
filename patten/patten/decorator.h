#include <iostream>
using namespace std;



class Wife
{
public:
    virtual ~Wife(){};
    void DoAction()
    {
        cout << "DoAction" <<endl;
    }
};

// 可以直接继承wife
class IDecorator: public Wife
{

public:
    virtual ~IDecorator(){};
    IDecorator(Wife* p) : wife_(p){};
protected:
    Wife* wife_;
};

class DecoratorA : public IDecorator
{
public:
    virtual ~DecoratorA(){};
    DecoratorA(Wife* p):IDecorator(p){};
    void Makeup()
    {
        wife_->DoAction();
        cout << "make_up_a" << endl;
    }
;
};
