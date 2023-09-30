class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;
        stack<int> order; // To store topological order

        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto t = q.front();
            order.push(t); // Push into stack for topological order
            q.pop();

            for (auto x : adj[t]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        // Check if there is a cycle (not all courses can be taken)
        if (order.size() != numCourses) {
            return {}; // Return an empty vector if there is a cycle
        }

        // Populate 'ans' vector with topological order
        while (!order.empty()) {
            ans.push_back(order.top());
            order.pop();
        }

        return ans;
    }
};