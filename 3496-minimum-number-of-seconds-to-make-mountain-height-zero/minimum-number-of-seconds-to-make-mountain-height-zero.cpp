class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e16;

        auto can = [&](long long t) {
            long long reduced = 0;

            for (int wt : workerTimes) {
                long long x = sqrt((2.0 * t) / wt + 0.25) - 0.5;
                reduced += x;

                if (reduced >= mountainHeight)
                    return true;
            }

            return reduced >= mountainHeight;
        };

        while (left < right) {
            long long mid = (left + right) / 2;

            if (can(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};