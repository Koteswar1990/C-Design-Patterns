#include <iostream>>

using namespace std;

class Car{
    public:
     virtual void drive() = 0;
};

class Renult : public Car{
    public:
       void drive(){
        cout<<"Renault car"<<endl;
       }
};

class Swift : public Car{
    public:
     void drive(){
        cout<<"Swift car"<<endl;
     }
};

class Ford : public Car {
    public:
    void drive(){
        cout<<"Ford Car"<<endl;
    }
};

class CarFactory{
    public:
     enum CarType{RENULT,SWIFT,FORD,NONE};

     Car* CreateCar(CarType instance){
        if(instance == RENULT){
            return new Renult();
        }
        else if(instance == SWIFT){
            return new Swift();
        }
        else if(instance == FORD) {
            return new Ford();
        }
        throw std::runtime_error("Type is not specfied in the factory");
        return nullptr;
     }
};

int main()
{
    CarFactory factory;
    CarFactory::CarType type=CarFactory::CarType::FORD;

    Car* m_ford = factory.CreateCar(type);
    m_ford->drive();

    return 0;
}