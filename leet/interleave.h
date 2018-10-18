class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        map<char, int> m;
        for (auto ch : s1)
            m[ch]++;
        for (auto ch : s2)
            m[ch]++;
        for (auto ch : s3) {
            if (m.count(ch) < 1)
                return false;
            m[ch]--;
        }
        for (auto p : m)
            if (p.second != 0)
                return false;

        vector<bool> dp(s2.size() + 1, false);
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.size()];
    }
};
