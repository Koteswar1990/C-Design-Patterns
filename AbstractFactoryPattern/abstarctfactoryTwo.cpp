#include <iostream>
#include <memory>

using namespace std;

class Vehicle
{
    public:
    virtual void startEngine() =0;
    virtual void getReady() =0;
};

class Aircraft : public Vehicle
{
    public:
      void startEngine()
      {
        cout<<"aircraft started engine"<<endl;
      }
      void getReady(){
        cout<<"aircraft getReady for Operation"<<endl;
      }
};

class Drone : public Vehicle
{
    public:
    void startEngine()
      {
        cout<<"drone started engine"<<endl;
      }
      void getReady(){
        cout<<"drone getReady for Operation"<<endl;
      }
};

class Car : public Vehicle
{
    public:
      void startEngine()
      {
        cout<<"car started engine"<<endl;
      }
      void getReady(){
        cout<<"car getReady for Operation"<<endl;
      }
};

class Truck : public Vehicle
{
       public:
      void startEngine()
      {
        cout<<"truck started engine"<<endl;
      }
      void getReady(){
        cout<<"truck getReady for Operation"<<endl;
      }
};

class Factory
{
    public:
     virtual unique_ptr<Vehicle> createSmallVehicle() =0;
     virtual unique_ptr<Vehicle> createBigVehicle() =0;
};

class FlyingTypeVehicle : public Factory
{
    public:
      unique_ptr<Vehicle> createBigVehicle()
      {
        return make_unique<Aircraft>();
      }
      unique_ptr<Vehicle> createSmallVehicle()
      {
        return make_unique<Drone>();
      }
};

class GroundTypeVehicle : public Factory
{
    public:
      unique_ptr<Vehicle> createBigVehicle()
      {
        return make_unique<Truck>();
      }
      unique_ptr<Vehicle> createSmallVehicle()
      {
        return make_unique<Car>();
      }
};

int main()
{
    unique_ptr<Factory> m_factory = make_unique<FlyingTypeVehicle>();

    m_factory->createBigVehicle()->getReady();
    m_factory->createBigVehicle()->startEngine();

    m_factory->createSmallVehicle()->getReady();
    m_factory->createSmallVehicle()->startEngine();

    return 0;
}
