class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for ( int i = n - 1 ; i > 0 ; i -- ) {
            if ( nums[i] > nums[i-1] ) {
                idx = i - 1;
                break;
            }
        }
        int nextGreaterIdx = -1 ;
        if ( idx == -1 ) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for ( int j = n - 1 ; j >= idx + 1 ; j -- ) {
             if ( nums[j] > nums[idx] ) {
                nextGreaterIdx = j;
                break;
             }
        }
        swap ( nums[idx] , nums[nextGreaterIdx] );
        reverse ( nums.begin() + idx + 1 , nums.end() );
    }
};