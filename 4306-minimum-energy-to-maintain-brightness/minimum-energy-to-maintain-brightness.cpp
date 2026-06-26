class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulbs = ( brightness + 2 ) / 3;
        sort ( intervals.begin() , intervals.end());
        long long totalTime = 0;
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        for ( int i = 1 ; i < intervals.size() ; i ++ ) {
            if ( intervals[i][0] <= currEnd ) {
                currEnd = max ( currEnd , intervals[i][1]);
            }
            else {
                totalTime += ( currEnd - currStart + 1 );
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
        }
        totalTime += ( currEnd - currStart + 1 );
        return bulbs * totalTime;
    }
};