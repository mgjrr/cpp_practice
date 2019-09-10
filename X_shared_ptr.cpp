#include <iostream>
using namespace std;
class tc
{
private:
    /* data */
public:
    tc(/* args */);
    ~tc();
};

tc::tc(/* args */)
{
    cout<<"in!"<<endl;
}

tc::~tc()
{
    cout<<"gone!"<<endl;
}

template<typename T>
class X_shared_ptr
{
public:
    T* ori_p;
    unsigned * count_p;
    X_shared_ptr(/* args */);
    X_shared_ptr(T* );
    X_shared_ptr(X_shared_ptr& rhs);
    ~X_shared_ptr();
};

template<typename T>
X_shared_ptr<T>::X_shared_ptr():ori_p(new T),count_p(new unsigned(0)){ }

template<typename T>
X_shared_ptr<T>::X_shared_ptr(T* melo):ori_p(melo),count_p(new unsigned(1)){ }

template<typename T>
X_shared_ptr<T>::X_shared_ptr(X_shared_ptr& rhs)
{   
    ori_p = rhs.ori_p;
    (*rhs.count_p)++;
    count_p = rhs.count_p;
}

template<typename T>
X_shared_ptr<T>::~X_shared_ptr()
{
    (*count_p)--;
    if(!(*count_p))
    {
        delete count_p;
        delete ori_p;
    }
}
void func(X_shared_ptr<tc> & melo)
{
    cout<<"in func "<<*(melo.count_p)<<endl;
    X_shared_ptr<tc> a(melo);
    cout<<"in func "<<*(a.count_p)<<endl;
}
int main(int argc, char const *argv[])
{
    // tc* a = new tc;
    X_shared_ptr<tc> a(new tc);
    cout<<*(a.count_p)<<endl;
    func(a);
    cout<<*(a.count_p)<<endl;
    return 0;
}
