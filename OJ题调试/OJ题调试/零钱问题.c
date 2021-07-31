#include "test.h"

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = fmin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[] = { 1,2,5 };
    int sz = sizeof(coins) / sizeof(coins[0]);
    int ret = coinChange(coins, sz, 11);
    printf("%d\n", ret);
    return 0;
}