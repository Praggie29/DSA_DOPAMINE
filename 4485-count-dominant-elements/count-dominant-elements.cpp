class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int dominantEles = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int count = 0;

            if (i - 1 >= 0) {
                sum += nums[i - 1];
                count++;
            }
            if (i + 1 < n) {
                sum += nums[i + 1];
                count++;
            }

            if (count == 0 || nums[i] * count >= sum) {
                dominantEles++;
            }
        }

        return dominantEles;
    }
};