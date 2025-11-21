#include <iostream>
#include "BankersAlgorithm.h"

using namespace std;

int main() {
    BankersAlgorithm banker;
    if (!banker.loadFromFile("input.txt"))
        return 1;

    banker.calculateNeed();
    banker.calculateAvailable();

    vector<int> safeSequence;
    if (banker.isSafe(safeSequence)) {
        cout << "System is in a safe state.\nSafe sequence: ";
        for (size_t i = 0; i < safeSequence.size(); i++) {
            cout << "P" << safeSequence[i];
            if (i != safeSequence.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "System is not in a safe state." << endl;
    }

    return 0;
}