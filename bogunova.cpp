#include <vector>
#include <algorithm>

using namespace std;

int greedyCoinChange(const vector<int>& coins, int amount) {
    // Сортируем монеты по убыванию
    vector<int> coinsCopy = coins;
    sort(coinsCopy.rbegin(), coinsCopy.rend());

    int coinCount = 0;
    int i = 0;

    // Проходим по всем номиналам
    while (amount > 0 && i < coinsCopy.size()) {
        if (coinsCopy[i] <= amount) {
            // Берем столько монет текущего номинала, сколько возможно
            coinCount += amount / coinsCopy[i];
            amount %= coinsCopy[i];  // Остаток после взятия монет
        }
        i++;
    }

    // Если осталась неразмененная часть
    if (amount > 0) {
        return -1;
    }

    return coinCount;
}