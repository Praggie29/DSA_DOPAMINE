class Solution {
public:
    int m = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,vector<int>> mpp;
        for ( int i = 0 ; i < n ; i ++ ) {
            mpp[nums[i]].push_back(i);
        }
        long long goodTriplets = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
           int target = nums[i] * 2;
           if ( mpp.find(target) == mpp.end()) continue;
           const vector<int>& indices = mpp[target];
           auto it1 = lower_bound(indices.begin(), indices.end(), i);
           long long left_count = distance(indices.begin(), it1);
           auto it2 = upper_bound(indices.begin(), indices.end(), i);
           long long right_count = distance(it2, indices.end());
           goodTriplets = (goodTriplets + (left_count * right_count)) % m;
        }
        return goodTriplets;
    }
};