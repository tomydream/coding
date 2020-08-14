#pragma once

#include <vector>
#include <string>
using namespace std;
class IObserver
{
public:
    IObserver(){};
    virtual ~IObserver(){};
    virtual void OnMsg(const std::string& msg) = 0;
};

class INotifier
{
public:
    INotifier(){};
    virtual ~INotifier(){};

    virtual void Attach(IObserver* observer) = 0;
    virtual void Dettach(IObserver* observer) = 0;
    virtual void Notify(const string & msg) = 0;
};

class Observer:public IObserver
{
public:
    Observer(){};
    virtual ~Observer(){};
    virtual void OnMsg(const std::string& msg) {cout << msg <<endl;}
};

class Notifier:public INotifier
{
public:
    Notifier(){};
    virtual ~Notifier(){};

    virtual void Attach(IObserver* observer)
    {
        vec_.push_back(observer);
    }
    virtual void Dettach(IObserver* observer)
    {
        return;
    }
    virtual void Notify(const string & msg)
    {
        for(auto observer : vec_){
            observer->OnMsg(msg);
        }
    }
private:
    vector<IObserver*> vec_;
};
