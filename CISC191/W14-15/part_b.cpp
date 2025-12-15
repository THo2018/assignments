// part_b.cpp - Dynamic Memory Using Raw Pointers (new/delete)

#include <iostream>
#include <string>
#include <limits>  // For numeric_limits
#include "Task.h"  // Include the header for Task class
using namespace std;

int main() {
    int capacity = 5;  // Maximum number of tasks allowed
    int size = 0;

    Task* tasks = new Task[capacity];  // Dynamically allocate memory for tasks array

    int choice;
    do {
        cout << "\nTask Manager Menu\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. List Tasks\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        // Input validation loop
        while (!(cin >> choice)) {
            cin.clear();  // Clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards invalid input
            cout << "Invalid input! Please enter a valid number (1-4): ";
        }

        switch (choice) {
            case 1: {
                cin.ignore();  // To ignore newline character left in buffer
                string desc;
                cout << "Enter task description: ";
                getline(cin, desc);
                tasks[size] = Task(size + 1, desc);  // Add task to the list
                size++;
                cout << "Task added: " << desc << "\n";
                break;
            }
            case 2: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < size; i++) {
                    if (tasks[i].getId() == id) {
                        found = true;
                        for (int j = i; j < size - 1; j++) {
                            tasks[j] = tasks[j + 1];
                        }
                        size--;
                        cout << "Task " << id << " removed.\n";
                        break;
                    }
                }
                if (!found) {
                    cout << "Task with ID " << id << " not found.\n";
                }
                break;
            }
            case 3:
                for (int i = 0; i < size; i++) {
                    cout << "Task " << tasks[i].getId() << ": " << tasks[i].getDescription() << "\n";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    delete[] tasks;  // Free the dynamically allocated memory
    return 0;
}
