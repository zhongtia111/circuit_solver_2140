// Jayden Tran EECE2140
#include <iostream>
#include <string>
#include <vector>
#include "tasks.h"
#include "circuit.h"
#include "validate.h"
#include "output.h"

using namespace std;

Circuit circuit;
vector<double> nodeVoltages;
vector<double> branchCurrents;
vector<double> powers;
bool solved = false;

void task1() { cout << "Not implemented yet\n"; }

void task2() { cout << "Not implemented yet\n"; }

void task3() { cout << "Not implemented yet\n"; }

void task4() {
    Validator validator;
    if (validator.validateCircuit(circuit)) {
        cout << "Circuit is valid.\n";
    } else {
        cout << "Circuit has " << validator.getErrors().size() << " error(s):\n";
        for (const string& error : validator.getErrors()) {
            cout << "  - " << error << "\n";
        }
    }
}

void task5() { cout << "Not implemented yet\n"; }

void task6() {
    if (!solved) {
        cout << "No results yet. Solve the circuit first (option 5).\n";
        return;
    }
    Output output;
    output.printResults(circuit, nodeVoltages, branchCurrents, powers);
}

void task7() {
    circuit = Circuit();
    circuit.addComponent(Component("V1", 'V', 1, 0, 10.0));
    circuit.addComponent(Component("R1", 'R', 1, 2, 1000.0));
    circuit.addComponent(Component("R2", 'R', 2, 0, 2000.0));
    circuit.addComponent(Component("R3", 'R', 2, 0, 2000.0));
    solved = false;
    cout << "Loaded example circuit:\n";
    cout << "  V1 1 0 10\n";
    cout << "  R1 1 2 1000\n";
    cout << "  R2 2 0 2000\n";
    cout << "  R3 2 0 2000\n";
}
