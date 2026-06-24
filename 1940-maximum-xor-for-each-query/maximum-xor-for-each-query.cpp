class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxi = ( 1 << maximumBit) - 1;
        vector <int> prefixXor(n);
        prefixXor[0] = nums[0];
        for ( int i = 1 ; i < n ; i ++ ) {
            prefixXor[i] = prefixXor[i-1] ^ nums[i];
        }
        vector<int>ans(n);
        for ( int i = 0 ; i < n ; i ++ ) {
            int a = prefixXor[ n - i - 1 ];
            ans[i] = a ^ maxi;
        }
        return ans;
    }
};