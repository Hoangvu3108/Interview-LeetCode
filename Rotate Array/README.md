**Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.**

 
```c
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```
```c
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
``` 
**Ý tưởng chính**
- Tính toán vị trí mới :
  -  Khi xoay phải k lần, phần tử tại vị trí i sẽ được chuyển đến vị trí ```(i+k) % numsSize``` 
  -  Sử dụng công thức này để tính toán vị trí mới cho từng phần tử.
- Sử dụng mảng tạm thời ```temp()```
    - Tạo một mảng temp để lưu trữ các phần tử đã được xoay.
    - Sao cho phép các phần tử từ mảng tạm thời trở lại mảng gốc.

**Các bước thực hiện**
- Sử dụng cấp phát động để tạo mảng ```nums``` và mảng ```temp```.
- Tính toán vị trí mới
- Duyệt qua các phần tử của mảng ```nums```.
- Sử dụng công thức ```(i+k) % numsSize``` để xác định vị trí mới của phần tử trong mảng ```temp```.
- Sao chép lại vào mảng gốc: Sau khi tính toán xong, sao cép các phần tử từ mảng temp trởi lại mảng ```nums```.
```c
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
    printf("The rotated array is:\n");
    for (int i=0 ;i<n ;i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
```