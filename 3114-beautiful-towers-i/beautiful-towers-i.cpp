class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long currSum = heights[i];
            int last_height = heights[i];
            for (int j = i - 1; j >= 0; j--) {
                last_height = min(heights[j], last_height);
                currSum += last_height;
            }
            last_height = heights[i]; 
            for (int j = i + 1; j < n; j++) {
                last_height = min(heights[j], last_height);
                currSum += last_height;
            }
            sum = max(sum, currSum);
        }

        return sum;
    }
};