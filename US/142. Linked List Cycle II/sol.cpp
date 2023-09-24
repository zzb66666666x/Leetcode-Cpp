/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr){
                return nullptr;
            }
            fast = fast->next;
            if (fast == nullptr){
                return nullptr;
            }
        }while (fast != slow);
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
