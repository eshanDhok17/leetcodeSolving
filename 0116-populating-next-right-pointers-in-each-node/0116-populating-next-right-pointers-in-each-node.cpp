/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* &root) {
        if(!root) return nullptr;
        Node* node = root;
        queue<Node*> q({node});
        while(!q.empty()) {
            Node *prev = nullptr;
            int sz = q.size();
            for(int i=sz-1; i>=0; i--) {
                auto p = q.front(); q.pop();
                p->next = prev;
                prev = p;
                if(p->right) q.push(p->right), q.push(p->left);
            }
        }
        return root;
    }
};