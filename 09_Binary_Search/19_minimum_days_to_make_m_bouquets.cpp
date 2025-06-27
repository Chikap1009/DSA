#include <bits/stdc++.h>
using namespace std;

vector<int> minMaxElement(vector<int>& bloomDay)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (auto x : bloomDay)
    {
        maxi = max(maxi, x);
        mini = min(mini, x);
    }
    return {mini, maxi};
}

bool checkDone(vector<int>& bloomDay, int m, int k, long long dayNo)
{
    int total = 0;
    int count = 0;
    for (long long i=0 ; i<bloomDay.size() ; i++)
    {
        if (bloomDay[i] <= dayNo)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if (count == k)
        {
            total++;
            count = 0;
        }
    }
    if (total >= m) return true;

    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long long)m*k > (long long)bloomDay.size()) return -1;

    vector<int> temp = minMaxElement(bloomDay);
    int low = temp[0];
    int high = temp[1];
    long long ans = INT_MAX;

    while (low <= high)
    {
        long long mid = (low + high)/2;

        if (checkDone(bloomDay, m, k, mid) == 1)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> bloomDay = {1,10,2,10,3};

    cout << minDays(bloomDay, 3, 1) << endl;

    return 0;
}