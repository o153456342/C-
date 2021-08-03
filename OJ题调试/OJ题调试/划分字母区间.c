//#include "test.h"
//
//int* partitionLabels(char* s, int* returnSize) {
//    int last[26];
//    int length = strlen(s);
//    for (int i = 0; i < length; i++) {
//        last[s[i] - 'a'] = i;
//    }
//    int* partition = malloc(sizeof(int) * length);
//    int start = 0, end = 0;
//    *returnSize = 0;
//    for (int i = 0; i < length; i++) {
//        end = fmax(end, last[s[i] - 'a']);
//        if (i == end) {
//            partition[(*returnSize)++] = end - start + 1;
//            start = end + 1;
//        }
//    }
//    return partition;
//}
//
//int main() {
//    char s[] = "ababcbacadefegdehijhklij";
//    int returnSize = 0;
//    printf("%s", partitionLabels(s, &returnSize));
//    return 0;
//}
