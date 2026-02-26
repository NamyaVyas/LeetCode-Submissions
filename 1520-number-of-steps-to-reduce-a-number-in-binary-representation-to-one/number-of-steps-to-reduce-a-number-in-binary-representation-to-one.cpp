class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Start from the last bit (rightmost)
        for (int i = s.length() - 1; i > 0; i--) {
            
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0) {
                // Even → divide by 2
                steps += 1;
            } else {
                // Odd → add 1 (carry happens), then divide
                steps += 2;
                carry = 1;
            }
        }

        // If carry remains at MSB
        return steps + carry;
    }
};