#pragma once

template<typename T>
class Singleton
{
public:

    static T* GetInstance()
    {
        // static T instance_;
        return instance_;
    }
private:
    Singleton(){};
    static T* instance_;
};

template <typename T>
T* Singleton<T>::instance_ = new T;
