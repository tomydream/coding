#include <iostream>
#include <memory>
using namespace std;

struct Task{
    int id_;
    Task(int id):id_(id){
        cout << "Task constructor" << endl;
    }
    ~Task(){
        cout << "Task destructor" << endl;
    }
};

void TestPointer()
{
    std::unique_ptr<int> ptr1;
    if(ptr1 == nullptr){
        cout << "ptr1 null" <<endl;
    }

    // 不能通过赋值创建unique_ptr
    // std::unique_ptr<Task> taskptr2 = new Task(3);

    // 可以通过原始指针创建unique_ptr
    std::unique_ptr<Task> taskptr(new Task(3));

    // 直接访问成员的数据
    cout << "直接访问数据成员:" <<taskptr->id_ << endl;
    // reset 指针
    cout << "reset指针" << endl;
    if(taskptr == nullptr){
        cout<< "taskptr is null"<< endl;
    }
    // 转移
    std::unique_ptr<Task> taskptr2 (new Task(4));
    std::unique_ptr<Task> taskptr3 = std::move(taskptr2);
    if(taskptr2 == nullptr){
        cout << "taskptr2转移后为空" << endl;
    }
    if(taskptr3 != nullptr){
        cout << "taskptr3转以后不为空:" << taskptr3->id_ << endl;
    }

    std::unique_ptr<Task> taskptr5(new Task(66));
    Task* ptr = taskptr5.release();
    cout << "释放taskptr5后,ptr:" << ptr->id_ <<endl;
    delete ptr;

    return;
}
