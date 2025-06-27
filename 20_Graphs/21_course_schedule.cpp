#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    if (count == numCourses) return true;
    return false;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    
    if (canFinish(numCourses, prerequisites)) {
        cout << "It is possible to finish all courses." << endl;
    } else {
        cout << "It is not possible to finish all courses." << endl;
    }
    
    return 0;
}