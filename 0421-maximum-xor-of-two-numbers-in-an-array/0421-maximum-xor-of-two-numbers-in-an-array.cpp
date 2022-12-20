class Node {
    public:
    Node* links[2]; // for 0 and 1 bit
    bool contains(int bit) {
        return (links[bit] != NULL);
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMaxXOR(int num) {
        Node* node = root;
        int maxi = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(node->contains(!bit)) {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int num : nums) t.insert(num);
        int maxNum = 0;
        for(int num : nums) {
            maxNum = max(maxNum, t.getMaxXOR(num));
        }
        
        return maxNum;
    }
};