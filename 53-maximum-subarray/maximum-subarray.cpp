class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSubArray = INT_MIN;
        int sum = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            sum += nums[i];
            maxSubArray = max ( maxSubArray , sum );
            if ( sum < 0 ) {
                sum = 0;
            }
        }
        return maxSubArray;
    }
};