class Solution:
    def canPartitionGrid(self, grid: list[list[int]]) -> bool:
        total = sum(sum(row) for row in grid)
        
        if total % 2 != 0:
            return False
        
        half = total // 2
        
        # Check horizontal cuts
        prefix = 0
        for i in range(len(grid) - 1):       # can't cut after last row
            prefix += sum(grid[i])
            if prefix == half:
                return True
        
        # Check vertical cuts
        prefix = 0
        for j in range(len(grid[0]) - 1):    # can't cut after last col
            prefix += sum(grid[i][j] for i in range(len(grid)))
            if prefix == half:
                return True
        
        return False