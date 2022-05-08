/*
    Problem: https://leetcode.com/problems/set-matrix-zeroes/ 
    TC: O(2(MxN))
    SC: O(1)
    Method: Take the first row and column as determiners and if any zero is found put the first row and first col as 0. 
    Subsequently check for the zeros in first column and if found make the variable col_check as false indicating that 0,0 will 
    be a 0. once done then traverse the arrya in reverse and if (matrix[0][j]==0 || matrix[i][0]==0) then make the element 0. 
    Lastly check col_check and accordingly make matrix[0][0] a 0.
*/
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size(), col_check = 1;
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            col_check = 0;
        for (int j = 1; j < col; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col_check == 0)
            matrix[i][0] = 0;
    }
}