/*
link: https://leetcode.com/problems/sort-colors/
TC: O(n)
SC: O(1)
Method: Dutch National Flag Algorithm => Take 3 pointers low=0, mid=0 and high=n-1 and make sure all elements before low are 0, 
all element between low and mid are 1 and all element after high are 2. Move only mid and swap with low if nums[mid]==0 and 
swap with high if nums[mid]==2.
*/

void sortColors(vector<int> &nums)
{
    int n = nums.size(), low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
            swap(nums[mid++], nums[low++]);
        else if (nums[mid] == 1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}