class Solution {
public:
    void f ( int idx , int sum , vector<int>&candidates , int target , vector<int>store  , vector<vector<int>>&ans ) {
       if ( sum > target || idx >= candidates.size()) return;
       if ( sum == target ) {
          ans.push_back(store);
          return;
       }
       store.push_back(candidates[idx]);
       f ( idx , sum + candidates[idx] , candidates , target , store , ans );
       store.pop_back();
       f ( idx + 1 , sum , candidates , target , store , ans );
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>store;
        f ( 0 , 0 , candidates , target , store , ans );
        return ans;
    }
};