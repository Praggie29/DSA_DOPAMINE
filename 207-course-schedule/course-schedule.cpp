class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        int n = prerequisites.size();
        vector<int>degree( numCourses , 0 );
        for ( auto &it : prerequisites ) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            degree[a]++;
        }

        queue<int>q;
        int cnt = 0;
        for ( int i = 0 ; i < numCourses ; i ++ ) {
            if ( degree[i] == 0 ) {
                q.push(i);
                cnt ++;
            }
        }
        
        while ( !q.empty() ) {
            int qS = q.size();
            int a = q.front();
            q.pop();
            for ( auto &it : adj[a] ) {
                degree[it]--;
                if ( degree[it] == 0 ) {
                    q.push(it);
                    cnt++;
                }
            }
        }
        return cnt == numCourses;
    }
};