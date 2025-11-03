# Non-Duplicated Integer Array Operations

This program allows the user to enter unique integers, then provides options to sort the array in ascending or descending order or find the largest number. Only `<iostream>` and `<array>` headers are used, and sorting is implemented manually.
### Code
```cpp
// Name: Tam Ho
// Course: CISC 192 - C++ Programming
// Date: 11/02/2025
// Assignment: Non-Duplicated Integer Array Operations

#include <iostream>
#include <array>
using namespace std;

int main() {
    const int arraySize = 5;            // number of integers in the array
    array<int, arraySize> myArray = {}; // store user-input integers
    int temp;                           // temporary variable for input and swaps

    cout << "Enter " << arraySize << " unique integers:\n";

    // input loop — ensures all integers are unique
    for (int i = 0; i < arraySize; i++) {
        bool duplicateFound;
        do {
            duplicateFound = false;
            cout << "Element " << i + 1 << ": ";
            cin >> temp;

            // check for duplicates
            for (int j = 0; j < i; j++) {
                if (myArray[j] == temp) {
                    cout << "Duplicate found! Enter a different number.\n";
                    duplicateFound = true;
                    break;
                }
            }
        } while (duplicateFound);

        myArray[i] = temp;
    }

    // display operation menu
    cout << "\nChoose an operation:\n";
    cout << "1. Sort Ascending\n";
    cout << "2. Sort Descending\n";
    cout << "3. Find Maximum\n";
    cout << "Enter your choice: ";

    int userChoice;
    cin >> userChoice;

    switch (userChoice) {
        case 1: {
            // sort ascending using bubble sort
            for (int i = 0; i < arraySize - 1; i++) {
                for (int j = 0; j < arraySize - i - 1; j++) {
                    if (myArray[j] > myArray[j + 1]) {
                        int temp = myArray[j];
                        myArray[j] = myArray[j + 1];
                        myArray[j + 1] = temp;
                    }
                }
            }

            cout << "\nArray sorted in ascending order:\n";
            for (int i = 0; i < arraySize; i++) {
                cout << myArray[i] << " ";
            }
            cout << endl;
            break;
        }

        case 2: {
            // sort descending using bubble sort
            for (int i = 0; i < arraySize - 1; i++) {
                for (int j = 0; j < arraySize - i - 1; j++) {
                    if (myArray[j] < myArray[j + 1]) {
                        int temp = myArray[j];
                        myArray[j] = myArray[j + 1];
                        myArray[j + 1] = temp;
                    }
                }
            }

            cout << "\nArray sorted in descending order:\n";
            for (int i = 0; i < arraySize; i++) {
                cout << myArray[i] << " ";
            }
            cout << endl;
            break;
        }

        case 3: {
            // find the biggest number
            int biggest = myArray[0];
            for (int i = 1; i < arraySize; i++) {
                if (myArray[i] > biggest) {
                    biggest = myArray[i];
                }
            }

            cout << "\nThe biggest number is: " << biggest << endl;
            break;
        }

        default:
            // handles invalid menu choices entered by the user (anything other than 1-3)
            cout << "Invalid choice! Please run the program again." << endl;
            break;
    }

    return 0;
}
