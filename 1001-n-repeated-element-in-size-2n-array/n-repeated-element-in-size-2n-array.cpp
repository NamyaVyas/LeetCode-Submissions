class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());

        int temp = 0;
        int x = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                temp++;
                x = nums[i];

                if (temp == n - 1) {
                    return x;
                }
            } else {
                // reseting
                temp = 0;
            }
        }

        return -1; 
    }
};
