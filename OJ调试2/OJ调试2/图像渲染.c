#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Position
{
    int row;
    int col;
}pos;

bool issame(int** image, int row, int col, pos next, pos aim, int newColor, int** ret)
{
    if (next.col < col && next.col >= 0 && next.row >= 0 && next.row < row
        && image[aim.row][aim.col] == image[next.row][next.col]
        && ret[next.row][next.col] != newColor)
        return true;
    else
        return false;
}

void changecolor(int** image, int row, int col, pos next, pos aim, int newColor, int** ret)
{
    ret[next.row][next.col] = newColor;


    //上
    next = aim;
    next.row -= 1;
    if (issame(image, row, col, next, aim, newColor, ret))
    {
        changecolor(image, row, col, next, aim, newColor, ret);
    }

    //下
    next = aim;
    next.row += 1;
    if (issame(image, row, col, next, aim, newColor, ret))
    {
        changecolor(image, row, col, next, aim, newColor, ret);
    }

    //左
    next = aim;
    next.col -= 1;
    if (issame(image, row, col, next, aim, newColor, ret))
    {
        changecolor(image, row, col, next, aim, newColor, ret);
    }

    //右
    next = aim;
    next.col += 1;
    if (issame(image, row, col, next, aim, newColor, ret))
    {
        changecolor(image, row, col, next, aim, newColor, ret);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes)
{
    int row = imageSize;
    int col = *imageColSize;
    int** ret = (int**)malloc(sizeof(int*) * row);
    *returnSize = row;
    for (int i = 0; i < row; i++)
    {
        *returnColumnSizes[i] = col;
    }
    pos aim = { sr,sc };
    pos next = aim;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ret[i][j] = image[i][j];
        }
    }

    ret[sr][sc] = newColor;

    changecolor(image, row, col, next, aim, newColor, ret);
    return ret;
}

int main()
{
    int N = 0, M = 0;
    while (scanf("%d%d", &N, &M) != EOF)
    {

        int** image = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++)
        {
            //Maze[i]就是int*，是一个指针，开辟的空间储存int
            image[i] = (int*)malloc(sizeof(int) * M);
        }

        //输入迷宫
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &image[i][j]);
            }
        }

        int sr = 1;
        int sc = 1;
        int newColor = 2;
        int returnSize = 0;
        int** returnColumnSizes = NULL;

        floodFill(image, N, &M, sr, sc, newColor, &returnSize, returnColumnSizes);

        return 0;
    }
}