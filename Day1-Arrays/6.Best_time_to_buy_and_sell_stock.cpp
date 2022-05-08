/*
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
TC: O(n)
SC: O(1)
Method: Maintain the ans=0 with the maximum profit. Keep updating the minimum value yet discovered and calculate the profit subsequently.
*/

int maxProfit(vector<int> &prices)
{
    int ans = 0, minprice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minprice = min(prices[i], minprice);
        ans = max(ans, prices[i] - minprice);
    }
    return ans;
}