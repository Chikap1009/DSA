#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_mergeSubIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i=0 ; i<intervals.size() ; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (ans.size() > 0 && end <= ans.back()[1])
        {
            continue;
        }
        for (int j=i+1 ; j<intervals.size() ; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> optimal_mergeSubIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i=0 ; i<intervals.size() ; i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = brute_mergeSubIntervals(v);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    ans = optimal_mergeSubIntervals(v);
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