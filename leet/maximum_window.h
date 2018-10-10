class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
        
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i);
                continue;
            }
            
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int index = s.top();
                s.pop();
            
                result = max(result,heights[index] * (s.empty() ? i :  i - s.top() - 1));
            }
            
            s.push(i);
        }
        
        while (!s.empty()) {
            
            int index = s.top();
            s.pop();
            
            int cur = heights[index] * (s.empty() ? heights.size() :  heights.size() - s.top() - 1);
            result = max(result,cur);
        }
        
        return result; 
    }
};
