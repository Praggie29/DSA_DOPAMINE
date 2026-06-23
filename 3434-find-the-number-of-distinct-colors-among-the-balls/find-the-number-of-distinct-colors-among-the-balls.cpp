class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        
        unordered_map<int, int> ball_to_color;
        unordered_map<int, int> color_count;
        
        for (int i = 0; i < n; ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            
            if (ball_to_color.count(ball)) {
                int old_color = ball_to_color[ball];
                color_count[old_color]--;
                
                if (color_count[old_color] == 0) {
                    color_count.erase(old_color);
                }
            }
            
            ball_to_color[ball] = color;
            color_count[color]++;
            
            ans[i] = color_count.size();
        }
        
        return ans;
    }
};