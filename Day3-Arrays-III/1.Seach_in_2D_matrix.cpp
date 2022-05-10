/*
link: https://leetcode.com/problems/search-a-2d-matrix/
TC: O(log(m*n))
SC: O(1)
Method: Since the matrix is rowwise sorted then consider it as one whole array and modify binary search for it.
*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size(), lo = 0, hi = (n * m) - 1;
    while (lo <= hi)
    {
        int mid = (lo + (hi - lo) / 2);
        if (matrix[mid / m][mid % m] == target)
            return true;
        if (matrix[mid / m][mid % m] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}