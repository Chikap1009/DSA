#include <bits/stdc++.h>
using namespace std;

void formCombos(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> combination = {}, int index = 0)
{
    if (target == 0)
    {
        ans.push_back(combination);
        return;
    }

    for (int i=index ; i<candidates.size() ; i++)
    {
        if (candidates[i] > target) break;

        if (i>index && candidates[i]==candidates[i-1]) continue;

        combination.push_back(candidates[i]);
        formCombos(candidates, target-candidates[i], ans, combination, i+1);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    formCombos(candidates,target, ans);
    return ans;
}

int main()
{
    vector<int> v = {10,1,2,7,6,1,5};

    vector<vector<int>> ans = combinationSum2(v, 8);

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