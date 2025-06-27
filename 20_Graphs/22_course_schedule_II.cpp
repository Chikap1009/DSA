#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto it : prerequisites) {
        graph[it[1]].push_back(it[0]);
    }

    vector<int> indegree(numCourses,0);

    for (int i=0 ; i<numCourses ; i++) {
        for (auto it : graph[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i=0 ; i<numCourses ; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    if (ans.size() == numCourses) return ans;
    return {};
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> order = findOrder(numCourses, prerequisites);
    
    if (order.empty()) {
        cout << "It is not possible to finish all courses." << endl;
    } else {
        cout << "One possible order to finish all courses is: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    return 0;
}