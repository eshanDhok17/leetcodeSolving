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
        unordered_set<ListNode*> mp;
        while(head && head->next) {
            if(mp.find(head) != mp.end()) {
                return head;
            }
            else {
                mp.insert(head);
            }
            head = head->next;
            /*
                    a --> b --> c --> d --> b
                    
                    a->b 
                    b->c
                    c->d
                    d->b
            */
        }
        return nullptr;
    }
};