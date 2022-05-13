/*
link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 
TC: O(n)
SC: O(1)
Method: Create a dummy node then push one pointer till n=0 and then start incrementing one pointer from start and first pointer until the first pointer reachers 
null. Then delete the said node.

*/

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *temp1 = start, *temp2 = start;
    while (temp1 && n--)
        temp1 = temp1->next;
    while (temp1->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = temp2->next->next;
    return start->next;
}