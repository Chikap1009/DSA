#include <bits/stdc++.h>
using namespace std;

void totalSum(vector<int>& arr, vector<int>& ans, int index = 0, vector<int> subset = {})
{
    if (index == arr.size())
    {
        ans.push_back(accumulate(subset.begin(),subset.end(),0));
        return;
    }
    
    subset.push_back(arr[index]);
    totalSum(arr, ans, index+1, subset);
    subset.pop_back();
    totalSum(arr, ans, index+1, subset);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> ans;
    totalSum(arr, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};

    vector<int> ans = subsetSums(arr);
    // sort(ans.begin(),ans.end());

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}