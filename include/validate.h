// Jayden Tran EECE2140
#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>
#include <vector>
#include "circuit.h"

class Validator {
private:
    std::vector<std::string> errors;
    void checkNodes(const Circuit& circuit);
    void checkNames(const Circuit& circuit);

public:
    bool validateCircuit(const Circuit& circuit);
    bool hasGroundNode(const Circuit& circuit);
    bool checkValues(const Circuit& circuit);
    const std::vector<std::string>& getErrors() const;
};

#endif
