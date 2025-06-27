#include <bits/stdc++.h>
using namespace std;

void makeCombos(int k, int n, vector<vector<int>>& ans, vector<int> combination = {}, int sum = 0, int num = 1)
{
    if (sum == n && combination.size() == k)
    {
        ans.push_back(combination);
        return;
    }

    for (int i=num ; i<=9 ; i++)
    {
        if (sum + i > n) break;

        combination.push_back(i);
        makeCombos(k,n,ans,combination,sum+i,i+1);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    makeCombos(k,n,ans);
    return ans;
}

int main()
{
    vector<vector<int>> ans = combinationSum3(3,9);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " "; 
        }
        cout << endl;
    }
    
    return 0;
}