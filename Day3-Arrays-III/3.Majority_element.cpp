/*
link: https://leetcode.com/problems/majority-element/
TC: O(n)
SC: O(1)
Method: Moore Voting algorithm:=> take 2 variables cnt and e and assign to 0. Then traverse linearly and check for cnt==0 then assign 
e=i, then check for i==e and increment cnt if yes else decrement cnt. Lastly, return e.
This algorithm works because fo the fact that the majority element will be present more than n/2 times.

*/

int majorityElement(vector<int> &nums)
{
    int e = 0, cnt = 0;
    for (int i : nums)
    {
        if (cnt == 0)
            e = i;
        if (i == e)
            cnt++;
        else
            cnt--;
    }
    return e;
}