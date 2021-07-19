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
//    //��
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
//    //��
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
//    //��
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
//    //��
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
//        //�����Թ�
//        //�ȴ���������
//        //�����Ƕ�λ���飬�ȴ���һ������N������ָ���ָ�����飬ָ�����鴢�����ָ�룬����ָ�����ָ�������ָ��Ϊ����ָ��
//        //ָ��������ÿ��ָ�붼Ϊ����ָ�룬ÿ������ָ��ָ�������Ϊÿһ��
//        int** Maze = (int**)malloc(sizeof(int*) * N);
//        for (int i = 0; i < N; i++)
//        {
//            //Maze[i]����int*����һ��ָ�룬���ٵĿռ䴢��int
//            Maze[i] = (int*)malloc(sizeof(int) * M);
//        }
//
//        //�����Թ�
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