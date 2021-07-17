//#define MIN(A, B) (A)<(B)?(A):(B)
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int jump(int* nums, int numsSize)
//{
//    int* dp = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        dp[i] = numsSize + 1;
//    }
//    dp[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; j <= i + nums[i]; j++)
//        {
//            if (j >= numsSize)
//                return dp[numsSize - 1];
//             dp[j] = MIN(dp[i] + 1, dp[j]);
//        }
//    }
//    return dp[numsSize - 1];
//}
//
//int main()
//{
//    int arr[] = {2,3,1,1,4};
//    int numsSize = sizeof(arr) / sizeof(arr[0]);
//    jump(arr, numsSize);
//    return 0;
//}