/*
link: https://leetcode.com/problems/find-the-duplicate-number/
TC: O(n)
SC: O(1)
Method: Tortoise method of linked list. assign one slow pointer and one fast pointer and let fast pointer move with twice the speed of 
slow resulting a collision then reassign fast to first and then move both of them together and return where they meet.
*/

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}