class Solution {
public:
    vector<int>findNSE(vector<int>&nums , int n ) { // Next Smaller Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = n - 1 ; i >= 0 ; i -- ) {
           while( !st.empty() && nums[st.top()] >= nums[i]) st.pop();
           res[i] = st.empty() ? n : st.top();
           st.push(i);
        }
        return res;
    }
    vector<int>findPSE(vector<int>&nums , int n ) { //Previous Smaller Element
        vector<int>res(n);
        stack<int>st;
        for ( int i = 0 ; i < n ; i ++ ) {
           while( !st.empty() && nums[st.top()] > nums[i]) st.pop();
           res[i] = st.empty() ? -1 : st.top();
           st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxRectangleArea = INT_MIN;
        vector<int>PSE = findPSE(heights,n);
        vector<int>NSE = findNSE(heights,n);
        for ( int i = 0 ; i < n ; i ++ ) {
            int area = heights[i] * ( NSE[i] - PSE[i] - 1);
            maxRectangleArea = max ( maxRectangleArea , area );
        }
        return maxRectangleArea;
    }
};