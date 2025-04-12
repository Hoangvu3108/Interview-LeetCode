#include<stdio.h>
#include<stdlib.h>

void singleNumber (int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    printf("The single number is: %d\n", result);  
}
int main ()
{
    int n;
    printf("Enter the number of elements in the array:\n");

    scanf("%d",&n);
    int *nums =(int *) malloc (sizeof(int)*n);
    if (nums == NULL)
    {
        printf("Memory failed\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (int i=0 ;i<n ;i++)
    {
        scanf("%d",&nums[i]);
    }
    singleNumber(nums, n);
    free(nums);
}