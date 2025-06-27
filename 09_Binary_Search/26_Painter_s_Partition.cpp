#include <bits/stdc++.h>
using namespace std;

bool checkPaint(vector<int> &boards, int k, int limit)
{
    int painter = 0;
    int sum = 0;
    for (int i=0 ; i<boards.size() ; i++)
    {
        sum += boards[i];
        if (sum > limit)
        {
            painter++;
            sum = boards[i];
        }
        else if (sum == limit)
        {
            painter++;
            sum = 0;
        }
    }
    if (sum != 0) painter++;
    if (painter > k) return false;
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) 
{
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while (low <= high)
    {
        int mid = (low + high)/2;
        if (checkPaint(boards,k,mid))
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
    vector<int> v = {2, 1, 5, 6, 2, 3};

    cout << findLargestMinDistance(v, 2) << endl;

    return 0;
}