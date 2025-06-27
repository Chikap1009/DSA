#include <bits/stdc++.h>
using namespace std;

void brute_merge(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> arr3;
    int n = arr1.size();
    int m = arr2.size();
    int left = 0;
    int right = 0;
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3.push_back(arr1[left]);
            left++;
        }
        else
        {
            arr3.push_back(arr2[right]);
            right++;
        }
    }

    while (left < n)
    {
        arr3.push_back(arr1[left]);
        left++;
    }

    while (right < m)
    {
        arr3.push_back(arr2[right]);
        right++;
    }

    for (int i=0 ; i<n+m ; i++)
    {
        if (i<n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}

void optimal1_merge(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int left = n-1;
    int right = 0;

    while (left>=0 && right<m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void optimal2_merge(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int gap = (n+m)/2 + (n+m)%2;
    while (gap>0)
    {
        int left = 0;
        int right = left+gap;
        while (right < (n+m))
        {
            if (left<n && right>=n)
            {
                if (arr1[left] > arr2[right-n])
                {
                    swap(arr1[left], arr2[right-n]);
                }
            }
            else if (right<n)
            {
                if (arr1[left] > arr1[right])
                {
                    swap(arr1[left], arr1[right]);
                }
            }
            else if (left>=n)
            {
                if (arr2[left-n] > arr2[right-n])
                {
                   swap(arr2[left-n], arr2[right-n]);
                }
            }
            left++;
            right++;
        }
        if (gap==1) break;
        gap = gap/2 + gap%2;
    }
}

int main()
{
    vector<int> a1 = {1,3,5,7};
    vector<int> a2 = {0,2,4,6,8,9};
    brute_merge(a1, a2);
    for (auto x : a1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : a2)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    a1 = {1,3,5,7};
    a2 = {0,2,4,6,8,9};
    optimal1_merge(a1, a2);
    for (auto x : a1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : a2)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    a1 = {1,3,5,7};
    a2 = {0,2,4,6,8,9};
    optimal2_merge(a1, a2);
    for (auto x : a1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : a2)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    return 0;
}