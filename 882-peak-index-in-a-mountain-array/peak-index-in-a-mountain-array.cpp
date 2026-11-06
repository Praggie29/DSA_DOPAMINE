class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        long long peakIdx ;
        long long low = 0 ;
        long long high = n - 1;
        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                peakIdx = mid;
                break;
            } 
            else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return peakIdx;
    }
};