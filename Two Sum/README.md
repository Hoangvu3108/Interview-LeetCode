Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:
```c
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```
Example 2:
```c
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
Example 3:
```c
Input: nums = [3,3], target = 6
Output: [0,1]
 ```

Constraints:
```c
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 ```

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

```c
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
```