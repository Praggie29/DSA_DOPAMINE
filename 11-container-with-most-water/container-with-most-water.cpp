class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = INT_MIN;
        int i = 0 , j = n - 1;
        while ( i < j ) {
            int dis = j - i;
            int mini = min ( height[i] , height[j] );
            maxWater = max ( maxWater , mini * dis );
            if ( height[i] < height[j] ) i++;
            else j--;
        }
        return maxWater;
    }
};