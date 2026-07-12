class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        unordered_map <int,int> mpp;
        vector<int>store = arr;
        sort(store.begin(),store.end());
        int rank = 1;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( mpp.find(store[i]) == mpp.end()) {
                mpp[store[i]] = rank;
                rank++;
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) {
              ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};