class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> s;
        for (auto w : wordList)
            s[w] = 0;

        if (s.count(endWord) == 0)
            return 0;

        deque<pair<string, int>> q;
        q.push_back(make_pair(beginWord, 1));
        
        while (!q.empty()) {
            auto wp = q.front();
            q.pop_front();

            for (int i = 0; i < wp.first.size(); ++i) {
                char old = wp.first[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    wp.first[i] = ch;

                    if (wp.first == endWord)
                        return wp.second + 1;
                    
                    if (s.count(wp.first) == 0 || s[wp.first] == 1) {
                        continue;
                    }

                    s[wp.first] = 1;
                    q.push_back(make_pair(wp.first, wp.second + 1));
                }
                wp.first[i] = old;
            }
        }
        
        return 0;
    }
};
