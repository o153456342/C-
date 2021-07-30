//#include "test.h"
//
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//int min(int a, int b)
//{
//    return a < b ? a : b;
//}
//
//int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes) {
//    int** res = (int**)malloc(sizeof(int*) * 2000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
//    int idx = 0;
//    for (int i = 0, j = 0; i < ASize && j < BSize;) {
//        //区间不相交
//        int x1 = A[i][0], y1 = A[i][1], x2 = B[j][0], y2 = B[j][1];
//        if (y1 < x2) {
//            i++;
//        }
//        else if (y2 < x1) {
//            j++;
//        }
//        else {
//            //必有交集
//            int max_x = max(x1, x2);
//            int min_y = min(y1, y2);
//            res[idx] = (int*)malloc(sizeof(int) * 2);
//            res[idx][0] = max_x;
//            res[idx++][1] = min_y;
//            if (y1 == y2) {
//                i++;
//                j++;
//            }
//            else if (y1 < y2) {
//                i++;
//            }
//            else {
//                j++;
//            }
//        }
//    }
//    for (int i = 0; i < idx; i++) {
//        (*returnColumnSizes)[i] = 2;
//    }
//    *returnSize = idx;
//    return res;
//}
//
//int main() {
//
//    return 0;
//}