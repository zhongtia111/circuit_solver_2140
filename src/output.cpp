// Jayden Tran EECE2140
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "output.h"

using namespace std;

Output::Output(int precision) : precision(precision) {}

string Output::formatValue(double value, const string& unit) const {
    double size = fabs(value);
    double scaled = value;
    string prefix = "";
    if (size != 0 && size < 1e-6) {
        scaled = value * 1e9;
        prefix = "n";
    } else if (size != 0 && size < 1e-3) {
        scaled = value * 1e6;
        prefix = "u";
    } else if (size != 0 && size < 1) {
        scaled = value * 1e3;
        prefix = "m";
    }
    ostringstream text;
    text << fixed << setprecision(precision) << scaled << " " << prefix << unit;
    return text.str();
}

void Output::printResults(const Circuit& circuit, const vector<double>& nodeVoltages,
                          const vector<double>& branchCurrents, const vector<double>& powers) const {
    cout << "\n========== Results ==========\n";
    printNodeVoltages(nodeVoltages);
    cout << "\n";
    printBranchCurrents(circuit, branchCurrents);
    cout << "\n";
    printPower(circuit, powers);
    cout << "=============================\n";
}

void Output::printNodeVoltages(const vector<double>& nodeVoltages) const {
    cout << "Node Voltages\n";
    if (nodeVoltages.size() <= 1) {
        cout << "  (no nodes besides ground)\n";
        return;
    }
    for (size_t i = 1; i < nodeVoltages.size(); i++) {
        cout << "  Node " << left << setw(6) << i << right << setw(14) << formatValue(nodeVoltages[i], "V") << "\n";
    }
}

void Output::printBranchCurrents(const Circuit& circuit, const vector<double>& branchCurrents) const {
    const vector<Component>& components = circuit.getComponents();
    cout << "Branch Currents\n";
    if (branchCurrents.size() != components.size()) {
        cout << "  Error: expected " << components.size() << " currents but got " << branchCurrents.size() << ".\n";
        return;
    }
    for (size_t i = 0; i < components.size(); i++) {
        cout << "  " << left << setw(11) << components[i].getName() << right << setw(14)
             << formatValue(branchCurrents[i], "A") << "\n";
    }
}

void Output::printPower(const Circuit& circuit, const vector<double>& powers) const {
    const vector<Component>& components = circuit.getComponents();
    cout << "Power\n";
    if (powers.size() != components.size()) {
        cout << "  Error: expected " << components.size() << " power values but got " << powers.size() << ".\n";
        return;
    }
    double total = 0;
    for (size_t i = 0; i < components.size(); i++) {
        total += powers[i];
        cout << "  " << left << setw(11) << components[i].getName() << right << setw(14)
             << formatValue(fabs(powers[i]), "W") << (powers[i] >= 0 ? "  absorbed" : "  delivered") << "\n";
    }
    cout << "  " << left << setw(11) << "Net" << right << setw(14) << formatValue(total, "W") << "  (should be 0)\n";
}
