// Jayden Tran EECE2140
#include <iostream>
#include "circuit.h"

using namespace std;

Component::Component(const string& name, char type, int nodeA, int nodeB, double value)
    : name(name), type(type), nodeA(nodeA), nodeB(nodeB), value(value) {}

string Component::getName() const { return name; }

char Component::getType() const { return type; }

int Component::getNodeA() const { return nodeA; }

int Component::getNodeB() const { return nodeB; }

double Component::getValue() const { return value; }

void Component::print() const {
    cout << "  " << name << " " << nodeA << " " << nodeB << " " << value << "\n";
}

Circuit::Circuit() : numNodes(0) {}

void Circuit::addComponent(const Component& component) {
    components.push_back(component);
    if (component.getNodeA() > numNodes) {
        numNodes = component.getNodeA();
    }
    if (component.getNodeB() > numNodes) {
        numNodes = component.getNodeB();
    }
}

const vector<Component>& Circuit::getComponents() const { return components; }

int Circuit::getNodeCount() const { return numNodes; }

void Circuit::print() const {
    if (components.empty()) {
        cout << "No circuit loaded.\n";
        return;
    }
    cout << "Circuit with " << components.size() << " component(s) and " << numNodes << " node(s) besides ground:\n";
    for (const Component& component : components) {
        component.print();
    }
}
