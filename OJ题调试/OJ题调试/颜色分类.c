//#include "test.h"
//
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b, * b = t;
//}
//
//void sortColors(int* nums, int numsSize) {
//    int p0 = 0, p2 = numsSize - 1;
//    for (int i = 0; i <= p2; ++i) {
//        while (i <= p2 && nums[i] == 2) {
//            swap(&nums[i], &nums[p2]);
//            --p2;
//        }
//        if (nums[i] == 0) {
//            swap(&nums[i], &nums[p0]);
//            ++p0;
//        }
//    }
//}
//
//int main() {
//    int arr[] = { 2,0,2,1,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    sortColors(arr, sz);
//    return 0;
//}