#include <stdlib.h>
#include <stdio.h>

int trap(int* height, int heightSize)
{
    if (heightSize <= 2)
        return 0;
    int* maxright = (int*)malloc(sizeof(int) * heightSize);
    int* maxleft = (int*)malloc(sizeof(int) * heightSize);

    maxleft[0] = height[0];
    for (int i = 1; i < heightSize; i++)
    {
        maxleft[i] = fmax(height[i], maxleft[i - 1]);
    }

    maxright[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--)
    {
        maxright[i] = fmax(height[i], maxright[i + 1]);
    }

    int sum = 0;
    for (int i = 0; i < heightSize; i++)
    {
        if (fmin(maxleft[i], maxright[i]) - height[i] > 0)
            sum += fmin(maxleft[i], maxright[i]) - height[i];
    }
    return sum;
}

int main()
{
    int arr[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int sum = trap(arr,12);
    printf("%d\n", sum);
    return 0;
}