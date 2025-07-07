#include<iostream>
#include<string>
using namespace std;

class Car {
protected:
	int make;
	string model;
	int year;
public:
	Car(int m=0, const string& mod="", int y=0) : make(m), model(mod), year(y) {
		// constructor
		cout << "기본 생성자" << endl;
	}
	
	~Car() {
		// destructor
		cout << "소멸자 " << "Car make: " << make << ", Car model: " << model << ", Car Year: " << year << endl;
	}
	
	/*
	Car(const Car& newCar) : name(newCar.name), speed(newCar.speed), year(newCar.year) {
		// copy constructor
		cout << "복사 생성자" << endl;
	}  // 더 추천하는 copy constructor 생성 방법
	*/
	Car(const Car& newCar) {
		// copy constructor
		cout << "복사 생성자" << endl;
		make = newCar.make;
		model = newCar.model;
		year = newCar.year;
	} 

	Car& operator=(const Car& newCar) {
		// copy assignment operator override
		cout << "복사 대입 생성자" << endl;
		if (this == &newCar) return *this;
		make = newCar.make;
		model = newCar.model;
		year = newCar.year;
		return *this;
	}

	void showCar() {
		cout << "Car make: " << make << ", Car model: " << model << ", Car year: " << year << endl << endl;
	}
};

class SportsCar : public Car {
private:
	int topSpeed;
public:
	SportsCar(int m, const string& mod, int y, int topSpeed) : Car(m,mod,y), topSpeed(topSpeed){}
	void drive() {
		cout << "Car make: " << make << ", Car model: " << model << ", Car year: " << year << ", Top Speed: " << topSpeed << "km/h" << endl << endl;
	}
};



int main() {
	Car a;						// 기본 생성자 호출
	a.showCar();

	Car benz(2020, "S-Class", 2025);			// 매개변수 생성자 호출
	benz.showCar();

	Car c = benz;					// 복사 생성자 호출
	c.showCar();

	Car d;						// 복사 개입 연산자 호출
	d = c;
	d.showCar();

	SportsCar bugatti(2024,"Chiron", 2025, 420);
	bugatti.drive();

	return 0;
}