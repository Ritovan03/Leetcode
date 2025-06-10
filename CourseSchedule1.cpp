class Solution {
public:
    bool dfs(vector<int> adj[], int node, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(adj, neighbor, visited, recStack)) return true;
            } else if (recStack[neighbor]) {
                return true;  // Found a cycle
            }
        }

        recStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // Edge: p[1] -> p[0] (prerequisite -> course)
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, recStack)) return false;
            }
        }

        return true; // No cycle found
    }
};