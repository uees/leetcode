#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target);
int *twoSum2(int *nums, int numsSize, int target);
int get_min(int *nums, int numsSize);

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

    result = twoSum2(nums, sizeof(nums), target);
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

int *twoSum2(int *nums, int numsSize, int target)
{
    int min = get_min(nums, numsSize); // 获取数组中的最小值
    int max = target - min;            // 最大差值
    int len = max - min + 1;           // 确定hash长度
    int *table = (int *)malloc(len * sizeof(int));
    int *indice = (int *)malloc(2 * sizeof(int));

    int i = 0;

    for (i = 0; i < len; i++)
    {
        table[i] = -1; // hash初值
    }

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] - min < len)
        {
            if (table[target - nums[i] - min] != -1)
            { //满足相加为target
                indice[0] = table[target - nums[i] - min];
                indice[1] = i;
                return indice;
            }
            table[nums[i] - min] = i;
        }
    }

    free(table);

    return indice;
}

int get_min(int *nums, int numsSize)
{
    int min = INT_MAX;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    return min;
}
