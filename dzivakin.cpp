#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int coinChangeRecursive(vector<int>& coins, int amount, int index) {
    if (amount == 0) {
        return 0; 
    }
    if (amount < 0 || index >= coins.size()) {
        return -1;
    }
    
    int minCoins = INT_MAX;
    bool found = false;
    
    int maxCount = amount / coins[index];
    
    for (int count = 0; count <= maxCount; count++) {
        int remaining = amount - count * coins[index];

        int result = coinChangeRecursive(coins, remaining, index + 1);
        
        if (result != -1) {
            minCoins = min(minCoins, count + result);
            found = true;
        }
    }
    
    return found ? minCoins : -1;
}

int bruteForceCoinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    
    return coinChangeRecursive(coins, amount, 0);
}

