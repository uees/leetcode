#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target);

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int *result;
    result = twoSum(nums, sizeof(nums), target);
    if (nums[result[0]] + nums[result[1]] == target)
    {
        printf("pass\n");
    }
    else
    {
        printf("error\n");
    }
    free(result);
    return 0;
}

int *twoSum(int *nums, int numsSize, int target)
{
    int i;
    int j;
    int diff;
    int *result;

    result = (int *)malloc(sizeof(int) * 2);

    for (i = 0; i < numsSize - 1; i++)
    {
        diff = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == diff)
            {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
}
