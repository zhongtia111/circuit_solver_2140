// Jayden Tran EECE2140
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>
#include "circuit.h"

class Output {
private:
    int precision;
    std::string formatValue(double value, const std::string& unit) const;

public:
    Output(int precision = 3);
    void printResults(const Circuit& circuit, const std::vector<double>& nodeVoltages,
                      const std::vector<double>& branchCurrents, const std::vector<double>& powers) const;
    void printNodeVoltages(const std::vector<double>& nodeVoltages) const;
    void printBranchCurrents(const Circuit& circuit, const std::vector<double>& branchCurrents) const;
    void printPower(const Circuit& circuit, const std::vector<double>& powers) const;
};

#endif
