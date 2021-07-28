//#include "test.h"
//
//int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
//    int n = obstacleGridSize, m = *obstacleGridColSize;
//    int* dp = (int*)malloc(sizeof(int) * m);
//    dp[0] = (obstacleGrid[0][0] == 0);
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (obstacleGrid[i][j] == 1) {
//                dp[j] = 0;
//                continue;
//            }
//            if (j - 1 >= 0 && obstacleGrid[i][j] == 0) {
//                dp[j] += dp[j - 1];
//            }
//        }
//    }
//    return dp[m - 1];
//
//}
//
//int main() {
//    int obstacleGrid[3][3] = { {0,0,0},{0,1,0},{0,0,0} };
//    int row = 3;
//    int col = 3;
//    int ret = uniquePathsWithObstacles(&obstacleGrid, row, &col);
//    printf("%d\n", ret);
//    return 0;
//}