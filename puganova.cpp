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
    string files[] = { "test1.txt", "test2.txt", "test3.txt",
                      "test4.txt", "test5.txt", "test6.txt", "test7.txt" };

    struct Alg { string name; string student; int (*func)(vector<int>&, int); };
    Alg algs[] = {
        {"Greedy", "Bogunova", greedyCoinChange},
        {"DP", "Lashenova", dpCoinChange},
        {"Recursive", "Agliullin", recursiveCoinChange},
        {"BFS", "Dunenko", bfsCoinChange},
        {"BruteForce", "Ivakin", bruteForceCoinChange}
    };

    for (string file : files) {
        ifstream f(file);
        string line;
        getline(f, line);

        vector<int> coins;
        stringstream ss(line);
        int coin;
        while (ss >> coin) coins.push_back(coin);

        int amount;
        f >> amount;

        cout << "File: " << file << " (amount=" << amount
            << ", coins=" << coins.size() << ")\n";

        for (Alg a : algs) {
            vector<int> copy = coins;
            auto start = high_resolution_clock::now();
            int result = a.func(copy, amount);
            auto end = high_resolution_clock::now();
            auto time = duration_cast<microseconds>(end - start);

            cout << "    " << a.name << " (" << a.student << "): "
                << time.count() << "mcs, result=" << result << "\n";
        }
        cout << endl;
    }

    return 0;
}