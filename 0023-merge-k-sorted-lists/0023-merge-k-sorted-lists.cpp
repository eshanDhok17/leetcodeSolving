class Solution {
public:
    typedef pair<int, ListNode*> pair;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        priority_queue<pair, vector<pair>, greater<pair>> pq;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode dummy(0), *head = &dummy;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            auto node = top.second;
            head->next = node;
            head=head->next;
            if(node->next)
                pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};