class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;
        int count = 0, start = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') count++;
            else count--;

            if(count == 0) { // found a special substring
                // recursively process the inner part
                string inner = s.substr(start + 1, i - start - 1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // sort in descending lex order
        sort(specials.begin(), specials.end(), greater<string>());

        string res = "";
        for(auto &str : specials) res += str;
        return res;
    }
};