// Jayden Tran EECE2140
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>
#include <vector>

class Component {
private:
    std::string name;
    char type;
    int nodeA;
    int nodeB;
    double value;

public:
    Component(const std::string& name, char type, int nodeA, int nodeB, double value);
    std::string getName() const;
    char getType() const;
    int getNodeA() const;
    int getNodeB() const;
    double getValue() const;
    void print() const;
};

class Circuit {
private:
    std::vector<Component> components;
    int numNodes;

public:
    Circuit();
    void addComponent(const Component& component);
    const std::vector<Component>& getComponents() const;
    int getNodeCount() const;
    void print() const;
};

#endif
