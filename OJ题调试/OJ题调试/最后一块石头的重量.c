//#include "test.h"
//
//int lastStoneWeightII(int* stones, int stonesSize)
//{
//    //分成两堆重量近乎相等的石头
//    int sum_weight = 0;
//    for (int i = 0; i < stonesSize; i++)
//    {
//        sum_weight += stones[i];
//    }
//    int target = sum_weight / 2;
//    int* dp = (int*)malloc(sizeof(int) * (target + 1));
//    memset(dp, 0, sizeof(int) * (target + 1));
//    for (int i = 0; i < stonesSize; i++)
//    {
//        for (int j = target; j >= stones[i]; j--)
//        {
//            dp[j] = fmax(dp[j], dp[j - stones[i]] + stones[i]);
//        }
//    }
//    return sum_weight - 2 * dp[target];
//}
//
//int main() {
//    int stones[] = { 2,7,4,1,8,1 };
//    int sz = sizeof(stones) / sizeof(int);
//    int ret = lastStoneWeightII(stones, sz);
//    printf("%d\n", ret);
//    return 0;
//}