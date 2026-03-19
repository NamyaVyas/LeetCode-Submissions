class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # diff[i][j] = prefix sum of X(+1), Y(-1), .(0)
        # xcnt[i][j] = prefix count of X
        diff = [[0] * (n + 1) for _ in range(m + 1)]
        xcnt = [[0] * (n + 1) for _ in range(m + 1)]
        
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                cell = grid[i-1][j-1]
                val  = 1 if cell == 'X' else (-1 if cell == 'Y' else 0)
                xval = 1 if cell == 'X' else 0
                
                diff[i][j] = (diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1] + val)
                xcnt[i][j] = (xcnt[i-1][j] + xcnt[i][j-1] - xcnt[i-1][j-1] + xval)
                
                if diff[i][j] == 0 and xcnt[i][j] > 0:
                    ans += 1
        
        return ans