#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for (int i=0 ; i<nums.size() ; i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maxi = max(count,maxi);
            }
            else
            {
                count = 0;
            }
        }
        return maxi;
    }

int main()
{
    vector<int> v = {1,1,0,1,1,1};

    cout << findMaxConsecutiveOnes(v) << endl;

    return 0;
}