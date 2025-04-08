- Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

- Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:
```c
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```
If all assertions pass, then your solution will be accepted.

 
```c
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```
```c
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
- Hide Hint #1  
    - In this problem, the key point to focus on is the input array being sorted. As far as duplicate elements are concerned, what is their positioning in the array when the given array is sorted? Look at the image below for the answer. If we know the position of one of the elements, do we also know the positioning of all the duplicate elements?

- Hide Hint #2  
    - We need to modify the array in-place and the size of the final array would potentially be smaller than the size of the input array. So, we ought to use a two-pointer approach here. One, that would keep track of the current element in the original array and another one for just the unique elements.
   Hide Hint #3  
- Essentially, once an element is encountered, you simply need to bypass its duplicates
```c
#include<stdio.h>
int removeDuplicates(int *nums, int numsSize)
{    // if the rray is empty so array don't have element to analyze and return 0
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
```
**Result**
```c
New size: 10
1 2 3 4 5 6 7 8 9 10
````
**Giải thích**
- Khai báo hàm với removeDuplicates với các tham số 
- nums: con trỏ tới mảng số nguyên
- NumsSize: số phần tử trong mảng
