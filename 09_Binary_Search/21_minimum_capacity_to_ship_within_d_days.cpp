#include <bits/stdc++.h>
using namespace std;

bool checkPossible(vector<int>& weights, int days, int capacity)
{
    int tempSum = 0;
    int daysTaken = 0;
    for (int i=0 ; i<weights.size() ; i++)
    {
        tempSum += weights[i];
        if (tempSum > capacity)
        {
            daysTaken++;

            tempSum = weights[i];
        }
        if (tempSum == capacity)
        {
            daysTaken++;
            tempSum = 0;
        }
    }
    if (tempSum != 0) daysTaken++;
    
    if (daysTaken <= days) return true;
    return false;
}

vector<int> sumMaxElement(vector<int>& weights)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (auto x : weights)
    {
        sum += x;
        maxi = max(maxi, x);
    }

    return {maxi, sum};
}
int shipWithinDays(vector<int>& weights, int days) {
    vector<int> v = sumMaxElement(weights);
    int low = v[0]; // max
    int high = v[1]; // sum
    
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (checkPossible(weights, days, mid))
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    cout << shipWithinDays(v, 5) << endl;

    return 0;
}