/*
link: https://leetcode.com/problems/add-two-numbers/
TC: O(n+m)
SC: O(1)
Method: Maintain a carry varibale and keep creating the new node as sum of the other nodes and update the carry accordingly and store.
*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *dummy = new ListNode;
    ListNode *temp = dummy;
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode *nn = new ListNode(sum % 10);
        temp->next = nn;
        temp = temp->next;
    }
    return dummy->next;
}