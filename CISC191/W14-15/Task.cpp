// Task.cpp
#include "Task.h"
#include <iostream>

// Default constructor
Task::Task() : id(0), description(""), completed(false) {}

// Parameterized constructor
Task::Task(int id, const string& desc) : id(id), description(desc), completed(false) {}

// Mark the task as completed
void Task::markCompleted() {
    completed = true;
}

// Return whether the task is completed
bool Task::isCompleted() const {
    return completed;
}

// Return the task ID
int Task::getId() const {
    return id;
}

// Return the task description
string Task::getDescription() const {
    return description;
}
