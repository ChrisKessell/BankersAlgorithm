#ifndef BANKERSALGORITHM_BANKERSALGORITHM_H
#define BANKERSALGORITHM_BANKERSALGORITHM_H

#include <vector>
#include <string>

class BankersAlgorithm {
private:
    int n; // number of processes
    int m; // number of resource types
    std::vector<int> total;
    std::vector<int> available;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> maximum;
    std::vector<std::vector<int>> need;

public:
    bool loadFromFile(const std::string& filename);
    void calculateNeed();
    void calculateAvailable();
    bool isSafe(std::vector<int>& safeSequence);
};

#endif //BANKERSALGORITHM_BANKERSALGORITHM_H