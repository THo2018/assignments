// part_a.cpp - Raw Pointers to Stack Objects

#include <iostream>
#include "Task.h"  // Include the header for Task class
using namespace std;

int main() {
    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    // Raw pointers to stack objects
    Task* p1 = &t1;
    Task* p2 = &t2;

    // Demonstrate pointer dereferencing
    cout << "Task 1: " << p1->getDescription() << "\n";
    cout << "Task 2: " << p2->getDescription() << "\n";

    // Mark task as completed using pointer
    p1->markCompleted();
    cout << "Task 1 completion status: " << (p1->isCompleted() ? "Completed" : "Not Completed") << "\n";

    return 0;
}
