#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    // int dp[triangleSize+1][triangleSize+1];
    int dp[triangleSize + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = triangleSize - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            // dp[i][j] = fmin(dp[i+1][j],dp[i+1][j+1]) +triangle[i][j];
            dp[j] = fmin(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }
    return dp[0];
}

//×Ô¶¥Ïòµ×
// int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
// {
//     int dp[triangleSize][triangleSize];
//     memset(dp, 0, sizeof(dp));
//     dp[0][0] = triangle[0][0];
//     for(int i =1;i<triangleSize;i++)
//     {
//         dp[i][0] = dp[i-1][0] + triangle[i][0];
//         for(int j= 1;j<i;j++)
//         {
//             dp[i][j] = fmin(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
//         }
//          dp[i][i] = dp[i-1][i-1] + triangle[i][i];
//     }
//     int ret = dp[triangleSize-1][0];
//     for(int i=1;i<triangleSize;i++)
//     {
//         ret = fmin(dp[triangleSize-1][i],ret);
//     }    

//     return ret;
// }

int main()
{
    minimumTotal();
    return 0;
}