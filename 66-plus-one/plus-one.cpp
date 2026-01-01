class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for ( int i = digits.size() - 1; i >= 0; i--){

            if (digits[i] < 9){
                digits[i]+=1;
                return digits;
            }
            digits[i] = 0;
        }
        // in the case loop finishes means all digits were 9
        digits.insert (digits.begin(), 1); // add 1 infront of the zeroes
        return digits;
    }
};