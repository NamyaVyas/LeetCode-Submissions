class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int lo = x, hi = x + k - 1;
        while (lo < hi) {
            for (int j = y; j < y + k; ++j) {
                swap(grid[lo][j], grid[hi][j]);
            }
            ++lo;
            --hi;
        }
        return grid;
    }
};