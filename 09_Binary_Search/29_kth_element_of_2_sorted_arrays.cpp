#include <bits/stdc++.h>    
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int m = b.size();
    
    if (n>m) return kthElement(b, a, k);
    
    int low = max(0, k-m);
    int high = min(n, k);
    
    while (low <= high)
    {
        int mid1 = (low + high)/2;
        int mid2 = k - mid1;
        
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        
        if (mid1 - 1 >= 0)
        {
            l1 = a[mid1-1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = b[mid2-1];
        }
        if (mid1 < n)
        {
            r1 = a[mid1];
        }
        if (mid2 < m)
        {
            r2 = b[mid2];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 <= r2 && l2 > r1)
        {
            low = mid1 + 1;
        }
        else
        {
            high = mid1 - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1,3,4,7,10,12};
    vector<int> v2 = {2,3,6,15};

    cout << kthElement(v1, v2, 7) << endl;

    return 0;
}