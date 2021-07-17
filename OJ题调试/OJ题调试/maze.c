//#define _CRT_SECURE_NO_WARNINGS 1
//
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
//}Pos;
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////栈创建
//
//typedef Pos STDataType;
//
//typedef struct Stack
//{
//    STDataType* a;
//    int top;
//    int capacity;
//}Stack;
//
//void StackInit(Stack* ps)
//{
//    assert(ps);
//
//    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
//    if (ps->a == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    ps->capacity = 4;
//    ps->top = 0;//初始给0，top指向栈顶元素的下一个；
//}
//
//void StackDestory(Stack* ps)
//{
//    assert(ps);
//    free(ps->a);
//    ps->a = NULL;
//    ps->top = ps->capacity = 0;
//}
//
////入栈
//void StackPush(Stack* ps, STDataType x)
//{
//    assert(ps);
//
//    if (ps->top == ps->capacity)
//    {
//        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
//        if (tmp == NULL)
//        {
//            printf("realloc fail\n");
//            exit(-1);
//        }
//        else
//        {
//            ps->a = tmp;
//            ps->capacity *= 2;
//        }
//    }
//
//    ps->a[ps->top] = x;
//    ps->top++;
//}
////出栈
//void StackPop(Stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);//栈空了，直接终止报错
//
//    ps->top--;
//}
//
//STDataType StackTop(Stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);//栈空了，直接终止报错
//
//    return ps->a[ps->top - 1];
//}
//
//int StackSize(Stack* ps)
//{
//    assert(ps);
//
//    return ps->top;
//}
//
//bool StackEmpty(Stack* ps)
//{
//    assert(ps);
//
//    return ps->top == 0;
//}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////迷宫主程序
//
//Stack path;
//
////判断是否有通路
//bool IsPass(int** Maze, int N, int M, Pos next)
//{
//    if (next.col >= 0 && next.col < M && next.row >= 0 && next.row < N && Maze[next.row][next.col] == 0)
//        return true;
//    else
//        return false;
//}
//
////判断是否有到终点的路
//bool GetMazePath(int** Maze, int N, int M, Pos cur)
//{
//    StackPush(&path, cur);
//
//    //判断是否到出口
//    if (cur.col == M - 1 && cur.row == N - 1)
//        return true;
//
//    Pos next;
//    //将走过的地方置2，防止重走
//    Maze[cur.row][cur.col] = 2;
//
//    //探测上下左右四个方向
//
//    //上
//    next = cur;
//    next.row -= 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        //如果有通路将继续递归
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //下
//    next = cur;
//    next.row += 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //左
//    next = cur;
//    next.col -= 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //右
//    next = cur;
//    next.col += 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //当走到思路，将走错的坐标删除
//    StackPop(&path);
//    return false;
//}
//
////采用栈储存路径
////由于先进后出，栈顶为出口，栈底为入口，需要反过来
////所以再创建一个栈将数据倒过来再输出
//void PrintPath(Stack path)
//{
//    Stack rPath;
//    StackInit(&rPath);
//    while (!StackEmpty(&path))
//    {
//        StackPush(&rPath, StackTop(&path));
//        StackPop(&path);
//    }
//
//    while (!StackEmpty(&rPath))
//    {
//        Pos top = StackTop(&rPath);
//        printf("(%d,%d)\n", top.row, top.col);
//        StackPop(&rPath);
//    }
//
//    StackDestory(&rPath);
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
//        //初始化栈
//        StackInit(&path);
//        //定起点
//        Pos entry = { 0,0 };
//
//        if (GetMazePath(Maze, N, M, entry))
//        {
//            PrintPath(path);
//        }
//        else
//        {
//            printf("没有找到通路\n");
//        }
//
//        StackDestory(&path);
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