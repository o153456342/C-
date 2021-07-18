//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int lengthOfLongestSubstring(char* s)
//{
//    int* arr = (int*)malloc(sizeof(int) * 26);
//    memset(arr, 0, sizeof(int) * 26);
//    int len = strlen(s);
//    int count = 0;
//
//    for (int i = 0; i < len; i++)
//    {
//        arr[s[i] - 'a']++;
//        if (arr[s[i] - 'a'] == 1)
//        {
//            count++;
//        }
//    }
//
//    return count;
//
//}
//
//int main()
//{
//    int a = lengthOfLongestSubstring("pwwkew");
//    printf("%d", a);
//    return 0;
//}