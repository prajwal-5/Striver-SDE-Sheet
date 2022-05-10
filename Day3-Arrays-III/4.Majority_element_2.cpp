/*
link: https://leetcode.com/problems/majority-element-ii/
TC: O(n + n)
SC: O(1)
Method: Same Boyre Moore algorithm.
*/

vector<int> majorityElement(vector<int> &nums)
{
    int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
    for (int i : nums)
    {
        if (n1 == i)
            c1++;
        else if (n2 == i)
            c2++;
        else if (c1 == 0)
        {
            n1 = i;
            c1++;
        }
        else if (c2 == 0)
        {
            n2 = i;
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = c2 = 0;
    vector<int> ans;
    for (int i : nums)
    {
        if (n1 == i)
            c1++;
        else if (n2 == i)
            c2++;
    }
    if (c1 > floor(nums.size() / 3))
        ans.push_back(n1);
    if (c2 > floor(nums.size() / 3))
        ans.push_back(n2);
    return ans;
}