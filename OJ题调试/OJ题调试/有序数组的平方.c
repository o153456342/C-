//#include <stdio.h>
//#include <stdlib.h>
//
//int* sortedSquares(int* nums, int numsSize, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * numsSize);
//    int left = 0;
//    int right = numsSize - 1;
//    int i = numsSize - 1;
//    while (left <= right)
//    {
//        int left2 = nums[left] * nums[left];
//        int right2 = nums[right] * nums[right];
//        if (left2 > right2)
//        {
//            ret[i--] = left2;
//            left++;
//        }
//        else
//        {
//            ret[i--] = right2;
//            right--;
//
//        }
//    }
//    *returnSize = numsSize;
//    return ret;
//}
//
//int main()
//{
//    int arr[] = { -7,-3,2,3,11 };
//    int returnSize=0;
//    sortedSquares(arr, 5, &returnSize);
//    return 0;
//}