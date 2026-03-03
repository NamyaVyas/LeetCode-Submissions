class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);

        // Step 1: Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailingZeros[i] = count;
        }

        int swaps = 0;

        // Step 2: Try to arrange rows
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;

            // Find suitable row
            while (j < n && trailingZeros[j] < required) {
                j++;
            }

            if (j == n)
                return -1;  // Not possible

            // Bring row j to position i
            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};