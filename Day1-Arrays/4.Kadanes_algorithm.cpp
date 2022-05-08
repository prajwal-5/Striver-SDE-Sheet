/*
    link: https://leetcode.com/problems/maximum-subarray/ 
    TC: O(n)
    SC: O(1)
    Method: take one variable to hold the maximum possible sum ans and assign it to the first element. Then calculate 
    the contiguous sum until the temp sum gets less than 0. If it gets less than 0 then update it to 0 and if it gives maximum sum 
    in between then reassign ans with sum. This is Kadane's algorithm.
*/

int maxSubArray(vector<int> &nums)
{
    int ans = nums[0], sum = 0;
    for (auto i : nums)
    {
        sum += i;
        if (sum > ans)
            ans = sum;
        if (sum < 0)
            sum = 0;
    }
    return ans;
}