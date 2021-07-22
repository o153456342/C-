//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//
//#define MIN(A, B) ((A)<(B))?(A):(B)
//
////单调栈
//int trap(int* height, int heightSize)
//{
//    if (heightSize <= 2)
//        return 0;
//
//    int* stk = (int*)malloc(sizeof(int) * heightSize);
//    int top = 0;
//    int sum = 0;
//    for (int i = 0; i < heightSize; i++)
//    {
//        while (top && height[stk[top - 1]] < height[i])
//        {
//            int stk_top = stk[--top];
//            if (!top)
//            {
//                break;
//            }
//            int left = stk[top - 1];
//            int wide = i - left - 1;
//            int depth = (MIN(height[left], height[i])) - height[stk_top];
//
//            sum += wide * depth;
//        }
//        stk[top++] = i;
//    }
//    return sum;
//}
//
//
//////动态规划
////int trap(int* height, int heightSize)
////{
////    if (heightSize <= 2)
////        return 0;
////    int* maxright = (int*)malloc(sizeof(int) * heightSize);
////    int* maxleft = (int*)malloc(sizeof(int) * heightSize);
////
////    maxleft[0] = height[0];
////    for (int i = 1; i < heightSize; i++)
////    {
////        maxleft[i] = fmax(height[i], maxleft[i - 1]);
////    }
////
////    maxright[heightSize - 1] = height[heightSize - 1];
////    for (int i = heightSize - 2; i >= 0; i--)
////    {
////        maxright[i] = fmax(height[i], maxright[i + 1]);
////    }
////
////    int sum = 0;
////    for (int i = 0; i < heightSize; i++)
////    {
////        if (fmin(maxleft[i], maxright[i]) - height[i] > 0)
////            sum += fmin(maxleft[i], maxright[i]) - height[i];
////    }
////    return sum;
////}
//
//int main()
//{
//    int arr[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    int sum = trap(arr,12);
//    printf("%d\n", sum);
//    return 0;
//}