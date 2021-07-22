#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char** letterCasePermutation(char* s, int* returnSize) 
{
    int len = strlen(s);
    char** ret = (char**)malloc(sizeof(char*) * (int)pow(2, len));  // �����ά���飺 ����2��N�η�
    ret[0] = (char*)malloc(sizeof(char) * (len + 1));  // ��һ�����ص��ַ�������
    strcpy(ret[0], s);
    int i, j, k;
    int size = 1;
    for (i = 0; i < len; i++) 
    {
        k = size;
        if (isalpha(s[i])) 
        {
            for (j = 0; j < k; j++) 
            {           // kΪ��������j������������                            
                ret[k + j] = malloc(sizeof(char) * (len + 1));
                strcpy(ret[j + k], ret[j]);    // �Ƚ������j->j+K�У�ÿ��ֻ��һ���ַ�                         
                ret[k + j][i] = (isupper(s[i]) != 0) ? s[i] + 32 : s[i] - 32;
                size++;
            }
        }
    }

    *returnSize = size;
    return ret;
}

int main()
{
    char s[] = "1a2c";
    int returnSize = 0;
    letterCasePermutation(s, &returnSize);
    return 0;
}
