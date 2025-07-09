#include<iostream>
#include<string>
#include<memory>
using namespace std;

int index = 0;

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
    virtual ~Part() {}
    // Getter
    int getIndex() const { return index; }
};

class Transmission : public Part {
private:
    char transmission[8] = { '1','2','3','4','5','6','R','N' };
public:
    void upGear() {
        if (index < 5) {
            index++;
        }
        else if (index == 5) {
            cout << "You Can`t Increase Gear ! (Current Gear = 6)" << endl;
        }
        else if (index == 6 || index == 7) {
            index = 1;
        }
    }
    void downGear() {
        if (index > 0 && index < 6) {
            index--;
        }
        else if (index == 6 || index == 7) {
            cout << "You Can`t Decrease Gear when Gear N / Gear R" << endl;
        }
        else if (index == 0) {
            cout << "You Can`t Decrease Gear ! (Current Gear = 1)" << endl;
        }
    }
    void GearNeutral() {
        index = 7;
    }
    void GearReverse() {
        index = 6;
    }
    void print() override {
        cout << "Transmission part\n";
        cout << "Current Transmission level: " << transmission[getIndex()];
        cout << "\n";
    }
};

class Engine : public Part {
private:
    int engine_rpm[8] = { 5000,3500,2500,1900,1500,1200,2500,800 };

public:
    void print() override {
        cout << "Engine part\n";
        cout << "Current Engine RPM: " << engine_rpm[getIndex()];
        cout << "\n";
    }
};

class Wheel : public Part {
private:
    int cnt_wheel = 1;
    int wheel_speed[8] = { 320,384,435,463,457,450,174,0 };
public:
    void print() override {
        cout << "Wheel part\n";
        cout << "Current Wheel Spin RPM: " << wheel_speed[getIndex()];
        cout << "\n";
    }

    void check() {
        cout << "Wheel " << cnt_wheel << " part CHECK \n";
        cnt_wheel++;
    }
};

class Brake : public Part {
private:
    int cnt_brake = 1;
    int brake_index = 0;
    int brake_temp[8] = { 0,50,100,150,200,250,300,350 };
public:

    int getBrake_Index() const { return brake_index; }

    void print() override {
        cout << "Brake part\n";
        cout << "Current Brake Temperture: " << brake_temp[getBrake_Index()];
        cout << "\n";
    }

    void check() {
        cout << "Brake " << cnt_brake << " part CHECK \n";
        cnt_brake++;
        cout << "\n";
    }

    void brake_on() {
        if (brake_index < 7) {
            brake_index++;
        }
        else if (brake_index == 7) {
            cout << "Break is TOO HOT !" << endl;
        }
    }

    void brake_off() {
        if (brake_index > 0) {
            brake_index--;
        }
    }
};

class Car {
public:
    Car() {
        transmission_ = new Transmission();
        engine_ = new Engine();
        wheels_ = new Wheel();
        brakes_ = new Brake();
    }

    void checkParts() {
        cout << "Checking wheels & brakes ~" << endl;
        for (int i = 0; i < 4; ++i) {
            wheels_->check();
            brakes_->check();
        }
    }

    void printParts() {
        cout << endl;
        transmission_->print();
        engine_->print();
        wheels_->print();
        brakes_->print();
    }

    ~Car() {
        delete engine_;
        delete transmission_;
        delete wheels_;
        delete brakes_;
    }

    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};

int main() {
    Car myCar;
    myCar.checkParts();
    myCar.printParts();

    while (true) {
        cout << endl;
        cout << "up : gear up, down : gear down, n : neutral gear, r : reverse gear, now : see current gear (-1 to exit): ";
        string gear;
        cin >> gear;
        if (gear == "up") {
            myCar.transmission_->upGear();
            myCar.brakes_->brake_off();
            myCar.printParts();
        }
        else if (gear == "down") {
            myCar.transmission_->downGear();
            myCar.brakes_->brake_on();
            myCar.printParts();
        }
        else if (gear == "n") {
            myCar.transmission_->GearNeutral();
            myCar.printParts();
        }
        else if (gear == "r") {
            myCar.transmission_->GearReverse();
            myCar.printParts();
        }
        else if (gear == "now") {
            myCar.printParts();
        }
        else if (gear == "-1") {
            break;
        }
        else {
            cout << "ONLY USE   up / down / n / r / now / -1" << endl;
            cout << endl;
        }
    }

    return 0;
}