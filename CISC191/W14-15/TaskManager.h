// TaskManager.h
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <memory>  // For std::unique_ptr
#include <string>
using namespace std;

class TaskManager {
private:
    unique_ptr<Task[]> tasks;  // unique_ptr to manage task array
    int size;
    int capacity;

public:
    TaskManager(int initialCapacity);  // Constructor declaration

    void addTask(const string& desc);  // Add task declaration
    void removeTask(int id);  // Remove task declaration
    void listTasks() const;  // List tasks declaration
};

#endif  // TASKMANAGER_H
