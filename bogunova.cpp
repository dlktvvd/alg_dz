#include <vector>
#include <algorithm>

using namespace std;

int greedyCoinChange(vector<int>& coins, int amount) {
    // Сортируем монеты по убыванию
    sort(coins.rbegin(), coins.rend());

    int coinCount = 0;
    int i = 0;

    // Проходим по всем номиналам
    while (amount > 0 && i < coins.size()) {
        if (coins[i] <= amount) {
            // Берем столько монет текущего номинала, сколько возможно
            coinCount += amount / coins[i];
            amount %= coins[i];  // Остаток после взятия монет
        }
        i++;
    }

    // Если осталась неразмененная часть
    if (amount > 0) {
        return -1;
    }

    return coinCount;
}

