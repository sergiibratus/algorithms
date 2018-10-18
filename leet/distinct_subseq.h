class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty())
            return 0;
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == t[i]) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                        continue;
                    }
                    if (i == 0) {
                        dp[i][j] = dp[i][j - 1] + 1;
                        continue;
                    }
                    
                    if (j == 0)
                        continue;
                    
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                    
                } else {
                    dp[i][j] = j > 0 ? dp[i][j - 1] : 0;
                }
            }
        }

        return dp[t.size() - 1][s.size() - 1];
    }
};

