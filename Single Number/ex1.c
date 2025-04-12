#include<stdio.h>
#include<stdlib.h>
int singleNumber (int *nums, int numsSize)
{
    int result =0;
    for (int i= 0; i< numsSize ;i ++)
    {
        result ^= nums[i];
    }
    return result;
}
int main ()
{
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int *nums = (int *)malloc (sizeof(int)*n);
    if(nums== NULL)
    {
        printf("Memory failed\n");
        return 1;
    }
    printf("Enter the elements \n");
    for (int i=0;i<n ;i++)
    {
        scanf("%d", &nums[i]);
    }
    int result = singleNumber(nums, n);
    printf(" The result is %d\n", result);
    free(nums);


}