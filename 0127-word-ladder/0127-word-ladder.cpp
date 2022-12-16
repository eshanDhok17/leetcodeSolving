class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string &str : wordList) st.insert(str);
        wordList.clear();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()) {
            auto word = q.front().first;
            auto steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0; i<word.size(); ++i) {
                char original = word[i];
                for(char x = 'a'; x <= 'z'; ++x) {
                    word[i] = x;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};