class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # Create a 2D list to represent the tower.
        # The number of rows required is query_row + 1 (as indices start from 0)
        tower = [[0] * (i + 1) for i in range(query_row + 1)]
        
        # Pour the champagne into the topmost glass.
        tower[0][0] = poured
        
        # Process each row to simulate the champagne pouring and overflow.
        for row in range(query_row):
            for col in range(row + 1):
                # If the current glass has more than 1 unit of champagne, spill it.
                excess = (tower[row][col] - 1) / 2.0
                if excess > 0:
                    tower[row + 1][col] += excess
                    tower[row + 1][col + 1] += excess
        
        # The result is the amount of champagne in the desired glass.
        return min(1, tower[query_row][query_glass])  # We cap it at 1 because no glass can hold more than 1 unit.
