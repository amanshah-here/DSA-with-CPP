#include<iostream>
#include<string>
#include<queue>
using namespace std;

// Employee class for priority queue demonstration
class Employee {
public:
    string name;
    unsigned int age;

    // Constructor to initialize employee details
    Employee(string name, unsigned int age) {
        this->name = name;
        this->age = age;
    }

    // Overload operator for min-heap (reverse comparison based on age)
    bool operator < (const Employee& obj) const {
        return this->age > obj.age;
    }
};

int main() {
    // Create a priority queue for Employee objects
    priority_queue<Employee> pq;

    // Insert employees into the priority queue
    pq.push(Employee("Aman", 20));
    pq.push(Employee("Kishan", 24));
    pq.push(Employee("Shristi", 19));
    pq.push(Employee("Nitin", 22));

    // Extract and display all employees in priority order (ascending age)
    while (!pq.empty()) {
        cout << "Top: " << pq.top().name << ", " << pq.top().age << endl;
        pq.pop();
    }

    return 0;
}