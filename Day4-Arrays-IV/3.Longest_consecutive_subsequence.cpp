/*
link: https://leetcode.com/problems/longest-consecutive-sequence/ 
TC: O(3n)
SC: O(n)
Method: hash all the elements present and then traverse one by one and check for the consecutive elements for which no previous 
element is there and store the maximum.
*/

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> m;
    int ans = 0;
    for (int i : nums)
        m[i]++;
    for (int i : nums)
    {
        if (!m[i - 1])
        {
            int cs = 0, cu = i;
            for (int x = i; m[x]; x++)
            {
                if (x == cu)
                {
                    cs++;
                    cu++;
                }
                else
                    break;
            }
            ans = max(ans, cs);
        }
    }
    return ans;
}