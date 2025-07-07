#include<iostream>
#include<string>
using namespace std;

class Car {
private:
	string name;
	int speed;
public:
	Car(const string& n = "", int s = 0) : name(n), speed(s) {
		// constructor
		cout << "기본 생성자" << endl;
	}
	
	~Car() {
		// destructor
		cout << "소멸자 " << "Car name: " << name << ", Car speed: " << speed << endl;
	}
	
	/*
	Car(const Car& newCar) : name(newCar.name), speed(newCar.speed) {
		// copy constructor
		cout << "복사 생성자" << endl;
	}  // 더 추천하는 copy constructor 생성 방법
	*/
	Car(const Car& newCar) {
		// copy constructor
		cout << "복사 생성자" << endl;
		name = newCar.name;
		speed = newCar.speed;
	} 

	Car& operator=(const Car& newCar) {
		// copy assignment operator override
		cout << "복사 대입 생성자" << endl;
		if (this == &newCar) return *this;
		name = newCar.name;
		speed = newCar.speed;
		return *this;
	}

	void showCar() {
		cout << "Car name: " << name << ", Car speed: " << speed << endl;
	}
};

int main() {
	Car a;						// 기본 생성자 호출
	a.showCar();

	Car b("BMW", 220);			// 매개변수 생성자 호출
	b.showCar();

	Car c("BENZ", 210);			// 매개변수 생성자 호출
	c.showCar();

	Car d = b;					// 복사 생성자 호출
	d.showCar();

	Car e;						// 복사 개입 연산자 호출
	e = c;
	e.showCar();

	return 0;
}