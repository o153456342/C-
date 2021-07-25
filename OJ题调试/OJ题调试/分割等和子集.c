#include "test.h"

bool canPartition(int* nums, int numsSize)
{
    int sum = 0;
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        maxNum = fmax(nums[i], maxNum);
    }

    if (sum % 2 == 1)
        return false;

    int target = sum / 2;

    if (target < maxNum)
        return false;

    int* dp = (int*)malloc(sizeof(int) * (target + 1));
    memset(dp, 0, sizeof(int) * (target + 1));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}

int main() {
    int stones[] = { 1,5,11,5 };
    int sz = sizeof(stones) / sizeof(int);

    printf("%d\n", canPartition(stones, sz));
    return 0;
}