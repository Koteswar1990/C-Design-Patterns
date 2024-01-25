#include <iostream>

using namespace std;

class Singleton{
    Singleton(){

    }
    static Singleton* instance;
    public:
    static Singleton* getInstance();
    void testMethod();
    static Singleton* destroyInstance();
    
};

Singleton* Singleton::instance = nullptr;

void Singleton::testMethod()
{
    cout<<"test method in singleton"<<endl;
    cout<<"testInstance"<<instance<<endl;
}

Singleton* Singleton::getInstance()
{
    if(instance == nullptr){
        instance = new Singleton();
        return instance;
    }
}

Singleton* Singleton::destroyInstance(){
    delete instance;
    instance= nullptr;
    cout<<"testInstance"<<instance<<endl;
}

int main()
{
    Singleton* obj = Singleton::getInstance();
    obj->testMethod();

    obj->destroyInstance();

    return 0;
}