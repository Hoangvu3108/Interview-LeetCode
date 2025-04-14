Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 
```c
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```
```c
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```


 
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
**Ý tưởng chính:**
- Duyệt qua từng phần tử của mảng num1
  -  Với mỗi phần tử trong num1 kiểm tra xem nó có xuất hiện trong num2 không 
  -  Nếu có, thêm phần tử đó vào mảng ```result``` và đánh dấu phần tử trong num2 đã sử dụng (bằng cách gắn giá trị bằng -1).
- Sử dụng mảng kết quả động:
  - Kích thước của mảng kết quả result được cấp phát động với kích thước tối đa là kích thước của mảng nhỏ trong hai mảng (num1 hoặc num2)
- Trả về kết quả:
  - Trả về mảng kết quả và số lượng phần tử trong mảng kết quả(returnSize).
```c
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
```
**Giải thích**
**Hàm interect**
- Cấp phát bộ nhớ cho mảng kết quả:
  - result được cấp phát động với kích thước tối đa là kích thước của mảng nhỏ trong hai mảng num1 và num2
- Duyệt qua từng phần từ của num1:
  - Với mỗi phần tử num1[i], duyệt qua toàn bộ num2.
  - Nếu tìm thấy num1[i] == num2[j], thì thêm phần tử num[i] vào mảng result và đánh dấu là num2[j] đã được sử dụng bằng cách gán giá trị -1.
- Trả về kết quả:
  - returnSize lưu số lượng phần tử trong mảng kết quả.
  - Trả về con trỏ result. 
**Hàm main**
- Nhập dữ liệu :
  - Nhập kích thước và phần tử của hai mảng num1 và num2.
- Gọi hàm intersect
- In ra kết quả 
- Giải phóng bộ nhớ của num1, num2 và result.