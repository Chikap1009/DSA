#include <bits/stdc++.h>
using namespace std;

int brute_missingNumber(vector<int> &arr)
{
    for (int i=1 ; i<=arr.size()+1 ; i++)
    {
        bool found = false;
        for (int j=0 ; j<arr.size() ; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            return i;
        }
    }
}

int better_missingNumber(vector<int> &arr)
{
    vector<int> found(arr.size()+2,0);
    for (int i=0 ; i<arr.size() ; i++)
    {
        found[arr[i]]++;
    }
    for (int i=1 ; i<found.size() ; i++)
    {
        if (found[i] == 0)
        {
            return i;
        }
    }
}

int optimal1_missingNumber(vector<int> &arr)
{
    int sum = ((arr.size()+1) * (arr.size()+2))/2;

    for (int i=0 ; i<arr.size() ; i++)
    {
        sum -= arr[i];
    }

    return sum;
}

int optimal2_missingNumber(vector<int> &arr)
{
    int xor1 = 0;
    int xor2 = 0;

    for (int i=0 ; i<arr.size() ; i++)
    {
        xor1 = xor1 ^ (arr[i]);
        xor2 = xor2 ^ (i+1);
    }
    xor2 = xor2 ^ (arr.size()+1);

    return xor1^xor2;
}

int main()
{
    vector<int> v = {1,5,3,2};

    cout << brute_missingNumber(v) << endl;
    cout << better_missingNumber(v) << endl;
    cout << optimal1_missingNumber(v) << endl;
    cout << optimal2_missingNumber(v) << endl;


    return 0;
}