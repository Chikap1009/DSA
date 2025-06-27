#include <bits/stdc++.h>
using namespace std;

vector<int> brute_two_sum(vector<int> arr, int target)
{
    for (int i=0 ; i<arr.size() ; i++)
    {
        for (int j=i+1 ; j<arr.size() ; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
}

vector<int> better_two_sum(vector<int> arr, int target)
{
    unordered_map<int,int> mp;
    for (int i=0 ; i<arr.size() ; i++)
    {
        int diff = target - arr[i];
        if (mp.find(diff) != mp.end())
        {
            return {mp[diff], i};
        }
        mp[arr[i]] = i;
    }
}

string optimal_two_sum(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size()-1;
    
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target) return "YES";
        else if (sum < target) left++;
        else right--;
    }

    return "NO";
}

int main()
{
    vector<int> v = {2,7,11,15};

    for (auto x : brute_two_sum(v, 9))
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : better_two_sum(v, 9))
    {
        cout << x << " ";
    }
    cout << endl;

    cout << optimal_two_sum(v, 9) << endl;

    return 0;
}