#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedyCoinChange(int amount, vector<int>& coins) {
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

int main() {
    int n, amount;

    // Ввод количества номиналов
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    // Ввод номиналов монет
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Ввод суммы для размена
    cout << "Enter the amount to change: ";
    cin >> amount;

    // Проверка на корректность ввода
    if (amount < 0) {
        cout << "Error: amount cannot be negative!" << endl;
        return 1;
    }

    // Вызов функции размена
    int result = greedyCoinChange(amount, coins);

    // Вывод результата
    cout << "\n=== Results ===" << endl;
    cout << "Coin denominations: ";
    for (int i = 0; i < n; i++) {
        cout << coins[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    cout << "Amount for change: " << amount << endl;
    cout << "Minimum number of coins: ";
    if (result != -1) {
        cout << result << endl;
    }
    else {
        cout << "-1 (change impossible)" << endl;
    }

    return 0;
}