class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        
        dfs(rooms, 0, visited);
        
        for (auto v : visited)
            if (v == 0)
                return false;
        
        return true;
    }
private:
    void dfs(const vector<vector<int>>& rooms, int start, vector<int>& visited) {
        if (visited[start] == 1)
            return;
        
        visited[start] = 1;
        for (auto n : rooms[start])
            dfs(rooms, n, visited);
    }
};
