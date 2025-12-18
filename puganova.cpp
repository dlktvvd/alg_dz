#include <iostream>
#include <vector>
#include <chrono>

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

    vector<vector<int>> allCoins = {
        {1, 2, 5, 10, 20, 50},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 7, 13, 24, 31, 45, 57, 65, 79, 89, 92, 105, 120},
        {10, 20, 50},
        {1},
        {1, 2, 5, 10, 20, 50, 140, 230, 450, 790, 940, 1080, 2800, 4300, 5700  }
    };

    vector<int> amounts = { 220, 50, 500, 37, 500, 15000 };

    for (int testNum = 0; testNum < 7; testNum++) {
        cout << "Test " << (testNum + 1) << ": coins = {";

        vector<int> coins = allCoins[testNum];
        int amount = amounts[testNum];

        for (int j = 0; j < coins.size(); j++) {
            cout << coins[j];
            if (j < coins.size() - 1) cout << ", ";
        }

        cout << "}, amount = " << amount << "\n";

        for (int algNum = 0; algNum < 5; algNum++) {
            Alg a = algs[algNum];
            vector<int> copy = coins;

            const int REPEAT = 1000;

            auto start = high_resolution_clock::now();
            int result = 0;

            for (int r = 0; r < REPEAT; r++) {
                vector<int> temp = copy;
                result = a.func(temp, amount);
            }

            auto end = high_resolution_clock::now();
            auto total_time = duration_cast<microseconds>(end - start);
            int avg_time = total_time.count() / REPEAT;  // целое число

            cout << "    " << a.name << " (" << a.student << "): "
                << avg_time << "mcs, result=" << result << "\n";
        }
        cout << endl;
    }

    return 0;
}