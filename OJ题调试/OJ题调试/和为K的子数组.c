#include "test.h"

int subarraySum(int* nums, int numsSize, int k) {
    int maxValue = numsSize * 1000 * 2;
    int minValue = -1000 * numsSize;
    int* sumList = (int*)malloc(maxValue * sizeof(int));
    if (sumList == NULL) {
        return 0;
    }
    memset(sumList, 0, sizeof(int) * maxValue);

    int count = 0;
    int preSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        preSum += nums[i];
        if (preSum == k) {
            count++;
        }
        int diffVal = preSum - k;
        int pos = diffVal - minValue;
        count += sumList[pos];
        sumList[preSum - minValue]++;
    }
    return count;
}

int main() {
    int nums[] = { 1,1,1 };
    int sz = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int ret = subarraySum(nums, sz, k);
    printf("%d\n", ret);
    return 0;
}