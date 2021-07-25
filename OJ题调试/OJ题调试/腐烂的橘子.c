//#include "test.h"
//
//typedef struct Position
//{
//    int row;
//    int col;
//}pos;
//
//int dir[4][2] = { {-1,0}, {1,0},  {0, -1}, {0, 1} };
//
//int orangesRotting(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize;
//    int col = *gridColSize;
//    int time = 0;
//    int tail = 0;
//    int head = 0;
//    pos* que = (pos*)malloc(sizeof(pos) * 100);
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] == 2)
//            {
//                que[tail].row = i;
//                que[tail].col = j;
//                tail++;
//            }
//        }
//    }
//
//    while (head < tail)
//    {
//        int pretail = tail;
//
//        while (head < pretail)
//        {
//            pos cur = que[head++];
//
//            for (int j = 0; j < 4; j++)
//            {
//                int x = cur.row + dir[j][0];
//                int y = cur.col + dir[j][1];
//
//                if (x < 0 || x >= row || y < 0 || y >= col)
//                {
//                    continue;
//                }
//
//                if (grid[x][y] == 1)
//                {
//                    grid[x][y] = 2;
//                    que[tail].row = x;
//                    que[tail].col = y;
//                    tail++;
//                }
//            }
//        }
//
//        time++;
//    }
//
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] == 1)
//            {
//                return -1;
//            }
//        }
//    }
//
//    return time ? time - 1 : 0;
//
//}
//
//int main()
//{
//    int arr[3][3] = { {2,1,1},{1,1,0},{0,1,1} };
//    int time=orangesRotting(arr, 3, 3);
//    printf("%d\n", time);
//    return 0;
//
//}