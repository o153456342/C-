//#include "test.h"
//
//int longestPalindromeSubseq(char* s) {
//    int len = strlen(s);
//    int* dp = (int*)malloc(sizeof(int)*len);
//    memset(dp, 0, sizeof(int) * len);
//    for (int j = 0; j < len; ++j) {
//        int* dp1 = (int*)malloc(sizeof(int) * (j+1));
//        dp1[j] = 1;
//        for (int i = j - 1; i >= 0; --i) {
//            if (s[i] == s[j]) {
//                if (i + 1 == j) {
//                    dp1[i] = 2;
//                }
//                else {
//                    dp1[i] = dp[i + 1] + 2;
//                }
//            }
//            else {
//                dp1[i] = fmax(dp[i], dp1[i + 1]);
//            }
//        }
//        memcpy(dp, dp1, sizeof dp1);
//    }
//    int res = 0;
//    for (int i = 0; i < len; ++i) {
//        res = fmax(res, dp[i]);
//    }
//    return res;
//}
//
//int main() {
//    char s[] = "babad";
//    int str = longestPalindromeSubseq(s);
//    printf("%d", str);
//    return 0;
//}
