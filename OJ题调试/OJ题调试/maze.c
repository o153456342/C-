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
////ջ����
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
//    ps->top = 0;//��ʼ��0��topָ��ջ��Ԫ�ص���һ����
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
////��ջ
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
////��ջ
//void StackPop(Stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);//ջ���ˣ�ֱ����ֹ����
//
//    ps->top--;
//}
//
//STDataType StackTop(Stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);//ջ���ˣ�ֱ����ֹ����
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
////�Թ�������
//
//Stack path;
//
////�ж��Ƿ���ͨ·
//bool IsPass(int** Maze, int N, int M, Pos next)
//{
//    if (next.col >= 0 && next.col < M && next.row >= 0 && next.row < N && Maze[next.row][next.col] == 0)
//        return true;
//    else
//        return false;
//}
//
////�ж��Ƿ��е��յ��·
//bool GetMazePath(int** Maze, int N, int M, Pos cur)
//{
//    StackPush(&path, cur);
//
//    //�ж��Ƿ񵽳���
//    if (cur.col == M - 1 && cur.row == N - 1)
//        return true;
//
//    Pos next;
//    //���߹��ĵط���2����ֹ����
//    Maze[cur.row][cur.col] = 2;
//
//    //̽�����������ĸ�����
//
//    //��
//    next = cur;
//    next.row -= 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        //�����ͨ·�������ݹ�
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //��
//    next = cur;
//    next.row += 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //��
//    next = cur;
//    next.col -= 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //��
//    next = cur;
//    next.col += 1;
//    if (IsPass(Maze, N, M, next))
//    {
//        if (GetMazePath(Maze, N, M, next))
//            return true;
//    }
//
//    //���ߵ�˼·�����ߴ������ɾ��
//    StackPop(&path);
//    return false;
//}
//
////����ջ����·��
////�����Ƚ������ջ��Ϊ���ڣ�ջ��Ϊ��ڣ���Ҫ������
////�����ٴ���һ��ջ�����ݵ����������
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
//        //��ʼ��ջ
//        StackInit(&path);
//        //�����
//        Pos entry = { 0,0 };
//
//        if (GetMazePath(Maze, N, M, entry))
//        {
//            PrintPath(path);
//        }
//        else
//        {
//            printf("û���ҵ�ͨ·\n");
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