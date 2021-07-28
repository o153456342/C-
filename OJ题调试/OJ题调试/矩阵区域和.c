//#include "test.h"
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes) {
//    int m = matSize, n = *matColSize;
//    int dp[m + 1][n + 1];   //LeetCode的变量创建数组似乎是直接走动态分配的
//    /* 左、上两边添加一排0用于边界处理 */
//    /* 每个数代表对应-1位置数字及其左上方所有的数字和 */
//    for (int i = 0; i < m + 1; i++)dp[i][0] = 0;
//    for (int j = 1; j < n + 1; j++)dp[0][j] = 0;
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < n + 1; j++) {
//            /* 本处的前缀和=本处的值+左前缀和+上前缀和-左上前缀和 */
//            dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//        }
//    }
//    /* 每个数位的值为【最大范围和】 - 【左侧和】 - 【上方和】 + 【重复减掉的左上和】 */
//    int il = 0, ir = 0, jl = 0, jr = 0;
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < n + 1; j++) {
//            il = i - K - 1 < 0 ? 0 : i - K - 1;
//            jl = j - K - 1 < 0 ? 0 : j - K - 1;
//            ir = i + K >= m ? m : i + K;
//            jr = j + K >= n ? n : j + K;
//            mat[i - 1][j - 1] = dp[ir][jr] - dp[il][jr] - dp[ir][jl] + dp[il][jl];
//        }
//    }
//    *returnSize = matSize;
//    *returnColumnSizes = matColSize;
//    return mat;
//}
//
//int main() {
//    int arr[3][3] = { {1,2,3}, {4,5,6},{7,8,9} };
//    int k = 1, row = 3, col = 3, returnSize = 0;
//    int returnColumnSizes[3][1] = { {3}, {3}, {3} };
//    matrixBlockSum(arr, row, &col, k, returnSize, returnColumnSizes);
//    return 0;
//}