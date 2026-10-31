class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        map <int,int> mpp;
        int i = 0 , j = 0;
        while ( j < n ) {
           mpp[nums[j]]++;
           if ( j - i + 1 == k ) {
             auto it = mpp.rbegin();
             ans.push_back(it->first);
              mpp[nums[i]]--;
             if ( mpp[nums[i]] == 0 ) mpp.erase(nums[i]);
             i++;
           }
           j++;
        }
        return ans;
    }
};