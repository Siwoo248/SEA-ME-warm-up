#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int speed;

public:
    // 매개변수 기본값을 가진 생성자
    Car(const string& n = "", int s = 0) : name(n), speed(s) {
        cout << "Constructor called                   (name: " << name << ", speed: " << speed << ")" << endl;
    }

    // 복사 생성자
    Car(const Car& other) : name(other.name), speed(other.speed) {
        cout << "Copy constructor called              (name: " << name << ", speed: " << speed << ")" << endl;
    }

    // 복사 대입 연산자
    Car& operator=(const Car& other) {
        cout << "Copy assignment operator called      (name: " << name << ", speed: " << speed << ")" << endl;
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    // 소멸자
    ~Car() {
        cout << "Destructor called                    (name: " << name << ", speed: " << speed << ")" << endl;
    }

    // 출력 함수
    void display() const {
        cout << "Car name: " << name << ", speed: " << speed << endl;
    }
};


int main() {
    Car a;                  // 기본 생성자 호출
    a.display();

    Car b("BMW", 220);      // 매개변수 생성자 호출
    b.display();

    Car c = b;              // 복사 생성자 호출
    c.display();

    Car d;                  // 기본 생성자 호출
    d = b;                  // 복사 대입 연산자 호출
    d.display();

    return 0;               // main 종료 시 소멸자들이 호출됨
}
