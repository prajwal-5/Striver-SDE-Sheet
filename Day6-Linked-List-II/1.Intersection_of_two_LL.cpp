/*
link: https://leetcode.com/problems/intersection-of-two-linked-lists/ 
TC: O(2n)
SC: O(1)
Method: keep traversing until you find intersecting nodes and update to head again in case some pointer reaches null.
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return NULL;
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != p2)
    {
        p1 = (p1) ? p1->next : headA;
        p2 = (p2) ? p2->next : headB;
    }
    return p1;
}