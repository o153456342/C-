//#include "test.h"
//
//struct huiwen {
//    int start;
//    int end;
//};
//
//char* longestPalindrome(char* s) {
//    struct huiwen temp, max;//�����������������ڴ洢��ǰ���Ĵ������Ż��Ĵ�
//    int i;
//    int lenth = strlen(s);
//    max.start = max.end = 0;//���Ż��Ĵ���ʼ��Ϊ0
//    for (i = 0; i < lenth;)
//    {
//        temp.start = temp.end = i;
//        while (s[temp.start] == s[temp.end + 1])//������ͬ���ַ���Ϊ���Ĵ�����������
//            (temp.end)++;
//        i = temp.end + 1;
//        while ((temp.start - 1) >= 0 && (temp.end + 1) < lenth)//��������
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
