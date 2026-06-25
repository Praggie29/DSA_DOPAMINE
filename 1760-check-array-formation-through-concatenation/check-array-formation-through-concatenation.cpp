class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = pieces.size();
        int m = arr.size();
        unordered_map <int,int> mpp;
        for ( int i = 0 ; i < n ; i ++ ) {
            mpp[pieces[i][0]] = i;
        }
        int i = 0;
        while ( i < m ) {
            if ( mpp.find(arr[i]) == mpp.end() ) {
                return false;
            }
            int idx = mpp[arr[i]];
            const vector<int>& it = pieces[idx];
            for ( int val : it ) {
                if ( i >= m || arr[i] != val ) {
                   return false;
                }
                 i++;
            }
           
        }
        return true;
    }
};