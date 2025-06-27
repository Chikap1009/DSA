#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<double,pair<double,double>>> v;

    for (int i=0 ; i<wt.size() ; i++) {
        v.push_back({(double)val[i]/wt[i],{wt[i],val[i]}});
    }

    sort(v.begin(),v.end());

    double ans = 0.0;
    int currCapacity = 0;
    for (int i=v.size()-1 ; i>=0 ; i--) {
        if (currCapacity + v[i].second.first < capacity) {
            ans += v[i].second.second;
            currCapacity += v[i].second.first;
        }
        else {
            double diff = capacity - currCapacity;
            currCapacity = capacity;
            ans += ((diff / (double)v[i].second.first) * (double)v[i].second.second);
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> val = {60,100,120}, wt = {10,20,30};

    cout << fractionalKnapsack(val, wt, 50) << endl;

    return 0;
}