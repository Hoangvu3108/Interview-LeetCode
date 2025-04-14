#include<stdio.h>
#include<stdlib.h>

int *plusOne(int *digits, int digitSize, int * returnSize)
{
    for (int i = digitSize -1 ; i>= 0 ;i--)
    {
        if (digits[i]< 9){
            digits[i]++;
            *returnSize = digitSize;
            return digits;
        }
        digits[i] = 0;
    }
    int *result= (int *)malloc (sizeof(int) *(digitSize + 1));
    result[0] = 1;
    for (int  i=1; i< digitSize +1;i++){
        result[i] = 0;
    }
    *returnSize = digitSize + 1;
    return result;
}
int main ()
{
    int n ;
    printf("Enter the size of the array:");
    scanf("%d",&n);

    int *digits= (int *)malloc(sizeof(int)*n);
    if (digits == NULL)
    {
        printf("Error memory");
    }
    printf("Enter the elements of the array:");
    for (int i=0 ; i< n ;i++){
        scanf("%d", &digits[i]);
    }
    int returnSize =0;
    int *result = plusOne(digits, n, &returnSize);

    printf("The result is: ");
    for (int i= 0; i< returnSize ; i++)
    {
        printf("%d",result[i]);
    }
    if (result != digits)
    {
        free(result);
    }
    free(digits);
    return 0;
}