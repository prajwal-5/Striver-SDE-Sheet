/*
link: https://leetcode.com/problems/merge-intervals/
TC: O(nlogn) + O(n)
SC: O(n)  
Method: sort and traverse the intervals accordingly.
*/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int i = 1;
    while (i < intervals.size())
    {
        if (intervals[i][0] <= intervals[i - 1][1])
        {
            intervals[i][0] = intervals[i - 1][0];
            intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
        }
        else
            ans.push_back(intervals[i - 1]);
        i++;
    }
    ans.push_back(intervals[i - 1]);
    return ans;
}