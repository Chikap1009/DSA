#include <bits/stdc++.h>
using namespace std;

int brute_maxProfit(vector<int>& prices) {
        int maxDiff = 0;
        for (int i=0 ; i<prices.size() ; i++)
        {
            for (int j=i+1 ; j<prices.size() ; j++)
            {
                int diff = prices[j] - prices[i];
                maxDiff = max(maxDiff, diff);
            }
        }
        return maxDiff;
    }

int optimal_maxProfit(vector<int>& prices) {
    int maxPro = 0;
    int mini = prices[0];
    for (int i=0 ; i<prices.size() ; i++)
    {
        int pro = prices[i] - mini;
        maxPro = max(maxPro, pro);
        if (prices[i] < mini) mini = prices[i];
    }
    return maxPro;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};

    cout << brute_maxProfit(v) << endl;
    cout << optimal_maxProfit(v) << endl;

    return 0;
}