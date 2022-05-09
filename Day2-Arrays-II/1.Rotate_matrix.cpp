/*
link: https://leetcode.com/problems/rotate-image/
TC: O(n^2)
SC: O(1)
Method 01: Transpose the matrix and the reverse the rows.
Method 02: Swap the elements of the matrix in a circular fashion leading to the result.
*/

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        for (int k = i; k < n - i - 1; k++)
        {
            swap(matrix[i][k], matrix[k][n - i - 1]);
            swap(matrix[i][k], matrix[n - i - 1][n - k - 1]);
            swap(matrix[i][k], matrix[n - k - 1][i]);
        }
    }
}