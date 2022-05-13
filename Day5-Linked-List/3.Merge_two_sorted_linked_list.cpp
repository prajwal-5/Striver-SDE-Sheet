/*
link: https://leetcode.com/problems/merge-two-sorted-lists/
TC: O(m+n)
SC: O(1)
Method: Make sure list1 always point to the smaller element and keep updating the links.
*/

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->val > list2->val)
        swap(list1, list2);
    ListNode *nh = list1;
    while (list1 && list2)
    {
        ListNode *temp = NULL;
        while (list1 && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    return nh;
}