/*
    link: https://leetcode.com/problems/next-permutation/
    TC: O(3n)
    SC: O(1)
    Method: 
        1) traverse from back and get index1 where a[i]<a[i+1]
        2) again traverse from back and get first index2 where ele > arr[index1]
        3) swap(arr[index1], arr[index2])
        4) reverse(arr[index1+1], arr.end)
 */

void nextPermutation(vector<int> &nums)
{
    int first = -1, last = -1, n = nums.size();
    for (int i = n - 1; i > 0; i--)
        if (nums[i] > nums[i - 1])
        {
            first = i - 1;
            break;
        }
    if (first != -1)
    {
        for (int i = n - 1; i > first; i--)
            if (nums[i] > nums[first])
            {
                last = i;
                break;
            }
    }
    else
        first = 0;

    if (first != -1 && last != -1)
    {
        swap(nums[first], nums[last]);
        first = first + 1;
    }
    for (int i = first, j = n - 1; i < j; i++, j--)
        swap(nums[i], nums[j]);
}