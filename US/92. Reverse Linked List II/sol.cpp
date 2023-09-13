/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* node = head;
        ListNode* nextnode = head->next;
        int i = 1;
        ListNode* left_end = nullptr;
        ListNode* old_head = head;
        ListNode* right_start = nullptr;
        while (nextnode != nullptr){
            if (i+1 == left){
                left_end = node;
                old_head = nextnode;
            }
            if (i == right){
                right_start = nextnode;
                node->next = nullptr;
                break;
            }
            i++;
            node = nextnode;
            nextnode = nextnode->next;
        }
        if (left_end != nullptr)
            left_end->next = nullptr;
        ListNode* reversed_head = reverse(old_head);
        // cout<<reversed_head->val<<endl;
        // cout<<reversed_head->next->val<<endl;
        old_head->next = right_start;
        if (left_end != nullptr){
            left_end->next = reversed_head;
            return head;
        }else{
            return reversed_head;
        }
    }

    ListNode * reverse(ListNode* head){
        ListNode* node = head;
        ListNode* nextnode = head->next;
        node->next = nullptr;
        while (nextnode != nullptr){
            ListNode* tmp = nextnode->next;
            nextnode->next = node;
            node = nextnode;
            nextnode = tmp;
        }
        return node;
    }
};
