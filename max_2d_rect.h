class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        vector<vector<uint64_t>> v(matrix.size(), vector<uint64_t>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                v[i][j] = matrix[i][j] == '1' ? 1 : 0;

        int result = hist(v[0]); 

        for (int i = 1; i < v.size(); i++) 
        { 
            for (int j = 0; j < v[0].size(); j++) 
                if (v[i][j])
                    v[i][j] += v[i - 1][j]; 

            result = max(result, hist(v[i])); 
        } 

        return result;
    }
private:
    int hist(const vector<uint64_t>& row) 
    { 
        stack<int> s; 
        int result = 0;

        int i = 0; 
        while (i < row.size()) 
        { 
            if (s.empty() || row[s.top()] <= row[i]) {
                s.push(i++); 
                continue;
            }

            int top_val = row[s.top()]; 
            s.pop(); 
            int area = top_val * i; 

            if (!s.empty()) 
                area = top_val * (i - s.top() - 1 ); 

            result = max(area, result); 
        } 

        while (!s.empty()) 
        { 
            int top_val = row[s.top()]; 
            s.pop(); 

            int area = top_val * i; 
            if (!s.empty()) 
                area = top_val * (i - s.top() - 1 ); 

            result = max(area, result); 
        } 

        return result;
    } 
};
