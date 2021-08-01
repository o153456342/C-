//#include "test.h"
//
//const int dx[4] = { 1, -1, 0, 0 };
//const int dy[4] = { 0, 0, 1, -1 };
//
//void solve(char** board, int boardSize, int* boardColSize) {
//    int n = boardSize;
//    if (n == 0) {
//        return;
//    }
//    int m = boardColSize[0];
//
//    int** que = (int**)malloc(sizeof(int*) * n * m);
//    for (int i = 0; i < n * m; i++) {
//        que[i] = (int*)malloc(sizeof(int) * 2);
//    }
//    int l = 0, r = 0;
//    for (int i = 0; i < n; i++) {
//        if (board[i][0] == 'O') {
//            board[i][0] = 'A';
//            que[r][0] = i, que[r++][1] = 0;
//        }
//        if (board[i][m - 1] == 'O') {
//            board[i][m - 1] = 'A';
//            que[r][0] = i, que[r++][1] = m - 1;
//        }
//    }
//    for (int i = 1; i < m - 1; i++) {
//        if (board[0][i] == 'O') {
//            board[0][i] = 'A';
//            que[r][0] = 0, que[r++][1] = i;
//        }
//        if (board[n - 1][i] == 'O') {
//            board[n - 1][i] = 'A';
//            que[r][0] = n - 1, que[r++][1] = i;
//        }
//    }
//    while (l < r) {
//        int x = que[l][0], y = que[l][1];
//        l++;
//        for (int i = 0; i < 4; i++) {
//            int mx = x + dx[i], my = y + dy[i];
//            if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
//                continue;
//            }
//            board[mx][my] = 'A';
//            que[r][0] = mx, que[r++][1] = my;
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (board[i][j] == 'A') {
//                board[i][j] = 'O';
//            }
//            else if (board[i][j] == 'O') {
//                board[i][j] = 'X';
//            }
//        }
//    }
//    for (int i = 0; i < n * m; i++) {
//        free(que[i]);
//    }
//    free(que);
//}
//
//int main() {
//    char arr[4][4] = { "XXXX", "XOOX","XXOX","XOXX" };
//    int row = 4, col = 4;
//    solve(arr, row, &col);
//    return 0;
//}