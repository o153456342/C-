//typedef struct {
//    int** sums;
//    int sumsSize;
//} NumMatrix;
//
//NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
//    NumMatrix* ret = malloc(sizeof(NumMatrix));
//    ret->sums = malloc(sizeof(int*) * (matrixSize + 1));
//    ret->sumsSize = matrixSize + 1;
//    int n = matrixSize ? matrixColSize[0] : 0;
//    for (int i = 0; i <= matrixSize; i++) {
//        ret->sums[i] = malloc(sizeof(int) * (n + 1));
//        memset(ret->sums[i], 0, sizeof(int) * (n + 1));
//    }
//    for (int i = 0; i < matrixSize; i++) {
//        for (int j = 0; j < matrixColSize[i]; j++) {
//            ret->sums[i + 1][j + 1] = ret->sums[i][j + 1] + ret->sums[i + 1][j] - ret->sums[i][j] + matrix[i][j];
//        }
//    }
//    return ret;
//}
//
//int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
//    return obj->sums[row2 + 1][col2 + 1] - obj->sums[row1][col2 + 1] - obj->sums[row2 + 1][col1] + obj->sums[row1][col1];
//}
//
//void numMatrixFree(NumMatrix* obj) {
//    for (int i = 0; i < obj->sumsSize; i++) {
//        free(obj->sums[i]);
//    }
//    free(obj->sums);
//}
