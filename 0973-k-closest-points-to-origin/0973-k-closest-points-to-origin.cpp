class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto &point : points) {
            int x = point[0], y = point[1];
            pq.push({(pow(x,2) + pow(y, 2)), {x, y}});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            res.push_back({top.second.first, top.second.second});
        }
        return res;
    }
};