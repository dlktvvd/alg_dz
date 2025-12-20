#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;
using namespace chrono;

int greedyCoinChange(vector<int>& coins, int amount);
int dpCoinChange(vector<int>& coins, int amount);
int recursiveCoinChange(vector<int>& coins, int amount);
int bfsCoinChange(vector<int>& coins, int amount);
int bruteForceCoinChange(vector<int>& coins, int amount);

int main() {
    struct Alg {
        string name;
        string student;
        int (*func)(vector<int>&, int);
    };

    Alg algs[] = {
        {"Greedy", "Bogunova", greedyCoinChange},
        {"DP", "Lashenova", dpCoinChange},
        {"Recursive", "Agliullin", recursiveCoinChange},
        {"BFS", "Dunenko", bfsCoinChange},
        {"BruteForce", "Ivakin", bruteForceCoinChange}
    };

    vector<int> coins1 = { 1, 5, 10, 20, 50 };
    int amount1 = 1000;

    vector<int> coins2 = { 1, 2, 3, 4,  5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    int amount2 = 100;

    vector<int> coins3 = { 1, 2, 9, 17, 23, 65, 72, 81 };
    int amount3 = 1000;

    vector<int> coins4 = { 10, 20, 30 };
    int amount4 = 39;

    vector<int> coins5 = { 1 };
    int amount5 = 5000;

    vector<int> coins6 = { 1, 1000, 2000, 3000, 5000 };
    int amount6 = 20000;

    vector<pair<vector<int>, int>> tests = {
        {coins1, amount1},
        {coins2, amount2},
        {coins3, amount3},
        {coins4, amount4},
        {coins5, amount5},
        {coins6, amount6},
    };

    
    for (int i = 0; i < tests.size(); i++) {
        cout << "Test " << (i + 1) << ": coins = {";

        vector<int> coins = tests[i].first;
        for (int j = 0; j < coins.size(); j++) {
            cout << coins[j];
            if (j < coins.size() - 1) cout << ", ";
        }

        cout << "}, amount = " << tests[i].second << "\n";

        for (Alg a : algs) {
            vector<int> copy = coins;
            auto start = high_resolution_clock::now();
            int result = a.func(copy, tests[i].second);
            auto end = high_resolution_clock::now();
            auto time = duration_cast<microseconds>(end - start);

            cout << "    " << a.name << " (" << a.student << "): "
                << time.count() << "mcs, result=" << result << "\n";
        }
        cout << endl;
    }

    return 0;
}