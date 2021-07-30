//#include "test.h"
//
//struct huiwen {
//    int start;
//    int end;
//};
//
//char* longestPalindrome(char* s) {
//    struct huiwen temp, max;//先声明两个变量用于存储当前回文串和最优回文串
//    int i;
//    int lenth = strlen(s);
//    max.start = max.end = 0;//最优回文串初始化为0
//    for (i = 0; i < lenth;)
//    {
//        temp.start = temp.end = i;
//        while (s[temp.start] == s[temp.end + 1])//先找相同的字符作为回文串的中心主体
//            (temp.end)++;
//        i = temp.end + 1;
//        while ((temp.start - 1) >= 0 && (temp.end + 1) < lenth)//两边延伸
//        {
//            if (s[temp.start - 1] == s[temp.end + 1])
//            {
//                (temp.start)--;
//                (temp.end)++;
//            }
//            else
//                break;
//        }
//        if (temp.end - temp.start > max.end - max.start)
//            max = temp;
//    }
//    s[max.end + 1] = '\0';
//    return &s[max.start];
//}
//
//int main() {
//    char s[] = "babad";
//    char* str = longestPalindrome(s);
//    printf("%s", str);
//    return 0;
//}
