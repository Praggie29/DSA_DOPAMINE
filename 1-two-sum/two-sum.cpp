class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int second=target-nums[i];
            if(mpp.find(second)!=mpp.end()){
                ans.push_back(mpp[second]);
                ans.push_back(i);
                break;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};