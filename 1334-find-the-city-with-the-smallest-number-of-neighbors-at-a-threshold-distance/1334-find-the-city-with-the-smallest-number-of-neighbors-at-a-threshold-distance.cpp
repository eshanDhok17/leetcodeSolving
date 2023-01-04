class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int &dt) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(auto &it : edges) {
            int i = it[0], j = it[1], wt = it[2];
            dist[i][j] = wt;
            dist[j][i] = wt;
        }
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] == INT_MAX or dist[k][j] == INT_MAX) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cntCity = n;
        int cityNo = -1;
        for(int city=0; city<n; city++) {
            int cnt=0;
            for(int adjCities=0; adjCities<n; adjCities++) {
                if(dist[city][adjCities] <= dt) {
                    cnt++;
                }
            }
            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNo = max(cityNo, city);
            }
        }
        return cityNo;
    }
};