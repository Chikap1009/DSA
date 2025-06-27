#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
    vector<vector<int>> graph(26);
    vector<bool> alphabets(26);

    for (int i=0 ; i<words.size()-1 ; i++) {
        string s1 = words[i];
        string s2 = words[i+1];
        bool diff = false;
        
        for (int j=0 ; j<min(s1.size(),s2.size()) ; j++) {
            if (s1[j] != s2[j]) {
                graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                diff = true;
                break;
            }
        }

        if (!diff && s1.size() > s2.size()) return ""; 

        for (int j=0 ; j<words[i].size() ; j++) {
            alphabets[words[i][j] - 'a'] = true;
        }
    }

    for (int j=0 ; j<words[words.size()-1].size() ; j++) {
        alphabets[words[words.size()-1][j] - 'a'] = true;
    }

    queue<int> q;

    vector<int> indegree(26,0);
    for (int i=0 ; i<26 ; i++) {
        for (auto it : graph[i]) {
            indegree[it]++;
        }
    }

    for (int i=0 ; i<26 ; i++) {
        if (alphabets[i] && indegree[i] == 0) {
            q.push(i);
        }
    }

    string ans = "";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(char(node + 'a'));

        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    if (ans.size() == accumulate(alphabets.begin(),alphabets.end(),0)) return ans;
    return "";
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string result = alienOrder(words);
    cout << result << endl; // Output: "wertf"
    return 0;
}