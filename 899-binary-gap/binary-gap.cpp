class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;
        int maxGap = 0;
        int currentPos = 0;

        while (n > 0) {
            if (n & 1) {   // if last bit is 1
                if (lastPos != -1) {
                    maxGap = max(maxGap, currentPos - lastPos);
                }
                lastPos = currentPos;
            }
            n >>= 1;       // shift right
            currentPos++;
        }

        return maxGap;
    }
};