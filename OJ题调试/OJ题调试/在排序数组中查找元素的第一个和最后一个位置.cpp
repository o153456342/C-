//#include "test.h"
//
//int binarySearch(int* nums, int numsSize, int target, bool lower) {
//    int left = 0, right = numsSize - 1, ans = numsSize;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (nums[mid] > target || (lower && nums[mid] >= target)) {
//            right = mid - 1;
//            ans = mid;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return ans;
//}
//
//int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//    int leftIdx = binarySearch(nums, numsSize, target, true);
//    int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    *returnSize = 2;
//    if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target) {
//        ret[0] = leftIdx, ret[1] = rightIdx;
//        return ret;
//    }
//    ret[0] = -1, ret[1] = -1;
//    return ret;
//}
//
//int main() {
//
//    return 0;
//}