//#include <stdlib.h>
//#include <stdio.h>
//
//int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
//{
//    int left = 1;
//    int right = 1;
//    int sum = 0;
//    *returnSize = 0;
//    int** ret = (int**)malloc(sizeof(int*) * target);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * target);
//    while (left < target / 2)
//    {
//        if (sum < target)
//        {
//            sum += right;
//            right++;
//        }
//        else if (sum > target)
//        {
//            sum -= left;
//            left++;
//        }
//        else
//        {
//            (*returnColumnSizes)[*returnSize] = right - left;
//            ret[*returnSize] = (int*)malloc(sizeof(int) * (right - left));
//            for (int i = left; i < right; i++)
//            {
//                ret[*returnSize][i - left] = i;
//            }
//            *returnSize++;
//            sum -= left;
//            left++;
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    int target = 9;
//    int returenSize = 0;
//    int* returnColumSize = 0;
//    findContinuousSequence(target, returenSize, &returnColumSize);
//}