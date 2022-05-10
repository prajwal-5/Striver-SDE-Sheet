/*
link: https://leetcode.com/problems/unique-paths/

DP solution:
TC: O(n*m)
SC: O(n*m)
Method: Recursive DP or Memorization.

Combinatorics solution:
TC: O(n-1) || O(m-1)
SC: O(1)
Method: You always have to take (m-1 +  n-1) right directions to reach, which means m+n-2 paths are there. and out of those choose m-1
or n-1 paths.
*/

// DP solution
int rec(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = rec(i + 1, j, n, m, dp) + rec(i, j + 1, n, m, dp);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return rec(0, 0, n, m, dp);
}

// Combinatorics solution
int uniquePaths(int m, int n)
{
    int N = m + n - 2, r = m - 1;
    double ans = 1;
    for (int i = 1; i <= r; i++)
        ans = ans * (N - r + i) / i;
    return (int)ans;
}