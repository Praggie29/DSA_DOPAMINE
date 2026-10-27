class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0 , ones = 0 , twos = 0;
        for ( int num : nums ) {
            if ( num == 0 ) zeros ++;
            else if ( num == 1 ) ones++;
            else twos++;
        }
        int i = 0;
        while ( i < n ) {
            while(zeros--) {
                nums[i++] = 0;
            }
            while(ones--) {
                nums[i++] = 1;
            }
            while(twos--) {
                nums[i++] = 2;
            }
        }
    }
};