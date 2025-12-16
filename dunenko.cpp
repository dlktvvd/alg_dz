#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> d(amount + 1, -1);
    queue<int> q;

    q.push(0);
    d[0] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            int y = x + coins[i];
            if (y <= amount && d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    cout << d[amount] << endl;

    return 0;
}
