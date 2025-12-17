#include <vector>
#include <queue>

using namespace std;

int bfsCoinChange(vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;

    vector<int> d(amount + 1, -1);
    queue<int> q;

    q.push(0);
    d[0] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int coin : coins) {
            int y = x + coin;
            if (y <= amount && d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    return d[amount];
}
