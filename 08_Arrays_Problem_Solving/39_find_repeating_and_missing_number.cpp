#include <bits/stdc++.h>
using namespace std;

vector<int> brute_missrep(vector<int>& arr)
{
    int rep = 0;
    int mis = 0;
    int n = arr.size();

    for (int i=1 ; i<=n ; i++)
    {
        int count = 0;
        for (int j=0 ; j<n ; j++)
        {
            if (arr[j] == i) count++;
        }
        if (count==2) rep = i;
        else if (count==0) mis = i;
        if (rep > 0 && mis > 0) break;
    }
    return {rep, mis};
}

vector<int> better_missrep(vector<int>& arr)
{
    int n = arr.size();
    vector<int> hash(n+1,0);
    for (int i=0 ; i<n ; i++)
    {
        hash[arr[i]]++;
    }
    int rep=0, mis=0;
    for (int i=1; i<hash.size() ; i++)
    {
        if (hash[i]==2) rep = i;
        else if (hash[i]==0) mis = i;
        if (rep>0 && mis >0) break;
    }
    return {rep, mis};
}

vector<int> optimal1_missrep(vector<int>& arr)
{
    int n = arr.size();
    int s1 = 0, s2 = 0;
    int s1n = n*(n+1)/2;
    int s2n = n*(n+1)*(2*n+1)/6;
    for (int i=0 ; i<arr.size() ; i++)
    {
        s1 += arr[i];
        s2 += (arr[i] * arr[i]);
    }
    int diff_of_sum = s1 - s1n;
    int diff_of_square = s2 - s2n;
    int sum = diff_of_square / diff_of_sum;
    int x = (diff_of_sum + sum)/2;
    int y = sum - x;
    return {x, y};
}

vector<int> optimal2_missrep(vector<int>& arr)
{
    int n = arr.size();

    int actual_xor = 0;
    int total_xor = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        actual_xor ^= (i+1);
        total_xor ^= (arr[i]);
    }
    int xr = actual_xor ^ total_xor;
    int bitNo = 0;
    while (1)
    {
        if ((xr & (1<<bitNo)) == 1)
        {
            break;
        }
        bitNo++;
    }
    int one_grp = 0;
    int zero_grp = 0;
    for (int i=0 ; i<n ; i++)
    {
        if ((arr[i] & (1<<bitNo)) == 1)
        {
            one_grp ^= arr[i];
        }
        else
        {
            zero_grp ^= arr[i];
        }

        if (((i+1) & (1<<bitNo)) == 1)
        {
            one_grp ^= (i+1);
        }
        else
        {
            zero_grp ^= (i+1);
        }
    }
    int rep = 0;
    int mis = 0;

    int count = 0;
    for (int i=0 ; i<n ; i++)
    {
        if (arr[i] == zero_grp) count++;
    }

    if (count == 2)
    {
        rep = zero_grp;
        mis = one_grp;
    }
    else
    {
        rep = one_grp;
        mis = zero_grp;
    }

    return {rep, mis};
}

int main()
{
    vector<int> v = {1,2,3,4,3,7,8,9,10,5};

    vector<int> ans = brute_missrep(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = better_missrep(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = optimal1_missrep(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = optimal2_missrep(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}