You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 
```c
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```
```c
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```
```c
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```
**Ý tưởng chính**
- Duyệt từ cuối mảng về đầu
  - Bắt đầu từ chữ số cuối cùng (chữ số hàng đơn vị)
  - Cộng thêm một vào chữ số đó.
  - Nếu chữ số đó là số 9 thì khi đặt chữ số đó về không và tiếp tục cộng chữ số tiếp theo 
- Xử lý trường hợp đặc biệt:
  - Nếu tát cả các chữ số đều là 9 thì sau khi cộng thêm 1 thì mảng có thêm chữ số một ở đầu nữa và các chữ số còn lại là 0 (Ví dụ : 9, 9 , 9 +1 = 1,0,0,0) 

```c
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
```