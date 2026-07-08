class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degreeCount; 
        for (const auto& edge : edges) {
            degreeCount[edge[0]]++;
            degreeCount[edge[1]]++;
        }
        
        int targetSize = edges.size();
        
        for (const auto& it : degreeCount) {
            if (it.second == targetSize) {
                return it.first;
            }
        }
        
        return -1;
    }
};