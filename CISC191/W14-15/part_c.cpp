// part_c.cpp - Smart Pointers (std::unique_ptr)

#include <iostream>
#include <string>
#include "TaskManager.h"  // Include the header for TaskManager class
using namespace std;

int getValidInt() {
    int input;
    while (!(cin >> input)) {
        cin.clear();  // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
        cout << "Invalid input! Please enter a valid integer: ";
    }
    return input;
}

int main() {
    int capacity = 5;  // Maximum number of tasks allowed
    TaskManager manager(capacity);  // Create TaskManager with capacity of 5

    int choice;
    do {
        cout << "\nTask Manager Menu\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. List Tasks\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        choice = getValidInt();  // Use the helper function to validate menu choice

        switch (choice) {
            case 1: {
                cin.ignore();  // To ignore newline character left in buffer
                string desc;
                cout << "Enter task description: ";
                getline(cin, desc);
                manager.addTask(desc);  // Add task to the list
                break;
            }
            case 2: {
                cout << "Enter task ID to remove: ";
                int id = getValidInt();  // Use the helper function to validate task ID
                manager.removeTask(id);  // Remove task by ID
                break;
            }
            case 3:
                manager.listTasks();  // List all tasks
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
