#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int xor_ele = 0;

        for (int i=0 ; i<nums.size() ; i++)
        {
            xor_ele ^= nums[i];
        }

        return xor_ele;
    }

int main()
{
    vector<int> v = {4,1,2,1,2};

    cout << singleNumber(v) << endl;

    return 0;
}