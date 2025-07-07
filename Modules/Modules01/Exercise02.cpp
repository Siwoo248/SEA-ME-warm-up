/*
Encapsulation - 캡슐화 (private, protected, public)
Abstraction - 추상화
Inheritance - 상속
Polymorphism - 다형성 (virtual, override)
Modularity - 모듈화
*/

#include <iostream>
#include <string>
using namespace std;

class ElectricCar {
private:
	string model;
	int year;
	int betteryCapacity;
public:
	ElectricCar(const string& mod="", int y=0, int b=0) : model(mod), year(y), betteryCapacity(b) {
		// constructor
	}
	
	~ElectricCar() {
		// destructor
	}
	
	string getMod() const { return model; }
	int getYear() const { return year; }
	int getBett() const { return betteryCapacity; }
	void setMod(const string& mod) {
		model = mod;
	}
	void setYear(int y) {
		year = y;
	}
	void setBett(int b) {
		betteryCapacity = b;
	}

	virtual void showCar() {
		cout << "Car model: " << getMod() << endl;
		cout << "Car year: " << getYear() << endl;
		cout << "Bettery Capacity: " << getBett() << endl;
	}
};

class SuperCar : public ElectricCar {
private:
	double ztoh;
	int topSpeed;
public:
	SuperCar(const string& mod = "", int y=0, int b=0, double z=0, int t=0) : ElectricCar(mod, y, b), ztoh(z), topSpeed(t) {};
	
	double getZtoh() const { return ztoh; }
	int getTopSpeed() const { return topSpeed; }
	void setZtoh(double z) {
		ztoh = z;
	}
	void setTopSpeed(int t) {
		topSpeed = t;
	}

	void showCar() override {
		/*cout << "Car model: " << model << endl;
		cout << "Car year: " << year << endl;
		cout << "Bettery Capacity: " << betteryCapacity << "kWh" << endl;
		*/
		cout << endl;
		ElectricCar::showCar();
		cout << "Zero to Hundred : " << getZtoh() << " sec" << endl;
		cout << "Top Speed: " << getTopSpeed() << " km/h" << endl;
		cout << endl;
	}
};

int main() {
	ElectricCar A("Ioniq 9", 2025, 110);
	A.showCar();

	SuperCar B("Spectre", 2024, 105, 4.5, 250);
	B.showCar();

	return 0;
}