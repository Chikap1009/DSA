#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    vector<int> track(250,0);
    int n = s.size();
    for (int i=0 ; i<n ; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            track[s[i]]++;
        }
        else
        {
            track[s[i]]++;
        }
    }

    set<int> st;
    for (int i=0 ; i<250 ; i++)
    {
        if (track[i] != 0)
        {
            st.insert(track[i]);
        }
    }

    string ans = "";

    for (auto x : st)
    {
        for (int i=0 ; i<250 ; i++)
        {
            if (track[i] == x)
            {
                for (int j=0 ; j<x ; j++)
                {
                    ans += (char) (i);
                }
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cout << frequencySort("2a554442f544asfasssffffasss") << endl;

    return 0;
}