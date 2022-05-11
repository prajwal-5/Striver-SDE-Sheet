/*
link: https://leetcode.com/problems/4sum/
TC: O(n^3)
SC: O(1)
Method: Sort the array. Run one loop i->n then inside it run another loop from i+1->n then you have fixed your two numbers then go for the remaining
target same as two sum.
*/

vector<vector<int>> fourSum(vector<int> &nums, int ftarget)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int left = j + 1, right = n - 1;
            int target = ftarget - nums[i] - nums[j];
            while (left < right)
            {
                long long fix = nums[right] + nums[left];
                if (fix > target)
                    right--;
                else if (fix < target)
                    left++;
                else
                {
                    vector<int> temp{nums[i], nums[j], nums[left], nums[right]};
                    ans.push_back(temp);
                    while (left < right && nums[left] == temp[2])
                        ++left;
                    while (left < right && nums[right] == temp[3])
                        --right;
                }
            }
            while (j < n - 1 && nums[j] == nums[j + 1])
                j++;
        }
        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}