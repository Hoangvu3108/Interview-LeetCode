#include<stdio.h>
#include<stdlib.h>

int *intersect(int *num1, int nums1Size, int *num2, int nums2Size, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int)* ((nums1Size < nums2Size) ? nums1Size : nums2Size));
    if (result == NULL)
    {
        printf("Error memory");
        return NULL;
    }
    int index= 0;
    for(int i =0; i< nums1Size;i ++)
    {
        for (int j=0; j < nums2Size; j++)
        {
            if (num1[i]==num2[j])
            {
                result[index++] = num1[i];
                num2[j] = -1; // Mark as used
                break;
            }
        }
    }
    free(num2);
    *returnSize = index;
    return result;
}
int main()
{
    int n1,n2;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    int *num1 = (int *)malloc(sizeof(int) * n1);
    if (num1 == NULL)
    {
        printf("Error memory");
        return 0;
    }
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &num1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    int *num2 = (int *)malloc(sizeof(int) * n2);
    if (num2 == NULL)
    {
        printf("Error memory");
        return 0;
    }
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &num2[i]);
    }
    int returnSize = 0;
    int *result = intersect(num1, n1, num2, n2, &returnSize);
    printf("The intersection is: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(num1);
    free(num2);
}