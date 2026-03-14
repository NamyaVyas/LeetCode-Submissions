class Solution {
public:
    void solve(int n, int k, string &curr, vector<string> &res) {
        if(res.size() >= k) return;
        
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }
        
        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                solve(n, k, curr, res);
                curr.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> res;
        string curr = "";
        
        solve(n, k, curr, res);
        
        if(res.size() < k) return "";
        return res[k-1];
    }
};