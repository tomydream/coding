#include <iostream>
#include "TestSingleton.h"
#include "observer.h"
#include "decorator.h"
#include "functors.h"
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

    MyPlust my_plus;
    cout << "my_plus:" << my_plus(3,5) << endl;
    cout << "my_plus��ʾ����:" << MyPlust()(3,5) << endl;
    cout << "my_plus��ʾ����:" << my_plus.operator()(3,5) << endl;
    return 0;
}
