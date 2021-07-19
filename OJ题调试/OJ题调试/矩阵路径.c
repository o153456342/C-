//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef struct Position
//{
//    int row;
//    int col;
//}pos;
//
//bool ispass(char** board, char* word, int row, int col, pos next, int k, int len)
//{
//    if (next.row < row && next.row >= 0 && next.col < col && next.col >= 0 && board[next.row][next.col] == word[k])
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool getword(char** board, char* word, int row, int col, pos cur, int k, int len)
//{
//
//    if (k == len - 1)
//    {
//        return true;
//    }
//
//    pos next;
//    board[cur.row][cur.col] = 2;
//
//    //上
//    next = cur;
//    next.row -= 1;
//    if (ispass(board, word, row, col, next, k + 1, len))
//    {
//        if (getword(board, word, row, col, cur, k, len))
//        {
//            return true;
//        }
//    }
//
//    //下
//    next = cur;
//    next.row += 1;
//    if (ispass(board, word, row, col, next, k + 1, len))
//    {
//        if (getword(board, word, row, col, cur, k, len))
//        {
//            return true;
//        }
//    }
//
//    //左
//    next = cur;
//    next.col -= 1;
//    if (ispass(board, word, row, col, next, k + 1, len))
//    {
//        if (getword(board, word, row, col, cur, k, len))
//        {
//            return true;
//        }
//    }
//
//    //右
//    next = cur;
//    next.col += 1;
//    if (ispass(board, word, row, col, next, k + 1, len))
//    {
//        if (getword(board, word, row, col, cur, k, len))
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool exist(char** board, int boardSize, int boardColSize, char* word)
//{
//    int row = boardSize;
//    int col = boardColSize;
//    int k = 0;//word[k]
//    int len = strlen(word);
//    pos cur = { 0,0 };
//    if (getword(board, word, row, col, cur, k, len))
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//int main()
//{
//    int N = 0, M = 0;
//    while (scanf("%d%d", &N, &M) != EOF)
//    {
//        //创建迷宫
//        //先创建行坐标
//        //由于是二位数组，先创建一个含有N个数组指针的指针数组，指针数组储存的是指针，所以指向这个指针数组的指针为二级指针
//        //指针数组中每个指针都为数组指针，每个数组指针指向的数组为每一行
//        int** Maze = (int**)malloc(sizeof(int*) * N);
//        for (int i = 0; i < N; i++)
//        {
//            //Maze[i]就是int*，是一个指针，开辟的空间储存int
//            Maze[i] = (int*)malloc(sizeof(int) * M);
//        }
//
//        //输入迷宫
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < M; j++)
//            {
//                scanf("%d", &Maze[i][j]);
//            }
//        }
//    
//        exist({ {'A', 'B', "C", "E"},{"S", "F", "C", "S"},{"A", "D", "E", "E"} }, N, M, "ABCCED");
//
//        for (int i = 0; i < N; i++)
//        {
//            free(Maze[i]);
//        }
//        free(Maze);
//        Maze = NULL;
//    }
//    return 0;
//}