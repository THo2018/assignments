// TaskManager.cpp
#include "TaskManager.h"
#include <iostream>

TaskManager::TaskManager(int initialCapacity)
    : tasks(make_unique<Task[]>(initialCapacity)), size(0), capacity(initialCapacity) {}

void TaskManager::addTask(const string& desc) {
    if (size < capacity) {
        tasks[size] = Task(size + 1, desc);  // Add task to the array using unique_ptr
        size++;
        cout << "Task added: " << desc << "\n";
    } else {
        cout << "Task array is full! Cannot add more tasks.\n";
    }
}

void TaskManager::removeTask(int id) {
    bool found = false;
    if (size == 0) {
        cout << "No tasks to remove. The task list is empty.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (tasks[i].getId() == id) {
            found = true;
            // Shift tasks left to maintain order
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
}

void TaskManager::listTasks() const {
    if (size == 0) {
        cout << "No tasks available.\n";
    } else {
        for (int i = 0; i < size; i++) {
            cout << "Task " << tasks[i].getId() << ": " << tasks[i].getDescription() << "\n";
        }
    }
}
