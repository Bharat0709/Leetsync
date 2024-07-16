class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2));

        // Iterate over each possible 3x3 subgrid
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int max_val = 0;
                
                // Find the maximum value in the current 3x3 subgrid
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        max_val = max(max_val, grid[i + k][j + l]);
                    }
                }
                
                // Store the maximum value in the result grid
                result[i][j] = max_val;
            }
        }

        return result;
    }
};
