class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> heights;
        vector<pair<int, int>> result;
        
        int cur = 0;
        while (cur < buildings.size() || !heights.empty()) {
            int cur_x = -1;
            
            if (heights.empty() || cur < buildings.size() && heights.top().second >= buildings[cur][0]) {
                cur_x = buildings[cur][0];
                while (cur < buildings.size() && buildings[cur][0] == cur_x) {
                    heights.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            else {
                cur_x = heights.top().second;
                while (!heights.empty() && heights.top().second <= cur_x)
                    heights.pop();
            }
            int cur_h = heights.empty() ? 0 : heights.top().first;
            if (result.empty() || result.back().second != cur_h)
                result.push_back(make_pair(cur_x, cur_h));
        }
        
        return result;
    }
};