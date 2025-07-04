#include<iostream>
#include<string>
using namespace std;

class Car {
protected:
    int make;
    string model;
    int year;
public:
    Car(int m = 0, const string& mod = "", int y = 0) : make(m), model(mod), year(y) {}
    void drive() {
        cout << "      Car Driving " << make << " " << model << " " << year << " edition" << endl;
    }
};

class SportsCar : public Car {
public:
    SportsCar(int m = 0, const string& mod = "", int y = 0) : Car(m, mod, y) {}
    void drive() {
        cout << "SportsCar Driving " << make << " " << model << " " << year << " edition" << endl;
    }
};

int main() {
    Car a;
    a.drive();

    SportsCar b(2023, "Ferrari", 2023);
    b.drive();

    Car c = b; // SportsCar 객체를 Car로 복사
    c.drive(); // Car의 drive() 호출

    return 0;
}