/*
link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
TC: O(n)
SC: O(n)
Method: create a vector of 256 size to hash the characters and declare an integer to hold the index of the substring's first character.
traverse the string and hash the elements with index and if found repeting then assign st=a[s[i]] and make sure to hold the maximum 
lenght in a variable and return it in last.
*/

int lengthOfLongestSubstring(string s)
{
    vector<int> a(256, -1);
    int ans = 0, st = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i]] > st)
            st = a[s[i]];
        a[s[i]] = i;
        ans = max(ans, i - st);
    }
    return ans;
}