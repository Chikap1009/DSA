#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, componentSize;

public:
    DisjointSet(int n) {
        componentSize.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;

        parent[node] = findParent(parent[node]); // Path compression
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return; // They are already in the same set

        if (componentSize[parentU] < componentSize[parentV]) {
            parent[parentU] = parentV; // Attach smaller rank tree under larger rank tree
            componentSize[parentV] += componentSize[parentU]; // Update the size of the new root
        } else {
            parent[parentV] = parentU; // Arbitrarily choose one as the new root
            componentSize[parentU] += componentSize[parentV]; // Increase the rank of the new root
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();

    unordered_map<string,int> mp;
    DisjointSet ds(n);

    for (int i=0 ; i<n ; i++) {
        for (int j=1 ; j<accounts[i].size() ; j++) {
            string mail = accounts[i][j];
            if (mp.find(mail) == mp.end()) {
                mp[mail] = i;
            }
            else ds.unionBySize(mp[mail], i);
        }
    }

    vector<vector<string>> mergedAccounts(n);
    for (auto it : mp) {
        string mail = it.first;
        int node = ds.findParent(it.second);

        mergedAccounts[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i=0 ; i<n ; i++) {
        if (mergedAccounts[i].size() == 0) continue;

        sort(mergedAccounts[i].begin(),mergedAccounts[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto it : mergedAccounts[i]) {
            temp.push_back(it);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main() {
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
                                       {"John","johnsmith@mail.com","john00@mail.com"},
                                       {"Mary","mary@mail.com"},
                                       {"John","johnnybravo@mail.com"}};

    vector<vector<string>> mergedAccounts = accountsMerge(accounts);
    for (auto account : mergedAccounts) {
        for (auto email : account) {
            cout << email << " ";
        }
        cout << endl;
    }

    return 0;
}