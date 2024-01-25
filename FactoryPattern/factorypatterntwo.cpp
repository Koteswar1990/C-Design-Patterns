#include <iostream>
#include<memory>

using namespace std;

enum TypeCar{
    FORD,
    SWIFT,
    TATA,
    TOGG,
};

class car{
    public:
    virtual void drive() = 0;
     static std::unique_ptr<car>createCar(TypeCar);
};

class Ford : public car{
    public:
    void drive(){
        cout<<"Ford car"<<endl;
    }
};

class Swift : public car{
    public:
    void drive(){
        cout<<"swift car"<<endl;
    }
};

class Tata : public car{
    public:
    void drive(){
        cout<<"tata car"<<endl;
    }
};
class Togg : public car{
    public:
     void drive(){
        cout<<"togg car"<<endl;
     }
};
std::unique_ptr<car> car::createCar(TypeCar instance)
{
      std::unique_ptr<car>m_car;
    if(instance == FORD){
        m_car = std::make_unique<Ford>();
    }
    else if(instance == SWIFT) {
        m_car = std::make_unique<Swift>();
    }
    else if(instance == TATA) {
        m_car = std::make_unique<Tata>();
    }
    else{
        m_car = std::make_unique<Togg>();
    }
    return m_car;
}

class CarOrder{
    public:
     CarOrder(TypeCar orderType){
      m_car = car::createCar(orderType);
    }
    std::unique_ptr<car>getCar(){
        return std::move(m_car);
    }
    private:
    std::unique_ptr<car>m_car;
};

int main()
{
    CarOrder m_carOrder{FORD};
    std::unique_ptr<car> m_car = m_carOrder.getCar();
    m_car->drive();
    return 0;

}

