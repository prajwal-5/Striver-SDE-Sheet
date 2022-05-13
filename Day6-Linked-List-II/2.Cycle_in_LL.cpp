/*
link: https://leetcode.com/problems/linked-list-cycle/
TC: O(2n)
SC: O(1)
Method: Keep iterating until fast or fast->next reaches null and if slow and fast intersects then break and return true.
*/

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}