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
        int i = 0;
        for (; i < left.size(); ++i)
            if (left[i] != right[i])
                break;
        
        if (i >= (left.size() - 1))
            return false;
        
        int j = left.size() - 1;
        for (; j > i; --j)
            if (left[j] != right[j])
                break;
        
        if (j <= i || left[i] != right[j] || left[j] != right[i])
            return false;

        string comp = right;
        comp[j] = left[j];
        comp[i] = left[i];
        
        for (i = 0; i < left.size(); ++i)
            if (left[i] != comp[i])
                return false;
        
        return true;
    }
};

