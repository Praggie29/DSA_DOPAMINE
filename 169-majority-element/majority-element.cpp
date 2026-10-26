class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0], count = 1;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( count == 0 ) {
                num = nums[i];
                count = 1;
            }
            else if ( nums[i] == num ) count ++;
            else if ( nums[i] != num ) {
                count--;
            }
        }
        return num;
    }
};