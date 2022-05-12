/*
link: https://www.interviewbit.com/problems/subarray-with-given-xor/
TC: O(n)
SC: O(n)
Method: Declare an unordered_map for storing prexor of elements till that point. then check if the current xor till that element == B.
Also check if current xor with the given xor is present in the map and if so increment the answer with the frequency. Lastly hash the 
curren xor or update the frquency.
*/

int Solution::solve(vector<int> &A, int B)
{
    int ans = 0, x = 0, n = A.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        x = x ^ A[i];
        if (x == B)
            ans++;
        if (m.find(x ^ B) != m.end())
            ans += m[x ^ B];
        m[x] += 1;
    }
    return ans;
}
