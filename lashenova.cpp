#include <vector>
#include <climits>

using namespace std;

int dpCoinChange(vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;

    vector<int> dp(amount + 1, INT_MAX - 1);

    dp[0] = 0;

    for (int currentSum = 1; currentSum <= amount; currentSum++) {
        for (int coin : coins) {
            if (coin <= currentSum) {
                dp[currentSum] = min(dp[currentSum], dp[currentSum - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX - 1) {
        return -1;
    }
    return dp[amount];
}

