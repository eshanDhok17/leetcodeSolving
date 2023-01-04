class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for(int &i : tasks) {
            mp[i]++;
        }
        int ans = 0;
        while(mp.size() > 0) {
            for(auto &it : mp) {
                int a = it.first, b = it.second;
                // cout << it.first << " " << it.second << endl;
                if((b % 2 == 3 or b % 2 == 0 or b - 2 >= 0) and b % 3 != 0) {
                    mp.erase(a);
                    b = b-2;
                    mp.insert({a, b});
                    if(b == 0) {
                        mp.erase(a);
                        // cout << a << " udadiya" << endl;
                    }
                    ans += 1;
                }
                else if(b % 3 == 2 or b % 3 == 0) {
                    mp.erase(a);
                    b = b-3;
                    mp.insert({a,b});
                    if(b == 0) {
                        mp.erase(a);
                        // cout << a << " udadiya" << endl;
                    }
                    ans += 1;
                }
                else return -1;
                // cout << ans << " iteration over" << endl;
            }
        }
        return ans;
    }
};