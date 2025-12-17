#include <vector>
#include <algorithm>

using namespace std;

int rec(int sum, vector<int>& coins, vector<int>& memo, int INF)
{
    if (sum < 0) return INF;
    if (sum == 0) return 0;

    if (memo[sum] != -1) return memo[sum];

    int best = INF;
    for (int coin : coins)
    {
        int cur = rec(sum - coin, coins, memo, INF);
        if (cur + 1 < best) best = cur + 1;
    }

    memo[sum] = best;
    return best;
}

int recursiveCoinChange(vector<int>& coins, int amount)
{
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (coins.empty()) return -1;

    int INF = amount + 1;

    vector<int> memo(amount + 1, -1);

    int ans = rec(amount, coins, memo, INF);
    return (ans >= INF) ? -1 : ans;
}


