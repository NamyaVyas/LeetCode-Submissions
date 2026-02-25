class Solution {
public:
    
    // Function to count number of 1 bits
    int countOnes(int n) {
        return __builtin_popcount(n);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            
            int countA = countOnes(a);
            int countB = countOnes(b);
            
            // First compare by number of 1 bits
            if (countA == countB)
                return a < b;     // If equal, compare normally
            
            return countA < countB;
        });
        
        return arr;
    }
};