#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char** letterCasePermutation(char* s, int* returnSize) 
{
    int len = strlen(s);
    char** ret = (char**)malloc(sizeof(char*) * (int)pow(2, len));  // 申请二维数组： 行数2的N次方
    ret[0] = (char*)malloc(sizeof(char) * (len + 1));  // 第一个返回的字符串数组
    strcpy(ret[0], s);
    int i, j, k;
    int size = 1;
    for (i = 0; i < len; i++) 
    {
        k = size;
        if (isalpha(s[i])) 
        {
            for (j = 0; j < k; j++) 
            {           // k为总行数，j控制行数下移                            
                ret[k + j] = malloc(sizeof(char) * (len + 1));
                strcpy(ret[j + k], ret[j]);    // 比较妙，基于j->j+K行，每次只改一个字符                         
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
