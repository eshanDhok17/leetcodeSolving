class Solution {
public:
    ListNode* rev(ListNode* first, ListNode* last) {
        ListNode* cur = first, *prev = nullptr, *next = nullptr;
        while(cur != last) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cur = head;
        for(int i=0; i<k; i++) {
            if(!cur) return head;
            else cur = cur->next;
        }
        auto newHead = rev(head, cur);
        head->next = reverseKGroup(cur, k);
        return newHead;
    }
};