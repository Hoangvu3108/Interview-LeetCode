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