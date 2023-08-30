#include <iostream>

 

class Vehicle {
public:
    virtual void start() {
        std::cout << "Vehicle starting..." << std::endl;
    }

 

    virtual void stop() {
        std::cout << "Vehicle stopping..." << std::endl;
    }

 

    virtual void drive() {
        std::cout << "Vehicle driving..." << std::endl;
    }
};

 

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "Car starting..." << std::endl;
    }

 

    void stop() override {
        std::cout << "Car stopping..." << std::endl;
    }

 

    void drive() override {
        std::cout << "Car driving..." << std::endl;
    }
};

 

class Bus : public Vehicle {
public:
    void start() override {
        std::cout << "Bus starting..." << std::endl;
    }

 

    void stop() override {
        std::cout << "Bus stopping..." << std::endl;
    }

 

    void drive() override {
        std::cout << "Bus driving..." << std::endl;
    }
};

 

class Truck : public Vehicle {
public:
    void start() override {
        std::cout << "Truck starting..." << std::endl;
    }

 

    void stop() override {
        std::cout << "Truck stopping..." << std::endl;
    }

 

    void drive() override {
        std::cout << "Truck driving..." << std::endl;
    }
};

 

int main() {
    Car car;
    Bus bus;
    Truck truck;

 

    car.start();
    car.drive();
    car.stop();

 

    std::cout << std::endl;

 

    bus.start();
    bus.drive();
    bus.stop();

 

    std::cout << std::endl;

 

    truck.start();
    truck.drive();
    truck.stop();

 

    return 0;
}