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