class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= s.length() - k; i++) {
            st.insert(s.substr(i, k));
        }
        
        return st.size() == (1 << k);
    }
};