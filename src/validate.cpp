// Jayden Tran EECE2140
#include <set>
#include <sstream>
#include "validate.h"

using namespace std;

bool Validator::validateCircuit(const Circuit& circuit) {
    errors.clear();
    if (circuit.getComponents().empty()) {
        errors.push_back("Circuit is empty. Load a netlist first.");
        return false;
    }
    hasGroundNode(circuit);
    checkValues(circuit);
    checkNodes(circuit);
    checkNames(circuit);
    return errors.empty();
}

bool Validator::hasGroundNode(const Circuit& circuit) {
    for (const Component& c : circuit.getComponents()) {
        if (c.getNodeA() == 0 || c.getNodeB() == 0) {
            return true;
        }
    }
    errors.push_back("No ground node. At least one component must connect to node 0.");
    return false;
}

bool Validator::checkValues(const Circuit& circuit) {
    bool ok = true;
    for (const Component& c : circuit.getComponents()) {
        char type = c.getType();
        if (type != 'R' && type != 'V' && type != 'I') {
            errors.push_back(c.getName() + ": unknown component type '" + string(1, type) + "' (use R, V, or I).");
            ok = false;
        } else if (type == 'R' && c.getValue() <= 0) {
            ostringstream message;
            message << c.getName() << ": resistance must be greater than 0 ohms (got " << c.getValue() << ").";
            errors.push_back(message.str());
            ok = false;
        }
    }
    return ok;
}

void Validator::checkNodes(const Circuit& circuit) {
    for (const Component& c : circuit.getComponents()) {
        if (c.getNodeA() < 0 || c.getNodeB() < 0) {
            errors.push_back(c.getName() + ": node numbers cannot be negative.");
        } else if (c.getNodeA() == c.getNodeB()) {
            errors.push_back(c.getName() + ": both ends connect to node " + to_string(c.getNodeA()) + ".");
        }
    }
}

void Validator::checkNames(const Circuit& circuit) {
    set<string> seen;
    for (const Component& c : circuit.getComponents()) {
        if (!seen.insert(c.getName()).second) {
            errors.push_back(c.getName() + ": name is used more than once.");
        }
    }
}

const vector<string>& Validator::getErrors() const {
    return errors;
}
