#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> graph(n);
    for (auto it : flights) {
        graph[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>> q;
    vector<int> prices (n, 1e9);

    q.push({0,{0,src}});
    prices[src] = 0;

    while(!q.empty()) {
        int stops = q.front().first;
        int price = q.front().second.first;
        int node = q.front().second.second;
        q.pop();

        if (stops > k) continue;

        for (auto it : graph[node]) {
            int adjNode = it.first;
            int cost = it.second;

            if (price + cost < prices[adjNode] && stops <= k) {
                prices[adjNode] = price + cost;
                q.push({stops+1,{prices[adjNode], adjNode}});
            }
        }
    }

    if (prices[dst] >= 1e9) return -1;
    return prices[dst]; 
}

int main() {
    int n = 5;
    vector<vector<int>> flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    int src = 0;
    int dst = 2;
    int k = 2;

    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "The cheapest price is: " << result << endl; // Output: 7

    return 0;
}