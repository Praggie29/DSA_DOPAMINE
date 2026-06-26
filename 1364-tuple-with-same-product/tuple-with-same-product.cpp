class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> mpp;
        int totalTuples = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = i + 1 ; j < n ; j ++ ) {
                int prod = nums[i] * nums[j];
                mpp[prod]++;  
            }
        }
        for ( auto &it : mpp ) {
            if ( it.second > 1 ) {
                int count = it.second;
                totalTuples += 4 * count * ( count - 1 );
            }
        }
        return totalTuples;
    }
};