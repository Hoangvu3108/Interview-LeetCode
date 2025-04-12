**Given a non-empty array of integers nums, every element appears twice except for one. Find that single one**
**You must implement a solution with a linear runtime complexity and use only constant extra space**

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

**Ý tưởng chính**
Sử dụng phép ```XOR```
Tính chất của XOR a^a = 0 và a^0 = a 
Phép XOR giao hoán và kết hợp a^b^c = c ^b^a 
Khi XOR tất cả các phần tử trong mảng thì các phần tử xuất hiện hai lần sẽ triệt với nhau 
**Các bước thực hiện**
- Khởi tạo biến ```result=0```
- Duyệt qua từng phần phần tử trong mảng 
- Thực hiện phép XOR giữa result và phần tử còn lại 
- Sau khi duyệt xong, result sẽ chứa phần tử xuất hiện một lần 
```c
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
```

Bài toán để in ra tất cả các số xuất hiện một lần trong mảng thì thay vì sử dụng XOR (vì XOR) chỉ tìm được một số duy nhất, thì ta có thể sử dụng hash table
```c
#include <stdio.h>
#include <stdlib.h>

void findSingleNumbers(int *nums, int numsSize) {
    int *count = (int *)calloc(100001, sizeof(int)); // Mảng đếm (giả sử giá trị nằm trong khoảng 0 đến 100000)
    if (count == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Đếm số lần xuất hiện của từng phần tử
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // In ra các số xuất hiện đúng 1 lần
    printf("Single numbers are: ");
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 1) {
            printf("%d ", nums[i]);
        }
    }
    printf("\n");

    // Giải phóng bộ nhớ
    free(count);
}

int main() {
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    int *nums = (int *)malloc(sizeof(int) * n);
    if (nums == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    findSingleNumbers(nums, n);

    free(nums);
    return 0;
}
```
```c
Enter the number of elements in the array:
6
Enter the elements of the array:
1 2 3 4 3 4
```
**Output**
```c
Single numbers are: 1 2
```
**Ý tưởng**
- Sử dụng mảng đếm count 
    - Sử dụng mảng count để đếm số lần xuất hiện của từng phần tử trong mảng ```nums```.
- Duyệt qua mảng 
    Lần đầu: Đếm số lần xuất hiện của từng phần tử 
    Lần thứ hai : Kiểm tra và in ra các phần tử có số lần xuất hiện bằng 1
- Giải phóng bộ nhớ: Sau khi sử dụng xong mảng count và núm, giải phóng bộ nhớ ```free()``