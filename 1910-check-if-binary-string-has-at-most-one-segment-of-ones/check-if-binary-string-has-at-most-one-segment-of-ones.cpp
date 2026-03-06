class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZeroAfterOne = false;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0' && i > 0 && s[i-1] == '1')
                seenZeroAfterOne = true;

            if(seenZeroAfterOne && s[i] == '1')
                return false;
        }

        return true;
    }
};