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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto traverse = head->next;
        while(n > 0) {
            if(traverse == nullptr) return head->next;
            traverse = traverse->next;
            n--;
        }
        auto rem = head;
        while(traverse) {
            rem = rem->next;
            traverse = traverse->next;
        }
        rem->next = rem->next->next;
        return head;
    }
};