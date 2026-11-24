class Solution {
private:
    bool canDistribute(int maxPerStore, int n, const vector<int>& quantities) {
        long long storesNeeded = 0;
        for (int q : quantities) {
            storesNeeded += (q + maxPerStore - 1LL) / maxPerStore;
            if (storesNeeded > n) {
                return false;
            }
        }
        return storesNeeded <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxiEle = *max_element(quantities.begin(), quantities.end());
        int low = 1;
        int high = maxiEle;
        int ans = maxiEle;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(mid, n, quantities)) {
                ans = mid;          
                high = mid - 1;
            } else {
                low = mid + 1;      
            }
        }

        return ans;
    }
};