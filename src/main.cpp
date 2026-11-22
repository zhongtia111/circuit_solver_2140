// Circuit Solver - main menu
// EECE 2140 Team 02

#include <iostream>
#include "tasks.h"
using namespace std;

void showMenu() {
    cout << endl;
    cout << "=== Circuit Solver ===" << endl;
    cout << "1. Load netlist from file" << endl;
    cout << "2. Enter netlist from terminal" << endl;
    cout << "3. Display current circuit" << endl;
    cout << "4. Validate circuit" << endl;
    cout << "5. Solve circuit" << endl;
    cout << "6. Display results" << endl;
    cout << "7. Load example circuit" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number." << endl;
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
