class Solution {
    public:
        int surfaceArea(vector<vector<int>>& grid) {
            int result = 0;

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 0)
                        continue;
                    result += grid[i][j] * 4 + 2;
                    result -= min(grid[i][j], get(grid, i + 1, j));
                    result -= min(grid[i][j], get(grid, i - 1, j));
                    result -= min(grid[i][j], get(grid, i, j + 1));
                    result -= min(grid[i][j], get(grid, i, j - 1));
                }
            }

            return result;
        }
    private:
        int get(const vector<vector<int>>& grid, int i, int j) {
            if (i < 0 || i >= grid.size())
                return 0;

            if (j < 0 || j >= grid[0].size())
                return 0;

            return grid[i][j];
        }
};

