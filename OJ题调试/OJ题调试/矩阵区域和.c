//#include "test.h"
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes) {
//    int m = matSize, n = *matColSize;
//    int dp[m + 1][n + 1];   //LeetCode�ı������������ƺ���ֱ���߶�̬�����
//    /* �����������һ��0���ڱ߽紦�� */
//    /* ÿ���������Ӧ-1λ�����ּ������Ϸ����е����ֺ� */
//    for (int i = 0; i < m + 1; i++)dp[i][0] = 0;
//    for (int j = 1; j < n + 1; j++)dp[0][j] = 0;
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < n + 1; j++) {
//            /* ������ǰ׺��=������ֵ+��ǰ׺��+��ǰ׺��-����ǰ׺�� */
//            dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//        }
//    }
//    /* ÿ����λ��ֵΪ�����Χ�͡� - �����͡� - ���Ϸ��͡� + ���ظ����������Ϻ͡� */
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