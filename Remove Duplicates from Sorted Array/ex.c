#include<stdio.h>
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0) return 0;
    int i=0; 
    for (int j =0 ;j <numsSize; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
int main()
{
    int nums[] = {1,1,2,3,4,5,5,6,6,6,7,7,8,9,10,10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int newSize = removeDuplicates(nums, numsSize);
    printf("New size: %d\n", newSize);
    // Print the modified array
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}