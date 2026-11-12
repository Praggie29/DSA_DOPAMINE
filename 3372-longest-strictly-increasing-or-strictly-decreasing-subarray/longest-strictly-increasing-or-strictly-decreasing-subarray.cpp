class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increasing = 1;
        int decreasing = 1;
        int cnt = 1;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( nums[i] > nums[ i - 1 ]) {
                cnt ++;
                increasing = max ( increasing , cnt );
            }
            else {
                cnt = 1;
            }
        }
        cnt = 1;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( nums[i] < nums[ i - 1 ]) {
                cnt ++;
                decreasing = max ( decreasing , cnt );
            }
            else {
                cnt = 1;
            }
        }
        return max ( increasing , decreasing );
    }
};