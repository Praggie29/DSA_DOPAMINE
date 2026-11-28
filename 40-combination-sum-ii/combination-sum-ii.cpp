class Solution {
public:
    void f ( int idx , int sum , vector<int>&candidates , int target , vector<int>store  , vector<vector<int>>&ans ) {
        if ( sum == target ) {
          ans.push_back(store);
          return;
       }
       if ( sum > target || idx >= candidates.size()) return;
       store.push_back(candidates[idx]);
       f ( idx + 1 , sum + candidates[idx] , candidates , target , store , ans );
       store.pop_back();
       while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++;
        }
       f ( idx + 1 , sum , candidates , target , store , ans );
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>store;
        f ( 0 , 0 , candidates , target , store , ans );
        return ans;
    }
};