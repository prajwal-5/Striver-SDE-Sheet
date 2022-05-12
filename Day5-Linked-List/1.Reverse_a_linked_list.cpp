/*
link: https://leetcode.com/problems/reverse-linked-list/
TC: O(n)
SC: O(1)
Method: Create a pointer pointing to null and then start traversing the linked list then create a temporary pointer pointing to next
element then point head->next to the new pointer and make the new pointer head and make head to temporary pointer.
*/

ListNode *reverseList(ListNode *head)
{
    if (!head)
        return head;
    ListNode *h = NULL;
    while (head)
    {
        ListNode *temp = head->next;
        head->next = h;
        h = head;
        head = temp;
    }
    return h;
}