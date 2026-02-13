class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0
        
        # -----------------------
        # Case 1: single char
        # -----------------------
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            ans = max(ans, j - i)
            i = j
        
        # -----------------------
        # Case 2: two characters
        # -----------------------
        def solve_two(c1, c2):
            mp = {0: -1}
            diff = 0
            res = 0
            
            for i in range(n):
                if s[i] == c1:
                    diff += 1
                elif s[i] == c2:
                    diff -= 1
                else:
                    diff = 0
                    mp = {0: i}
                    continue
                
                if diff in mp:
                    res = max(res, i - mp[diff])
                else:
                    mp[diff] = i
            return res
        
        ans = max(ans, solve_two('a', 'b'))
        ans = max(ans, solve_two('a', 'c'))
        ans = max(ans, solve_two('b', 'c'))
        
        # -----------------------
        # Case 3: all three equal
        # -----------------------
        a = b = c = 0
        mp = {(0, 0): -1}
        
        for i, ch in enumerate(s):
            if ch == 'a':
                a += 1
            elif ch == 'b':
                b += 1
            else:
                c += 1
            
            key = (a - b, a - c)
            
            if key in mp:
                ans = max(ans, i - mp[key])
            else:
                mp[key] = i
        
        return ans
