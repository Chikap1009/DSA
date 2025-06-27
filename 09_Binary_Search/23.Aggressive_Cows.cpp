#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>& stalls, int cows, int gap)
{
    int placed = 1;
    int location = stalls[0];

    for (int i=1 ; i<stalls.size() ; i++)
    {
        if (stalls[i] - location >= gap)
        {
            location = stalls[i];
            placed++;
        }
        if (placed >= cows) return true;
    }

    return false;
}

int getLow(vector<int> &stalls)
{
    int mini = INT_MAX;
    for (int i=1 ; i<stalls.size() ; i++)
    {
        mini = min(mini, stalls[i] - stalls[i-1]);
    }
    return mini;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = getLow(stalls);
    int high = stalls[stalls.size()-1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high)/2;
        if (canWePlace(stalls, k, mid))
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return high;
}

int main()
{
    vector<int> v = {0,3,4,7,9,10};

    cout << aggressiveCows(v, 4) << endl;

    return 0;
}