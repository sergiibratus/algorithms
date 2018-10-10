class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_map<string, int> m;
        for (const auto& s : A)
            m[s] = -1;
        
        int current = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (m[A[i]] == -1) {
                ++current;
                m[A[i]] = current;
            }
            
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int index = q.front();
                q.pop();
                    
                for (int j = 0; j < A.size(); ++j) {
                    if (m[A[j]] != -1 || !check(A[index], A[j]))
                        continue;
                        
                    m[A[j]] = m[A[index]];
                    q.push(j);
                }
            }
        }
        
        return current;
    }
private:
    bool check(const std::string& left, const std::string& right) {
        int count = 0;
        for (int i = 0; i < left.size() && count <= 2; ++i)
            if (left[i] != right[i])
                ++count;
        return (count == 2);
    }
};
