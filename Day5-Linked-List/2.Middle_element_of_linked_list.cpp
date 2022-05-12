/*
link: https://leetcode.com/problems/middle-of-the-linked-list/ 
TC: O(n/2)
SC: O(1)
Method: Assign two pointers to head one fast and one slow then while checking for fast and fast->next keep updating slow by 1 and fast 
by 2. By the end slow will have covered half the distance done by the fast pointer resuting to the middle element.
*/

ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }