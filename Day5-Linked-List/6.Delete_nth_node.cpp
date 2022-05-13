/*
link: https://leetcode.com/problems/delete-node-in-a-linked-list/
TC: O(1)
SC: O(1)
Method: Swap the values with the next node and then update the link;
*/
void deleteNode(ListNode *node)
{
    swap(node->val, node->next->val);
    node->next = node->next->next;
}