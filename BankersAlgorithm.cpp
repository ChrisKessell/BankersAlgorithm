#include "BankersAlgorithm.h"
#include <fstream>
#include <iostream>

using namespace std;

bool BankersAlgorithm::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        return false;
    }

    file >> n >> m;

    total.resize(m);
    for (int j = 0; j < m; j++)
        file >> total[j];

    allocation.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            file >> allocation[i][j];

    maximum.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            file >> maximum[i][j];

    cout << "n=" << n << " m=" << m << endl;
    cout << "Total: ";
    for (int j = 0; j < m; ++j) cout << total[j] << " ";
    cout << endl << "Allocation:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << allocation[i][j] << " ";
        cout << endl;
    }
    cout << "Max:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << maximum[i][j] << " ";
        cout << endl;
    }


    file.close();
    return true;
}

void BankersAlgorithm::calculateNeed() {
    need.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

void BankersAlgorithm::calculateAvailable() {
    available.assign(m, 0);
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += allocation[i][j];
        available[j] = total[j] - sum;
    }
}

bool BankersAlgorithm::isSafe(vector<int>& safeSequence) {
    vector<int> work = available;
    vector<bool> finish(n, false);
    safeSequence.clear();

    int finishedCount = 0;
    bool progress = true;

    while (finishedCount < n && progress) {
        progress = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safeSequence.push_back(i);
                    finish[i] = true;
                    finishedCount++;
                    progress = true;
                }
            }
        }
    }

    // if all processes finished -> safe
    for (bool f : finish)
        if (!f) return false;
    return true;
}