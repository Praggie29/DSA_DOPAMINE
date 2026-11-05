class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin() , arr2.end());
        int n = arr1.size() , m = arr2.size();
        int cnt = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
           int lower = arr1[i] - d;
           int upper = arr1[i] + d;
           int low = 0 , high = m - 1;
           bool found = false;
           
           while ( low <= high ) {
            int mid = low - ( low - high ) / 2;
             if ( arr2[mid] >= lower && arr2[mid]<=upper) {
                found = true;
                break;
             } 
             else if ( arr2[mid] < lower ) {
                low = mid + 1;
             }
             else {
                high = mid - 1;
             }
           }
           if (!found) cnt++;
        }
        return cnt;
    }
};