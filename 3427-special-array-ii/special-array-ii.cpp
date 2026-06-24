class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool>ans;
        vector<int>prefSum(n,0);
        for ( int i = 1 ; i < n ; i ++ ) {
            prefSum[i] = prefSum[i - 1];
            if ( nums[i] % 2 == nums[i - 1] % 2 ) {
                prefSum[i]++;
            }
        }
        for ( const auto &it : queries ) {
            int a = it[0];
            int b = it[1];
            if ( ( prefSum[b] - prefSum[a] ) == 0 ) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};