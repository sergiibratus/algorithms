class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> visited(quiet.size(), 0);
        vector<int> result(quiet.size());
        for (int i = 0; i < result.size(); ++i)
            result[i] = i;

        vector<vector<int>> tree(quiet.size());
        for (int i = 0; i < richer.size(); ++i)
            tree[richer[i][0]].push_back(richer[i][1]);

        for (int i = 0; i < tree.size(); ++i) {
            dfs(tree, i, quiet, result, visited);
        }

        return result;
    }
private:
    void dfs(const vector<vector<int>>& tree, int index, const vector<int>& quiet, vector<int>& result, vector<int>& visited) {
        for (int i = 0; i < tree[index].size(); ++i) {
            if (quiet[result[index]] < quiet[result[tree[index][i]]])
                result[tree[index][i]] = result[index];
            else {
                if (visited[tree[index][i]] == 1)
                    continue;
            }

            dfs(tree, tree[index][i], quiet, result, visited);
            visited[tree[index][i]] = 1;
        }
    }
};
