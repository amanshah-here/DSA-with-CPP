#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Student: small POD to hold name and marks.
class Student {
public:
    string name; // student's name
    int marks;   // student's marks (not used for ordering here)

    // Simple constructor
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Define ordering used by priority_queue.
    // Here we compare by `name` (lexicographic). 
    bool operator < (const Student& obj) const {
        return this->name < obj.name;
    }
};

int main() {
    // Default priority_queue 
    priority_queue<Student> pq;

    // Push a few students into the queue.
    pq.push(Student("Aman", 90));
    pq.push(Student("Shristi", 93));
    pq.push(Student("Kishan", 86));

    // Pop and print until empty. Each loop prints the current top element
    // (the student with the lexicographically largest name) and removes it.
    while (!pq.empty()) {
        cout << "Top: " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}