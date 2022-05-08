/*
    link: https://leetcode.com/problems/pascals-triangle/ 
    TC: O(n^2)
    SC: O(n^2)
    Method: Add the upper element and upper left element for the current element.
*/

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});
    if (numRows > 1)
        ans.push_back({1, 1});
    for (int i = 2; i < numRows; i++)
    {
        vector<int> newRow(i + 1, 1);
        for (int j = 1; j < i; j++)
            newRow[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        ans.push_back(newRow);
    }
    return ans;
}