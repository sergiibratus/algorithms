class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) return false;

            int i = matrix.size() - 1;
            int j = 0;

            while (true) {
                if ( i < 0 || j == matrix[0].size()) break;
                if (matrix[i][j]  == target)
                    return true;

                if (matrix[i][j] < target)
                    j++;
                else if (matrix[i][j] > target)
                    i--;
            }

            return false;
        }
};
