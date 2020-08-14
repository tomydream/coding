#include <iostream>
#include "TestSingleton.h"
#include "observer.h"
#include "decorator.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << Singleton<TestSingleton>::GetInstance().a <<endl;

    auto* ntf = new Notifier();
    auto* ob = new Observer();

    ntf->Attach(ob);
    ntf->Notify("hello");

    auto* wife = new Wife();
    auto* da = new DecoratorA(wife);
    da->Makeup();
    return 0;
}
