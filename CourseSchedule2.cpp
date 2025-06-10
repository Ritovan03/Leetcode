class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);  // in-degree array

        // Build adjacency list and compute in-degrees
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // pre[1] → pre[0]
            indegree[pre[0]]++;
        }

        queue<int> q;
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);  // Course with no prereq
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (topo.size() == numCourses) {
            return topo;
            
        }
        return {}; // Cycle detected → no valid order
    }
};