#include <bits/stdc++.h>
using namespace std;

void returnCombinations(vector<int>& candidates, int target, vector<vector<int>>& ans, int index = 0, vector<int> combination = {})
{
    if (index == candidates.size())
    {
        if (target == 0) ans.push_back(combination);
        return;
    }

    if (candidates[index] <= target)
    {
        combination.push_back(candidates[index]);
        returnCombinations(candidates, target-candidates[index], ans, index, combination);
        combination.pop_back();
    }

    returnCombinations(candidates, target, ans, index+1, combination);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    returnCombinations(candidates, target, ans);
    return ans;
}

int main()
{
    vector<int> v = {2,3,6,7};

    vector<vector<int>> ans = combinationSum(v, 7);

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