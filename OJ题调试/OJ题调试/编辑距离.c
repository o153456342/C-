//#include "test.h"
//
//static inline int min(int a, int b, int c)
//{
//    int d = a < b ? a : b;
//    return d < c ? d : c;
//}
//
//int minDistance(char* word1, char* word2) {
//    /*
//     * ״̬���̣�case1:word1��word2��Ȼ��� => dp[i][j] = dp[i - 1][j - 1]
//     *          case2:word1�ɲ��롢ɾ�����滻���word2 => dp[i][j] = 1 + MIN{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}
//     * �߽�������dp[0][j] = j, dp[i][0] = i
//     * ��ʼ������dp[0][0] = 0 ���ճ�һ��
//     */
//
//    int row = 0;
//    int col = 0;
//    int lenOfWord1IsRow = strlen(word1);
//    int lenOfWord2IsCol = strlen(word2);
//
//    // ÿ�����Ϊһά�����˳���
//    int** dp = (int**)malloc((lenOfWord1IsRow + 1) * sizeof(int*));
//    for (row = 0; row <= lenOfWord1IsRow; row++)
//    {
//        dp[row] = (int*)malloc((lenOfWord2IsCol + 1) * sizeof(int));
//    }
//
//    // ��ʼ�������߽�����
//    for (row = 0; row <= lenOfWord1IsRow; row++)
//    {
//        dp[row][0] = row;
//    }
//
//    for (col = 0; col <= lenOfWord2IsCol; col++)
//    {
//        dp[0][col] = col;
//    }
//
//    // ״̬ת�Ʒ���
//    for (row = 1; row <= lenOfWord1IsRow; row++)
//    {
//        for (col = 1; col <= lenOfWord2IsCol; col++)
//        {
//            if (word1[row - 1] == word2[col - 1])
//            {
//                dp[row][col] = dp[row - 1][col - 1];
//            }
//            else
//            {
//                dp[row][col] = 1 + min(dp[row][col - 1], dp[row - 1][col], dp[row - 1][col - 1]);
//            }
//        }
//    }
//
//    return dp[lenOfWord1IsRow][lenOfWord2IsCol];
//}
//
//int main() {
//
//    return 0;
//}