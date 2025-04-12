#include <stdio.h>
#include <stdlib.h>
void rotate (int *nums, int numsSize, int k)
{
    int *temp = (int*)malloc(numsSize*sizeof(int));
    if (temp == NULL)
    {
        printf("Memory Failed");
        return;
    }
    for (int i = 0; i < numsSize; i++)
    {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = temp[i];
    }

}
int main ()
{
    int n,k;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the number of rotations:\n");
    scanf("%d",&k);

    int *nums = (int *)malloc(sizeof(int)*n);

    if(nums== NULL)
    {
        printf("Memory failed");
        return 1;
    }
    printf("Enter the elements of the array:\n");   
    for (int i=0 ;i<n ;i++)
    {
        scanf("%d",&nums[i]);
    }
    rotate(nums, n, k);
    printf("The rotated array is: \n");
    for (int i=0 ;i<n ;i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}