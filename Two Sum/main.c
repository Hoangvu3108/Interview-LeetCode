#include<stdio.h>
#include<stdlib.h>

int *twoSum(int * nums, int numsSize, int target, int *returnSize)
{
     for (int i = 0; i< numsSize;i ++)
        {
            for (int j=i+1; j < numsSize; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    int *result = (int *)malloc(sizeof(int) * 2);
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;    
                }
            }
        }
    *returnSize = 0;
    return NULL;
}

int main ()
{
    int nums[] = {2, 7,11,15,13};
    int target= 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL)
    {
        printf("Indices: [ %d, %d ]\n", result[0], result[1]);
        free(result);
    }
    else
    {
        printf("No two sum solution found.\n");
    }
}