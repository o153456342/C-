//#include "test.h"
//
//int cuttingRope(int n)
//{
//    unsigned int res = 1;
//
//    if (n < 4)
//        return n - 1;
//
//    while (n > 4)
//    {
//        res *= 3;
//        res %= 1000000007;
//        n -= 3;
//    }
//    return res * n % 1000000007;
//}
//
//int main()
//{
//    int ret = cuttingRope(15);
//    printf("%d\n", ret);
//    return 0;
//}