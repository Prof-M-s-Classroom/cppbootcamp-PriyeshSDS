#include <iostream>
#include <set>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    Robot(string  n, string m, int b):name(n),model(m),batteryLife(b) {}

    // Getter Methods
    string getName() {return name;}
    string getModel() {return model;}
    int getBatteryLife() {return batteryLife;}


    // Setter Methods
    void setBatteryLife(int b){batteryLife=b;}
    void setName(string s){name=s;}
    void setModel(string m){model = m;}


    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
void modifyRobotByValue(Robot r) {
    r.setBatteryLife(100);
}


// Step 3: Function to modify robot (pass by reference)
void modifyRobotByReference(Robot &r) {
    r.setBatteryLife(90);
}

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot myRobot("Bob","Roomba",50);



    // Step 6: Use pointers to access Robot object
    Robot* robotPtr = &myRobot;

   // cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotByValue(myRobot);
   // cout << "After modifyRobotByValue, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    modifyRobotByReference(myRobot);
   // cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.addRobot("Roomba");
    myFleet.showFleet();



    return 0;
}