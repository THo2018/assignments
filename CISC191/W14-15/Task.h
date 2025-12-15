// Task.h
#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    int id;
    string description;
    bool completed;

public:
    Task();  // Default constructor
    Task(int id, const string& desc);  // Parameterized constructor

    void markCompleted();  // Method to mark task as completed
    bool isCompleted() const;  // Method to check if task is completed
    int getId() const;  // Method to get task ID
    string getDescription() const;  // Method to get task description
};

#endif  // TASK_H
