class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum1 = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            sum1 += nums[i];
            maxSum = max ( maxSum , sum1 );
            if ( sum1 < 0 ) sum1 = 0;
        }

        int minSum = INT_MAX;
        int sum2 = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            sum2 += nums[i];
            minSum = min ( minSum , sum2 );
            if ( sum2 > 0 ) sum2 = 0;
        }
        return max ( maxSum , abs(minSum) );
    }
};