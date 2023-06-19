#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int coinsRequired = 0;
    for (int i = 8; i >= 0 && amount > 0; --i)
    {
        int q = amount / coins[i];
        amount -= (coins[i] * q);
        coinsRequired += q;
    }
    return coinsRequired;
}
