#include <iostream>
#include <string>
using namespace std;

class Sensor {
private:
    static int counter;   // for auto ID generation.
    /*"A static variable is declared inside a class, 
	but initialized outside to ensure that only one copy of it exists 
	and is shared among all objects of that class.
	-Mean if there are 10 objects, counter variable will only one.
	-Inside Class=Variable declare only. 
	-outside Class=Memory will be allocate.
	-why Static? Because common for all objects */
    int sensorID;
    string type;
    string status;

public:
    // Default Constructor
    Sensor() {
        counter++;			// increment when object create
        sensorID = counter;
        type = "Generic";
        status = "Offline";
    }

    // Parameterized Constructor
    Sensor(string t, string s) {
        counter++;			//increment when object create.
        //behave common variable for default and parameterized constructor.
        sensorID = counter;
        type = t;
        status = s;
    }

    // Function to display sensor info
    void displaySensor() {
        cout << "Sensor ID  : " << sensorID << endl;
        cout << "Type       : " << type << endl;
        cout << "Status     : " << status << endl;
        cout << "-----------------------------" << endl;
    }
};

/*-Initialize static variable, only definition, allocate memory
-Create one global copy of the static variable counter for the class Sensor
,and set its initial value to 0.Without it, your program will give this error 
-the variable counter belongs to the class Sensor, not to any single object.
Example:
Class = School
Static variable = School bell
You only install one bell in the whole school,not one in each classroom.
So you write outside the class where that bell is placed and first installed.*/
int Sensor::counter = 0;

int main() {

    // Using Default Constructor
    Sensor s1;				//counter=1
    Sensor s2;				//counter=2

    // Using Parameterized Constructor
    Sensor s3("Temperature", "Online");		//counter=3
    Sensor s4("Pressure", "Offline");		//counter=4
    Sensor s5("Humidity", "Online");		//counter=5

    cout << "IoT Sensor Monitoring System\n";
    cout << "=============================\n";

    s1.displaySensor();
    s2.displaySensor();
    s3.displaySensor();
    s4.displaySensor();
    s5.displaySensor();

    return 0;
}
/* Static Variable 
A static variable is a variable that:
-Belongs to the class, not to individual objects
-Has only one copy for all objects
-Keeps its value shared and updated among all objects.
-Each time an object is created, increase static counter.
-Static variable remembers the total.
-Value of static variable does not reset when objects are destroyed.
-It stays until the program ends.
-We use static variables to store common data shared among all objects and to save memory.*/
