#include <iostream>
#include <memory>

using namespace std;

class Car
{
    public:
     virtual void produceComponent() =0;
};

class marutiGearEngine : public Car
{
    public:
    void produceComponent(){
        cout<<"marutiGearEngine component"<<endl;
    }
};

class marutiAutoTrans : public Car
{
    public:
    void produceComponent(){
        cout<<"marutiAuto Trans Engine"<<endl;
    }
};

class fordGearEngine : public Car
{
    public:
    void produceComponent(){
        cout<<"fordGearEngine component"<<endl;
    }
};

class fordAutoTrans : public Car
{
    public:
    void produceComponent(){
        cout<<"fordAuto Trans Engine"<<endl;
    }
};

class Factory
{
    public:
     virtual unique_ptr<Car> GearEngineComponent() =0;
     virtual unique_ptr<Car> AutoTransComponent() =0;
};

class MarutiFactory : public Factory
{
    public:
    unique_ptr<Car> GearEngineComponent(){
        return std::make_unique<marutiGearEngine>();
    }
    unique_ptr<Car> AutoTransComponent() {
        return std::make_unique<marutiAutoTrans>();
    }
};

class FordFactory : public Factory
{
    public:
    unique_ptr<Car>GearEngineComponent(){
        return std::make_unique<fordGearEngine>();
    }
    unique_ptr<Car>AutoTransComponent(){
        return std::make_unique<fordAutoTrans>();
    }
};

int main()
{
    std::unique_ptr<Factory>m_factory = make_unique<MarutiFactory>();

    m_factory->GearEngineComponent()->produceComponent();
    m_factory->AutoTransComponent()->produceComponent();

    return 0;
}

