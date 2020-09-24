#include <iostream>

class Vehicle{
protected:
    int id_;
    static int total_;
public:
    Vehicle(){
        id_ +total_++;
    }
    virtual void make() = 0;
};
int Vehicle::total_ = 0;

class Car : public Vehicle{
public:
    void make(){
        std::cout << "Car " << id_ << ": drive" << std::endl;
    }
};

class Plane : public Vehicle{
public:
    void make(){
        std::cout << "Plane " << id_ << ": drive" << std::endl;
    }
};

class Bike : public Vehicle{
public:
    void make(){
        std::cout << "Bike " << id_ << ": drive" << std::endl;
    }
};

class Rocket : public Vehicle{
public:
    void make(){
        std::cout << "Rocket " << id_ << ": drive" << std::endl;
    }
};

class Factory{
public:
    virtual Vehicle* createGroundInstance() = 0;
    virtual Vehicle* createAirInstance() = 0;
};

class Factory1: public Factory{
public:
    Vehicle* createGroundInstance(){
        return new Car;
    }
    Vehicle* createAirInstance(){
        return new Plane;
    }
};

class Factory2 : public Factory{
public:
    Vehicle* createGroundInstance(){
        return new Bike;
    }
    Vehicle* createAirInstance(){
        return new Bike;
    }
};

int main() {

    Factory* factory = new Factory1;
    Factory* factory1 = new Factory2;

    Vehicle* vehicles[3];

    vehicles[0] = factory->createAirInstance();
    vehicles[1] = factory->createGroundInstance();
    vehicles[2] = factory->createAirInstance();

    for (int i=0; i < 3; i++) {
        vehicles[i]->make();
    }

}

