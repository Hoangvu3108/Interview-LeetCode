**PROBLEM**
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 
```c
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```
```c
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```
```c
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```
**Ý tưởng chính**
- Nếu giá ngày hôm nay price[i] cao hơn giá ngày hôm trước price[i-1] thì có thể kiếm được lợi nhuận bằng cách mua vào cách hôm trước và bán vào ngày hôm nay 
- Cộng tất cả các khoản lợi nhuẩn lại để tính tổng lợi nhuận tối đa có thể thu được.

**Các bước thực hiện**
- Khởi tọa biến maxProfit để lưu tổng lợi nhuận.
- Duyệt qua mảng ```prices```  từ ngày đầu đến ngày cuối cùng 
- Nếu prices[i] > prices[i-1] đến ngày cuối cùng:
    Nếu prices[i] > prices[i-1] cộng thêm ```(prices[i] - price[i-1])``` maxProfit 
- Trả về maxProfit.
```c
#include<stdio.h>
#include<stdlib.h>
 
int maxProfit(int *prices, int pricesSize)
{
    int maxProfit =0;
    for (int i=1; i< pricesSize; i++)
    {
        if (prices[i] > prices[i-1])
        {
            maxProfit += prices[i] - prices[i-1];
        }
    }
    return maxProfit;
}
int main ()
{
    int n;
    printf("Enter the number of days:");
    scanf("%d",&n);

    int *prices =(int*) malloc (n*sizeof(int));
    if (prices == NULL)
    {
        printf("Memory failed");
        return 1;
    }
    printf("Enter the prices of stock for each day:\n");
    for (int i=0; i<n; i++)
    {
        scanf("%d",&prices[i]);
    }
    int profit = maxProfit(prices, n);
    printf("The maximum profit is: %d\n", profit);
    free(prices);
}
```
