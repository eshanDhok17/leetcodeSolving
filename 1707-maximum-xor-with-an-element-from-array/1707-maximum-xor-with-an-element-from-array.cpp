class Node {
    public:
    Node* links[2];
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
        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(node->contains(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    /* 
        1. Create Offline queries for the question's Condition of quering value less than or equal to queries[i][1], 
           Sort them according to queries[i][1] to always get according to condition.
        2. Create a TRIE and insert nums[ind] where ind < n and nums[ind] <= queries[i][1].
        3. When TRIE Insertion is complete, we have successfully inserted all array elements which obey the condition for question,
           now we just need to run getMaxXOR within the trie to get max XOR of queries[i][0] and such a number which is <= queries[i][0].
        4. if we dont have any ind which is <= queries[i][1], we return -1 as asked by the question.
        5. Finally we store answer which we got in ans[qInd], where qInd is the original index for each element queries,
           just to make the queries online again or in order again.
           qInd = offlineQueries[i].second.second;
    */
        vector<pair<int, pair<int, int>>> offlineQueries;
        int n = queries.size();
        for(int i=0; i<n; i++) {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        sort(nums.begin(), nums.end());
        int ind = 0;
        vector<int> ans(n, 0);
        Trie t;
        for(int i=0; i<n; i++) {
            int mi = offlineQueries[i].first,
                xi = offlineQueries[i].second.first,
                qInd = offlineQueries[i].second.second;
            while(ind < nums.size() and nums[ind] <= mi) {
                t.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = t.getMaxXOR(xi);
        }
        return ans;
    }
};