// Circuit Solver - main menu
// EECE 2140 Team 02

#include <iostream>
using namespace std;

void loadFromFile() {
    cout << "Load netlist from file: not implemented yet" << endl;
}

void enterFromTerminal() {
    cout << "Enter netlist from terminal: not implemented yet" << endl;
}

void displayCircuit() {
    cout << "Display current circuit: not implemented yet" << endl;
}

void validateCircuit() {
    cout << "Validate circuit: not implemented yet" << endl;
}

void solveCircuit() {
    cout << "Solve circuit: not implemented yet" << endl;
}

void displayResults() {
    cout << "Display results: not implemented yet" << endl;
}

void loadExample() {
    cout << "Load example circuit: not implemented yet" << endl;
}

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
                loadFromFile();
                break;
            case 2:
                enterFromTerminal();
                break;
            case 3:
                displayCircuit();
                break;
            case 4:
                validateCircuit();
                break;
            case 5:
                solveCircuit();
                break;
            case 6:
                displayResults();
                break;
            case 7:
                loadExample();
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
