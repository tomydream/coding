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

    // ����ͨ����ֵ����unique_ptr
    // std::unique_ptr<Task> taskptr2 = new Task(3);

    // ����ͨ��ԭʼָ�봴��unique_ptr
    std::unique_ptr<Task> taskptr(new Task(3));

    // ֱ�ӷ��ʳ�Ա������
    cout << "ֱ�ӷ������ݳ�Ա:" <<taskptr->id_ << endl;
    // reset ָ��
    cout << "resetָ��" << endl;
    if(taskptr == nullptr){
        cout<< "taskptr is null"<< endl;
    }
    // ת��
    std::unique_ptr<Task> taskptr2 (new Task(4));
    std::unique_ptr<Task> taskptr3 = std::move(taskptr2);
    if(taskptr2 == nullptr){
        cout << "taskptr2ת�ƺ�Ϊ��" << endl;
    }
    if(taskptr3 != nullptr){
        cout << "taskptr3ת�Ժ�Ϊ��:" << taskptr3->id_ << endl;
    }

    std::unique_ptr<Task> taskptr5(new Task(66));
    Task* ptr = taskptr5.release();
    cout << "�ͷ�taskptr5��,ptr:" << ptr->id_ <<endl;
    delete ptr;

    return;
}
