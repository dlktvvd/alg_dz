#include <iostream>
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

int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    
    return coinChangeRecursive(coins, amount, 0);
}

void inputData(vector<int>& coins, int& amount) {
    int n;
    cout << "Введите количество номиналов монет: ";
    cin >> n;
    
    coins.resize(n);
    cout << "Введите номиналы монет (через пробел): ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    cout << "Введите сумму для размена: ";
    cin >> amount;
}

int main() {
    cout << "=== Программа для размена суммы на монеты ===" << endl;
    cout << "Используется метод полного перебора" << endl << endl;
    
    vector<int> coins;
    int amount;
    
    inputData(coins, amount);
    
    if (coins.empty()) {
        cout << "Ошибка: список монет не может быть пустым!" << endl;
        return 1;
    }
    
    if (amount < 0) {
        cout << "Ошибка: сумма не может быть отрицательной!" << endl;
        return 1;
    }
    
    int result = coinChange(coins, amount);
    
    cout << "\n=== Результат ===" << endl;
    cout << "Номиналы монет: ";
    for (int coin : coins) {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Сумма для размена: " << amount << endl;
    
    if (result == -1) {
        cout << "Размен невозможен!" << endl;
    } else if (result == 0 && amount == 0) {
        cout << "Сумма 0 разменивается 0 монетами" << endl;
    } else {
        cout << "Минимальное количество монет: " << result << endl;
    }
    
    cout << "\n=== Программа завершена ===" << endl;
    
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Нажмите Enter для выхода...";
        cin.ignore();
        cin.get();
    #endif
    
    return 0;
}