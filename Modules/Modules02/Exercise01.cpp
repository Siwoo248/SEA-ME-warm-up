#include<iostream>
#include<string>
#include<memory>
using namespace std;


int cnt_wheel = 1;
int cnt_brake = 1;
int index = 0;
int brake_index = 0;
// 속도 60km/h 기준
char transmission[8] = { '1','2','3','4','5','6','R','N' };
int engine_rpm[8] = { 5000,3500,2500,1900,1500,1200,2500,800 };
int wheel_speed[8] = { 320,384,435,463,457,450,174,0 };
int brake_temp[8] = { 0,50,100,150,200,250,300,350 };

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
    virtual ~Part() {}
};

class Transmission : public Part {
public:
    void upGear() {
        if (index < 5) {
            index++;
            if (brake_index > 0) {
                brake_index--;
            }
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
            if (brake_index > 7) {
                cout << "Brake is TOO HOT" << endl;
                brake_index = 7;
            }
            else {
                brake_index++;
            }
        }
        else if (index == 6 || index == 7) {
            index = 0;
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
        brake_index++;
    }
    void print() override {
        cout << "Transmission part\n";
        cout << "Current Transmission level: " << transmission[getIndex()];
        cout << "\n";
    }
    int getIndex() const { return index; }
    int getBrake_Index() const { return brake_index; }
};

class Engine : public Part {
private:
    Transmission* transmission_;
public:
    Engine(Transmission* t) : transmission_(t) {}

    void print() override {
        cout << "Engine part\n";
        cout << "Current Engine RPM: " << engine_rpm[transmission_->getIndex()];
        cout << "\n";
    }
};

class Wheel : public Part {
private:
    Transmission* transmission_;
public:
    Wheel(Transmission* t) : transmission_(t) {}

    void print() override {
        cout << "Wheel part\n";
        cout << "Current Wheel Spin RPM: " << wheel_speed[transmission_->getIndex()];
        cout << "\n";
    }

    void check() {
        cout << "Wheel " << cnt_wheel << " part CHECK \n";
        cnt_wheel++;
    }
};

class Brake : public Part {
private:
    Transmission* transmission_;
public:
    Brake(Transmission* t) : transmission_(t) {}

    void print() override {
        cout << "Brake part\n";
        cout << "Current Brake Temperture: " << brake_temp[transmission_->getBrake_Index()];
        cout << "\n";
    }

    void check() {
        cout << "Brake "<< cnt_brake << " part CHECK \n";
        cnt_brake++;
        cout << "\n";
    }
};

class Car {
public:
    Car() {
        transmission_ = new Transmission();
        engine_ = new Engine(transmission_);
        for (int i = 0; i < 4; ++i) {
            wheels_[i] = new Wheel(transmission_);
            brakes_[i] = new Brake(transmission_);
        }
    }

    void checkParts() {
        cout << "Checking wheels & brakes ~" << endl;
        for (int i = 0; i < 4; ++i) {
            wheels_[i]->check();
            brakes_[i]->check();
        }
    }

    void printParts() {
        cout << endl;
        transmission_->print();
        engine_->print();
        wheels_[1]->print();
        brakes_[1]->print();
    }

    ~Car() {
        delete engine_;
        delete transmission_;
        for (int i = 0; i < 4; ++i) {
            delete wheels_[i];
            delete brakes_[i];
        }
    }

    Engine* engine_;
    Wheel* wheels_[4];
    Brake* brakes_[4];
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
            myCar.printParts();
        }
        else if (gear == "down") {
            myCar.transmission_->downGear();
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